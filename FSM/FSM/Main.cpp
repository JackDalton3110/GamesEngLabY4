#include <stdio.h>
#include "InputHandler.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "State.h"

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 400;
const int SPRITE = 560;

bool init();
bool loadMedia();
void close();

SDL_Surface* loadSurface(std::string location);
SDL_Surface* ScreenSurface = NULL;
SDL_Surface* PNGSurface = NULL;
SDL_Window* window = NULL;

SDL_Rect beginRect;
SDL_Rect endRect;

State current;

bool init()
{
	bool success = true;
	beginRect.x = 100;
	beginRect.y =100;
	beginRect.w = 558;
	beginRect.h = 828;

	endRect.x = 0;
	endRect.y = 0;
	endRect.w = 558;
	endRect.h = 828;
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			int imgFlags = IMG_INIT_PNG;

			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_Image could not load! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}
			else
			{
				ScreenSurface = SDL_GetWindowSurface(window);
			}
		}

	}
	return success;
}

bool loadMedia()
{
	bool success = true;
	PNGSurface = loadSurface("spritesheet.png");
	if (PNGSurface == NULL)
	{
		std::cout << "Failed to load image" << std::endl;
		success = false;
	}
	return success;
}

void close()
{
	SDL_FreeSurface(PNGSurface);
	PNGSurface = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	IMG_Quit();
	SDL_Quit();
}

SDL_Surface* loadSurface(std::string location)
{
	SDL_Surface* optimizedSurface = NULL;

	SDL_Surface* loadedSurface = IMG_Load(location.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", location.c_str(), IMG_GetError());
	}
	else
	{
		optimizedSurface = SDL_ConvertSurface(loadedSurface, ScreenSurface->format, NULL);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", location.c_str(), SDL_GetError());
		}

		SDL_FreeSurface(loadedSurface);
	}
	return optimizedSurface;
}

int main(int argc, char* args[])
{
	InputHandler * handler = new InputHandler();
	//The window we'll be rendering to

	if (!init())
	{
		printf("Failed to initialize \n");
	}
	else
	{
		if (!loadMedia())
		{
			printf("Failed to load media! \n");
		}
		else
		{
			bool quit = false;
			SDL_Event e;
			int count = 0;

			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					handler->handleInput(e);
					
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}
				if (handler->getCurrent() == handler->IDLE)
				{
					endRect.y = 0;
				}
				if (handler->getCurrent() == handler->JUMP)
				{
					
					endRect.y = 345;
				}
				if (handler->getCurrent() == handler->CLIMB)
				{
					endRect.y = 169;
					
				}

				count++;
				endRect.w = 116;
				endRect.h = 134;

				if (count > 500)
				{
					endRect.x = endRect.x + 116;
					count = 0;
				}

				if (endRect.x > 470)
				{
					endRect.x = 0;
				}
				
				//Apply the PNG image
				SDL_BlitSurface(PNGSurface, &endRect, ScreenSurface, &beginRect);

				//Update the surface
				SDL_UpdateWindowSurface(window);
				
				
				
			}
		}
	}

	close();

	return 0;
}
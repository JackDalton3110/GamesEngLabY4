#include "Entity.h"
#include "HealthComponent.h"
#include "HealthSystem.h"
#include "PositionComponent.h"
#include "PositionSystem.h"
#include "Component.h"
#include "AISystem.h"
#include "RenderSystem.h"
#include "ControlSystem.h"
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 400;

bool init();
bool loadMedia();
void close();

SDL_Surface* loadSurface(std::string location);
SDL_Window* m_window = NULL;
SDL_Surface* m_ScreenSurface = NULL;
SDL_Surface* m_ImageSurface = NULL;
SDL_Rect startRect;
SDL_Rect endRect;

int count = 0;

bool init()
{
	bool success = true;

	startRect.x = 200;
	startRect.y = -100;
	startRect.w = 558;
	startRect.y = 828;

	endRect.x = 0;
	endRect.y = 0;
	endRect.w = 558;
	endRect.h = 828;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		m_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (m_window == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}
			else
			{
				//Get window surface
				m_ScreenSurface = SDL_GetWindowSurface(m_window);
			}
		}
	}

	return success;
}

bool loadMedia()
{
	bool success = true;
	m_ImageSurface = loadSurface("spritesheet.png");
	if (m_ImageSurface == NULL)
	{
		std::cout << "Failed to load image" << std::endl;
		success = false;
	}
	return success;
}

void close()
{
	SDL_FreeSurface(m_ImageSurface);
	m_ImageSurface = NULL;
	SDL_DestroyWindow(m_window);
	m_window = NULL;
	IMG_Quit();
	SDL_Quit();
}

SDL_Surface* loadSurface(std::string location)
{
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedSurface = IMG_Load(location.c_str());

	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", location.c_str(), SDL_GetError());
	}
	else
	{
		optimizedSurface = SDL_ConvertSurface(loadedSurface, m_ScreenSurface->format, NULL);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", location.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}
	return optimizedSurface;
}

int main(int argc, char* argv[])
{

	if (!init())
	{
		printf("Failed to initalize!\n");
	}
	else 
	{
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			bool quit = false;

			Entity player;
			player.addComponent(new HealthComponent()); player.addComponent(new PositionComponent());
			player.addComponent(new ControlComponent());

			Entity enemy;
			enemy.addComponent(new HealthComponent()); enemy.addComponent(new PositionComponent());

			Entity dog;
			dog.addComponent(new HealthComponent()); dog.addComponent(new PositionComponent());

			Entity cat;
			cat.addComponent(new HealthComponent()); cat.addComponent(new PositionComponent());

			HealthSystem hs;  RenderSystem rs; AISystem ai; ControlSystem cs;

			hs.addEntity(player);
			hs.addEntity(enemy);
			hs.addEntity(dog);
			hs.addEntity(cat);

			rs.addEntity(player);
			rs.addEntity(enemy);
			rs.addEntity(dog);
			rs.addEntity(cat);

			ai.addEntity(enemy);
			ai.addEntity(dog);
			ai.addEntity(cat);

			cs.addEntity(player);
			SDL_Event e;

			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					cs.input(e);
					{
						if (e.type == SDL_QUIT)
						{
							quit = true;
						}
					}
				}
				//ai.update();
				//rs.update();
				//hs.update();

				SDL_BlitSurface(m_ImageSurface, &endRect, m_ScreenSurface, &startRect);
				SDL_UpdateWindowSurface(m_window);
			}

		}
	}
	close();
	return 0;
}
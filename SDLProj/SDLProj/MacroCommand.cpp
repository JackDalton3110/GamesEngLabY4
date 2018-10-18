#include "MacroCommand.h"

MacroCommand::MacroCommand()
{

}

MacroCommand::~MacroCommand()
{
	std::cout << "deconstructing" << std::endl;
}

void MacroCommand::add(Command* command)
{
	commands.push_back(command);
}

void MacroCommand::remove(Command* command)
{
	commands.remove(command);
}

void MacroCommand::undo()
{
	std::cout << "\n" << std::endl;
	if (commands.size() > 0) {

		(*commands.rbegin())->undo();
		removedList.push_back(*commands.rbegin());
		commands.pop_back();
	}
	else {
		std::cout << "Command List Empty" << std::endl;
	}
}

void MacroCommand::redo()
{
	std::cout << "\n" << std::endl;
	if (removedList.size() > 0)
	{
		(*removedList.rbegin())->redo();
		commands.push_back(*removedList.rbegin());
		removedList.pop_back();
	}
}


void MacroCommand::execute()
{
	std::cout << "\n" << std::endl;
	std::list<Command*>::iterator iter;

	for (iter = commands.begin(); iter != commands.end(); ++iter)
	{
		(*iter)->execute();
	}

	std::cout << "\n" << "executed" << "\n" << std::endl;
}
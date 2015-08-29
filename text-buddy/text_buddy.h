#pragma once
#include <string>
#include <vector>
#include "task.h"
#include "text_buddy_command.h"

class TextBuddy
{
public:
	TextBuddy();
	~TextBuddy();

	void run(int argc, char* argv[]);
    void runInteractively();
    void runFromScriptFile(char* filename);

    TextBuddyCommand parseCommand(const std::string &command_line);
    void executeCommand(const TextBuddyCommand &command);

    void addTask(const std::string &memo);
    void deleteTask(int task_no);
    void clearTask();
    void displayTask();

    void load();
    void save();

private:

    static const std::string COMMAND_ADD;
    static const std::string COMMAND_DELETE;
    static const std::string COMMAND_CLEAR;
    static const std::string COMMAND_DISPLAY;
    static const std::string COMMAND_EXIT;
    static const std::string TASK_FILENAME;

    std::vector<Task> task_list;
    std::string filename;
};


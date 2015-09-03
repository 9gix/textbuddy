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

    /* Application Mode. */
    // Start Application Call
	void run(int argc, char* argv[]);
    void runInteractively();

    // User Command Parser and executor
    TextBuddyCommand parseCommand(const std::string &command_line);
    void executeCommand(const TextBuddyCommand &command);


    // Basic Operation of the Task
    void addTask(const std::string &memo);
    void deleteTask(int task_no);
    void clearTask();
    void displayTask();


    // IO Operation (Backup/Restore)
    void load(); // clear and readd task from the task file to application
    void save(); // store the task from application to a task file.

    std::vector<Task> getTaskList();

private:

    static const std::string COMMAND_ADD;
    static const std::string COMMAND_DELETE;
    static const std::string COMMAND_CLEAR;
    static const std::string COMMAND_DISPLAY;
    static const std::string COMMAND_EXIT;
    static const std::string TASK_FILENAME;

    std::vector<Task> task_list;
};


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "text_buddy.h"
#include "task.h"
#include "text_buddy_command.h"

const std::string TextBuddy::COMMAND_ADD = std::string("add");
const std::string TextBuddy::COMMAND_DELETE = std::string("delete");
const std::string TextBuddy::COMMAND_CLEAR = std::string("clear");
const std::string TextBuddy::COMMAND_DISPLAY = std::string("display");
const std::string TextBuddy::COMMAND_EXIT = std::string("exit");

const std::string TextBuddy::TASK_FILENAME = std::string("task_list.txt");

TextBuddy::TextBuddy() {

}
TextBuddy::~TextBuddy() {

}

void TextBuddy::runInteractively() {
    std::string command_line;
    while (std::getline(std::cin, command_line)) {
        std::cout << "Command: " << command_line << std::endl;
        TextBuddyCommand command = this->parseCommand(command_line);
        this->executeCommand(command);
    }
}

TextBuddyCommand TextBuddy::parseCommand(const std::string &command_line) {
    TextBuddyCommand command;
    std::istringstream command_stream(command_line);
    command_stream >> command.command >> std::ws;
    std::getline(command_stream, command.argument);
    return command;
}

void TextBuddy::executeCommand(const TextBuddyCommand &command) {
    if (command.command.compare(TextBuddy::COMMAND_ADD) == 0) {
        std::string memo(command.argument);
        this->addTask(memo);
        std::cout << "Added task: \"" << memo << "\"" << std::endl;
    } else if (command.command.compare(TextBuddy::COMMAND_DELETE) == 0) {
        int task_index = atoi(command.argument.c_str()) - 1;
        std::string memo(this->task_list.at(task_index).memo);
        this->deleteTask(task_index);
        std::cout << "Deleted task: \"" << memo << "\"" << std::endl;
    } else if (command.command.compare(TextBuddy::COMMAND_CLEAR) == 0) {
        this->clearTask();
        this->save();
        std::cout << "All task have been deleted" << std::endl;
    } else if (command.command.compare(TextBuddy::COMMAND_DISPLAY) == 0) {
        // this->load(); // re-loading is not efficient. Consider diff algorithm later instead.
        this->displayTask();
    } else if (command.command.compare(TextBuddy::COMMAND_EXIT) == 0) {
        exit(EXIT_SUCCESS);
    } else {
        // TODO: raise unregistered command exception
    }
    std::cout << std::endl;
}

void TextBuddy::run(int argc, char* argv[]) {
    // restore existing task.
    this->load();
    this->runInteractively();
}

void TextBuddy::addTask(const std::string &memo) {
    Task task;
    task.memo = memo;
    this->task_list.push_back(task);
    this->save();
}

void TextBuddy::deleteTask(int task_index) {
    this->task_list.erase(this->task_list.begin() + task_index);
    this->save();
}

void TextBuddy::clearTask() {
    this->task_list.clear();
}

void TextBuddy::displayTask() {
    if (this->task_list.empty()) {
        std::cout << "Task List is empty" << std::endl;
    } else {
        for (size_t i = 0; i < this->task_list.size(); ++i) {
            std::cout << i + 1 << ". " << this->task_list.at(i).memo << std::endl;
        }
    }
}

void TextBuddy::load() {
    std::ifstream task_file(TASK_FILENAME);
    std::string memo;
    if (task_file.is_open()) {
        this->task_list.clear();
        while (std::getline(task_file, memo)) {
            this->addTask(memo);
        }
    }
}

void TextBuddy::save() {
    std::ofstream task_file(TASK_FILENAME);
    if (task_file.is_open()) {
        for (std::vector<Task>::const_iterator it = this->task_list.begin(); 
                it != this->task_list.end(); 
                ++it) {
            task_file << *it;        
        }
        task_file.close();
    }
}

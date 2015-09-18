#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <exception>
#include <functional>
#include "text_buddy.h"
#include "task.h"
#include "text_buddy_command.h"
#include "command.h"
#include "add_command.h"
#include "delete_command.h"
#include "clear_command.h"
#include "sort_command.h"
#include "search_command.h"
#include "exit_command.h"
#include "display_command.h"
#include <tuple>
#include <algorithm>
#include <map>

const std::string TextBuddy::COMMAND_ADD = std::string("add");
const std::string TextBuddy::COMMAND_DELETE = std::string("delete");
const std::string TextBuddy::COMMAND_CLEAR = std::string("clear");
const std::string TextBuddy::COMMAND_DISPLAY = std::string("display");
const std::string TextBuddy::COMMAND_SEARCH = std::string("search");
const std::string TextBuddy::COMMAND_SORT = std::string("sort");
const std::string TextBuddy::COMMAND_EXIT = std::string("exit");

const std::string TextBuddy::TASK_FILENAME = std::string("task_list.txt");

TextBuddy::TextBuddy() {

}
TextBuddy::~TextBuddy() {

}

void TextBuddy::runInteractively() {
    std::cout << "Welcome to TextBuddy" << std::endl << std::endl;
    std::string command_line;
    while (std::getline(std::cin, command_line)) {
        std::cout << "Command: " << command_line << std::endl;
        //TextBuddyCommand command_token = this->parseCommand(command_line);
        Command* command = this->parseCommand(command_line);
        command->execute();
        std::cout << command << std::endl;
        delete command;
    }
}

std::tuple<std::string, std::string> splitFirstWhiteSpace(const std::string line) {
    std::string head, tail;
    std::istringstream command_stream(line);
    command_stream >> head >> std::ws;
    std::getline(command_stream, tail);
    return std::make_tuple(head, tail);
}

Command* TextBuddy::parseCommand(const std::string &command_line) {
    std::string cmd_token, arg_token;

    std::tie(cmd_token, arg_token) = splitFirstWhiteSpace(command_line);

    std::map<std::string, Command*> command_map {
        { TextBuddy::COMMAND_ADD, new AddCommand(this, arg_token) },
        { TextBuddy::COMMAND_DELETE, new DeleteCommand(this, atoi(arg_token.c_str()))},
        { TextBuddy::COMMAND_CLEAR, new ClearCommand(this)},
        { TextBuddy::COMMAND_SORT, new SortCommand(this)},
        { TextBuddy::COMMAND_SEARCH, new SearchCommand(this, arg_token)},
        { TextBuddy::COMMAND_EXIT, new ExitCommand()},
        { TextBuddy::COMMAND_DISPLAY, new DisplayCommand(this)},
    };
    return command_map.at(cmd_token);
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
}

void TextBuddy::deleteTask(int task_index) {
    if (!this->task_list.empty() && (int)this->task_list.size() > task_index) {
        this->task_list.erase(this->task_list.begin() + task_index);
    } else {
        throw std::out_of_range("Invalid Task Index");
    }
}

void TextBuddy::clearTask() {
    this->task_list.clear();
}

void TextBuddy::sortTask() {
    std::sort(this->task_list.begin(), this->task_list.end());
}

std::vector<Task> TextBuddy::getTaskList() {
    return this->task_list;
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

#include "search_command.h"

SearchCommand::SearchCommand(TextBuddy * textbuddy, std::string keyword) : tb(textbuddy), keyword(keyword) {
}

void SearchCommand::execute() {
    auto task_list = tb->getTaskList();
    if (task_list.empty()) {
        this->outstream << "Task List is empty" << std::endl;
    } else {
        for (size_t i = 0; i < task_list.size(); ++i) {
            std::string memo = task_list.at(i).memo;
            if (memo.find(this->keyword) != std::string::npos) {
                this->outstream << i + 1 << ". " << task_list.at(i).memo << std::endl;
            }
        }
    }
}

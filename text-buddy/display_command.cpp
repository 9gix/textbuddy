#include "display_command.h"



DisplayCommand::DisplayCommand(TextBuddy* textbuddy)
    : tb(textbuddy) {
}

void DisplayCommand::execute() {
    tb->displayTask();
    auto task_list = tb->getTaskList();
    if (task_list.empty()) {
        this->outstream << "Task List is empty" << std::endl;
    } else {
        for (size_t i = 0; i < task_list.size(); ++i) {
            this->outstream << i + 1 << ". " << task_list.at(i).memo << std::endl;
        }
    }
}

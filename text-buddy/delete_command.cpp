#include "delete_command.h"
#include "text_buddy.h"



DeleteCommand::DeleteCommand(TextBuddy* textbuddy, int task_id) 
    : tb(textbuddy) {
    this->task_index = task_id - 1;
}

void DeleteCommand::execute() {
    std::string memo(tb->getTaskList().at(task_index).memo);
    tb->deleteTask(task_index);
    tb->save();
    this->outstream << "Deleted task: \"" << memo << "\"" << std::endl;
}

#include "add_command.h"

AddCommand::AddCommand(TextBuddy * textbuddy, std::string memo)
    : memo(memo)
    , tb(textbuddy) { }

void AddCommand::execute() {
    tb->addTask(memo);
    tb->save();
    this->outstream << "Added task: \"" << this->memo << "\"" << std::endl;
}
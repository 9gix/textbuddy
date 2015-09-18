#include "clear_command.h"
#include "text_buddy.h"


ClearCommand::ClearCommand(TextBuddy* textbuddy)
    : tb(textbuddy) {
}

void ClearCommand::execute() {
    tb->clearTask();
    tb->save();
    this->outstream << "All task have been deleted" << std::endl;
}
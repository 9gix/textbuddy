#include "sort_command.h"
#include "text_buddy.h"


SortCommand::SortCommand(TextBuddy* textbuddy) : tb(textbuddy) {
}


void SortCommand::execute() {
    tb->sortTask();
}
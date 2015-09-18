#pragma once
#include "command.h"
#include <sstream>
#include "text_buddy.h"
class DeleteCommand :
    public Command {
public:
    DeleteCommand(TextBuddy*, int);
    virtual void execute();

private:
    TextBuddy* tb;
    int task_index;
};


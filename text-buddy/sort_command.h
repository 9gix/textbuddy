#pragma once
#include "command.h"
#include "text_buddy.h"

class SortCommand : public Command {
public:
    SortCommand(TextBuddy*);
    virtual void execute();

private:
    TextBuddy* tb;
};


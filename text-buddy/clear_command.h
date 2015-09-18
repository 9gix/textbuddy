#pragma once
#include "command.h"
#include <sstream>
#include "text_buddy.h"
class ClearCommand :
    public Command {
public:
    ClearCommand(TextBuddy*);
    virtual void execute();
private:
    TextBuddy* tb;
};


#pragma once
#include "command.h"
#include <sstream>
#include "text_buddy.h"

class DisplayCommand : public Command {
public:
    DisplayCommand(TextBuddy*);
    virtual void execute();

private:
    TextBuddy* tb;
};


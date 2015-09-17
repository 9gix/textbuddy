#pragma once
#include "command.h"
#include <sstream>
#include "text_buddy.h"

class AddCommand : public Command {
public:
    AddCommand(TextBuddy*, std::string);
    virtual void execute();

private:
    TextBuddy* tb;
    std::string memo;
    std::ostringstream outstream;
};


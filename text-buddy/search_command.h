#pragma once
#include "command.h"
#include "text_buddy.h"

class SearchCommand : public Command {
public:
    SearchCommand(TextBuddy*, std::string);
    virtual void execute();
private:
    TextBuddy* tb;
    std::string keyword;
};


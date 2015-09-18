#pragma once
#include <sstream>

/* Base Class for TextBuddy Command */
class Command {
public:
    virtual ~Command() {};
    virtual void execute() = 0;
    friend std::ostream& operator<<(std::ostream&, const Command*);
protected:
    Command() {};
    std::ostringstream outstream;
};

std::ostream& operator<<(std::ostream&, const Command*);
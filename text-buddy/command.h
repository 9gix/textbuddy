#pragma once
#include <sstream>

class Command {
public:
    virtual ~Command() {};
    virtual void execute() = 0;
    virtual void print(std::ostream& out) const;
    friend std::ostream& operator<<(std::ostream&, const Command*);
protected:
    Command() {};
    std::ostringstream outstream;
};

std::ostream& operator<<(std::ostream&, const Command*);
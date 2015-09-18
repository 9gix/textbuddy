#pragma once
#include "command.h"
class ExitCommand :
    public Command {
public:
    ExitCommand();
    virtual void execute();
};


#include "exit_command.h"
#include <iostream>


ExitCommand::ExitCommand() {
}

void ExitCommand::execute() {
    exit(EXIT_SUCCESS);
}
#include "command.h"


void Command::print(std::ostream& out) const {
    out << this->outstream.str();
}
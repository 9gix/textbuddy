#include "command.h"


void Command::print(std::ostream& out) const {
    out << this->outstream.str();
}


std::ostream & operator<<(std::ostream &out, const Command* cmd) {
    cmd->print(out);
    return out;
}
#include "command.h"


/* overload function for stream output */
std::ostream & operator<<(std::ostream &out, const Command* cmd) {
    out << cmd->outstream.str();
    return out;
}
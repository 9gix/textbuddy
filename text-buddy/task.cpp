#include <iostream>
#include <string>
#include "task.h"

std::istream& operator>>(std::istream& in, Task task) {
    std::string memo;
    std::getline(in, memo);
    task.memo = memo;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Task &task) {
    out << task.memo << std::endl;
    return out;
}

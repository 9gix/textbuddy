#include <iostream>
#include <string>
#include "task.h"

std::ostream& operator<<(std::ostream& out, const Task &task) {
    // output the memo of the task, and go to the new line.
    out << task.memo << std::endl;
    return out;
}

bool Task::operator<(const Task & task2) {
    return this->memo.compare(task2.memo) < 0;
}

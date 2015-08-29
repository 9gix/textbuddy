#pragma once
#include "string"

struct Task {
    friend std::ostream &operator <<(std::ostream &output, const Task &task);
    friend std::istream &operator >>(std::istream &input, Task &task);
    std::string memo;
};
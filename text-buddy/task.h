#pragma once
#include "string"


/* Data structure for task*/
struct Task {
    // Input Output operator overloading
    friend std::ostream &operator <<(std::ostream &output, const Task &task);
    bool operator<(const Task& task2);
    std::string memo;
};
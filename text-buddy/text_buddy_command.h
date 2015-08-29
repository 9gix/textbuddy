#pragma once
#include <string>

/* Abstraction for User Command and its argument */
struct TextBuddyCommand {
    std::string command;
    std::string argument;
};
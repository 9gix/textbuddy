#include "utils.h"


std::tuple<std::string, std::string> splitFirstWhiteSpace(const std::string line) {
    std::string head, tail;
    std::istringstream command_stream(line);
    command_stream >> head >> std::ws;
    std::getline(command_stream, tail);
    return std::make_tuple(head, tail);
}
#pragma once
#include <tuple>
#include <string>
#include <sstream>

/* Split only on first whitespace, return a tuple of <First word, Remaining String> */
std::tuple<std::string, std::string> splitFirstWhiteSpace(const std::string line);
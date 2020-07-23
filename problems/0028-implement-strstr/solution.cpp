#include <string>

int strStr(const std::string& haystack, const std::string& needle) {
    auto pos = haystack.find(needle);
    return pos == std::string::npos ? -1 : pos;
}


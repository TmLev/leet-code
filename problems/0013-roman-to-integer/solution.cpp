#include <string>

int romanToInt(std::string s) {
    int result = s.empty() ? 0 : convert(s.back());
    
    for (std::size_t i = 0; i + 1 < s.size(); ++i) {
        int sign = convert(s[i]) < convert(s[i + 1]) ? -1 : 1;
        result += sign * convert(s[i]);
    }
    
    return result;
}

constexpr int convert(char c) {
    switch (c) {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        throw std::runtime_error("Unknown Roman character");
    }
} 

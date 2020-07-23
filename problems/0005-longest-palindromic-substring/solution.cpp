#include <algorithm>
#include <string>

std::string longestPalindrome(const std::string& s) {
    if (s.empty()) {
        return {};
    }
    
    auto begin = 0;
    auto end = 0;
    
    for (int i = 0; i < s.size(); ++i) {
        auto length = std::max(expand(s, i, i), expand(s, i, i + 1));
        if (length > end - begin) {
            begin = i - (length - 1) / 2;
            end   = i + length / 2;
        }
    }
    
    return std::string(s.begin() + begin, s.begin() + end + 1);
}

int expand(const std::string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left;
        ++right;
    }
    
    return right - left - 1;
}

#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>

int lengthOfLongestSubstring(const std::string& s) {
    int result = 0;
    std::unordered_map<char, int> met;
        
    for (auto [i, j] = std::tuple{0, 0}; i < s.size(); ++i) {
        if (met.find(s[i]) != met.end()) {
            j = std::max(met[s[i]], j);
        }
        
        result = std::max(result, i - j + 1);
        met[s[i]] = i + 1;
    }
    
    return result;
}


#include <string>
#include <vector>

std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    if (strs.empty()) {
        return {};
    }
    
    auto max_length = strs[0].size();
    for (const auto& str : strs) {
        max_length = std::min(max_length, str.size());
    }
    
    std::string result;
    result.reserve(max_length);

    for (std::size_t i = 0; i < max_length; ++i) {
        result.push_back(strs[0][i]);
        
        for (const auto& str : strs) {
            if (str[i] != result.back()) {
                result.pop_back();
                return result;
            }
        }
    }
    
    return result;
}

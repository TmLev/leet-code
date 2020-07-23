#include <string>

std::string convert(const std::string& s, int numRows) {
    if (numRows == 1) {
        return s;
    }

    std::string result;
    int cycle = 2 * numRows - 2;

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; i + j < s.size(); j += cycle) {
            result.push_back(s[i + j]);

            if (i != 0 && i != numRows - 1 && j + cycle - i < s.size()) {
                result.push_back(s[j + cycle - i]);
            }
        }
    }

    return result;
}


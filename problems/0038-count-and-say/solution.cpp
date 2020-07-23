#include <string>

std::string nextNumber(const std::string& s) {
    std::string result;

    for (int i = 0; i < s.size(); i++) {
        int count = 1;

        while (i + 1 < s.size() && s[i] == s[i + 1]) {
            ++i;
            ++count;
        }

        result += std::to_string(count) + s[i];
    }

    return result;
}

std::string countAndSay(int n) {
    std::string s{"1"};

    for (int i = 1; i < n; i++) {
        s = nextNumber(s);
    }

    return s;
}


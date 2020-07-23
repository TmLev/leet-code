#include <string>

bool isPalindrome(int x) {
    auto str = std::to_string(x);
    auto reverse = std::string(str.rbegin(), str.rend());
    return str == reverse;
}

#include <string>
#include <vector>

bool isMatch(const std::string& s, const std::string& p) {
    std::vector<std::vector<bool>> dp(s.size() + 1, std::vector<bool>(p.size() + 1, false));
    dp[s.size()][p.size()] = true;

    for (int i = s.size(); i >= 0; --i) {
        for (int j = static_cast<int>(p.size()) - 1; j >= 0; --j) {
            bool first_match = i < s.size() && (p[j] == s[i] || p[j] == '.');

            if (j + 1 < p.size() && p[j + 1] == '*') {
                dp[i][j] = dp[i][j + 2] || first_match && dp[i + 1][j];
            } else {
                dp[i][j] = first_match && dp[i + 1][j + 1];
            }
        }
    }

    return dp[0][0];
}


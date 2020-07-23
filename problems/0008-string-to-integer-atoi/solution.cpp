#include <string>
#include <climits>

int myAtoi(const std::string& str) {
    long long int result = 0;
    int sign = 1;

    int i = str.find_first_not_of(' ');
    if (i == std::string::npos) {
        return 0;
    }

    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i++] == '-') ? -1 : 1;
    }

    while ('0'<= str[i] && str[i] <= '9') {
        result = result * 10 + (str[i++] - '0');

        if (sign * result >= INT_MAX) {
            return INT_MAX;
        }

        if (sign * result <= INT_MIN) {
            return INT_MIN;
        }
    }

    return sign * result;
}


#include <limits>

int reverse(int x) {
    int int_min = std::numeric_limits<int>::min();
    int int_max = std::numeric_limits<int>::max();
    
    int result = 0;
    
    while (x) {
        int digit = x % 10;
        x /= 10;
        
        if (result > int_max / 10 || (result == int_max && digit > 7)) {
            return 0;
        }
        
        if (result < int_min / 10 || (result == int_min && digit < -8)) {
            return 0;
        }

        result = result * 10 + digit;
    }
    
    return result;
}

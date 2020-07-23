#include <stack>
#include <string>

bool isValid(const std::string& s) {
    std::stack<char> stack;
    
    for (auto c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
            continue;
        }
        
        if (stack.empty()) {
            return false;
        }
        
        auto last = stack.top();
        stack.pop();
        
        if (last == '(' && c != ')') {
            return false;
        }
        
        if (last == '{' && c != '}') {
            return false;
        }
        
        if (last == '[' && c != ']') {
            return false;
        }
    }
    
    return stack.empty();
}

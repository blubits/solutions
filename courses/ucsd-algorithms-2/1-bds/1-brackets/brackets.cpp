#include <algorithm>
#include <iostream>
#include <stack>

int main() {
    char c;
    int i = 1, idx_error = 0;
    std::stack<std::pair<char, int>> brackets;
    bool success = true;
    while (std::cin >> c) {
        if (c == '[' || c == '{' || c == '(') {
            brackets.push(std::make_pair(c, i));
        } else if (c == ']' || c == ')' || c == '}') {
            if (brackets.empty()) {
                success = false;
                idx_error = i;
                break;
            }
            char t = brackets.top().first;
            int ti = brackets.top().second;
            brackets.pop();
            if ((c == ']' && t != '[') || (c == ')' && t != '(') ||
                (c == '}' && t != '{')) {
                success = false;
                idx_error = i;
                break;
            }
        }
        i++;
    }
    if (success && !brackets.empty()) {
        success = false;
        idx_error = brackets.top().second;
    }
    if (success) {
        std::cout << "Success";
    } else {
        std::cout << idx_error;
    }
    std::cout << std::endl;
}

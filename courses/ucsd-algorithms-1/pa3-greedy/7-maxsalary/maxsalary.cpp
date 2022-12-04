#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool is_greater_or_equal(std::string a, std::string b) {
    if (b == "-infty") return true;
    if (a.size() == b.size())
        return a >= b;
    else {
        for (int i = 0; i < std::max(a.size(), b.size()); i++) {
            if (i >= b.size()) {
                if (a[i] != b[0]) {
                    return (a[i] > b[0]);
                } else if (i == a.size() - 1) {
                    return (a[i] > b[0]) ||
                           (a[i] == b[0] && a[a.size() - 1] > b[b.size() - 1]);
                }
            } else if (i >= a.size()) {
                if (a[0] != b[i]) {
                    return (a[0] > b[i]);
                } else if (i == b.size() - 1) {
                    return (a[0] > b[i]) ||
                           (a[0] == b[i] && a[a.size() - 1] > b[b.size() - 1]);
                }
            } else if (a[i] != b[i]) {
                return a[i] > b[i];
            }
        }
    }
}

std::string max_number(int N, std::vector<std::string> digits) {
    std::string ans;
    while (!digits.empty()) {
        std::string max_digit = "-infty";
        for (std::string digit : digits) {
            if (is_greater_or_equal(digit, max_digit)) {
                max_digit = digit;
            }
        }
        digits.erase(std::find(digits.begin(), digits.end(), max_digit));
        ans += max_digit;
    }
    return ans;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<std::string> digits(N);
    for (int i = 0; i < N; i++) {
        std::cin >> digits[i];
    }
    std::cout << max_number(N, digits) << std::endl;
    return 0;
}

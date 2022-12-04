#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    std::stack<std::pair<int, int>> s;
    int N, max_top = 0;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::string command;
        std::cin >> command;
        if (command == "push") {
            int k;
            std::cin >> k;
            max_top = std::max(k, max_top);
            s.push(make_pair(k, max_top));
        } else if (command == "pop") {
            s.pop();
            max_top = s.top().second;
        } else if (command == "max") {
            std::cout << max_top << std::endl;
        }
    }
}
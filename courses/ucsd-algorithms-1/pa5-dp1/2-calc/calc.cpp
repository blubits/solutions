#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

int main() {
    int N;
    std::cin >> N;
    int min_ops[N + 10], prev_num[N + 10];
    min_ops[0] = -1;
    prev_num[0] = -1;
    min_ops[1] = 0;
    prev_num[1] = 0;
    for (int i = 2; i <= N; i++) {
        // calculate +1
        int min_ops_i = min_ops[i - 1] + 1;
        int prev_num_i = i - 1;
        // calculate x2
        if (i % 2 == 0 && min_ops[i / 2] + 1 <= min_ops_i) {
            min_ops_i = min_ops[i / 2] + 1;
            prev_num_i = i / 2;
        }
        // calculate x3
        if (i % 3 == 0 && min_ops[i / 3] + 1 <= min_ops_i) {
            min_ops_i = min_ops[i / 3] + 1;
            prev_num_i = i / 3;
        }
        min_ops[i] = min_ops_i;
        prev_num[i] = prev_num_i;
    }
    std::cout << min_ops[N] << std::endl;
    std::stack<int> trace;
    int curr_num = N;
    while (prev_num[curr_num] != -1) {
        trace.push(curr_num);
        curr_num = prev_num[curr_num];
    }
    while (!trace.empty()) {
        std::cout << trace.top() << " ";
        trace.pop();
    }
    std::cout << std::endl;
    return 0;
}

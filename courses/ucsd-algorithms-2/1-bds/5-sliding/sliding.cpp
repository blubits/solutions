#include <deque>
#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        std::cin >> numbers[i];
    }
    int k;
    std::cin >> k;
    std::deque<int> dq;
    // process first k elements
    for (int i = 0; i < k; i++) {
        // if the elements in the rear are less than numbers[i], pop them
        while (!dq.empty() && numbers[dq.back()] <= numbers[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    std::cout << numbers[dq.front()] << " ";
    for (int i = k; i < N; i++) {
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        while (!dq.empty() && numbers[dq.back()] <= numbers[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        std::cout << numbers[dq.front()] << " ";
    }
    std::cout << std::endl;
    return 0;
}
#include <algorithm>
#include <iostream>
#include <vector>

int majority_element(std::vector<int> numbers, int N) {
    std::sort(numbers.begin(), numbers.end());
    int curr_i = numbers[0], curr_count = 1;
    for (int i = 1; i < N; i++) {
        if (curr_i != numbers[i]) {
            curr_i = numbers[i];
            curr_count = 1;
        } else {
            curr_count++;
            if (curr_count > (N / 2)) return curr_i;
        }
    }
    return -1;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        std::cin >> numbers[i];
    }
    std::cout << (majority_element(numbers, N) != -1) << std::endl;
    return 0;
}

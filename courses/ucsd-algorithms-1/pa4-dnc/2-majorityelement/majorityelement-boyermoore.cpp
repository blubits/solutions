#include <algorithm>
#include <iostream>
#include <vector>

int majority_element(std::vector<int> numbers, int N) {
    int m, cnt = 0;
    for (int i = 0; i < N; i++) {
        if (cnt == 0) {
            m = numbers[i];
            cnt = 1;
        } else if (m == numbers[i]) {
            cnt++;
        } else {
            cnt--;
        }
    }
    int cnt_m = 0;
    for (int i = 0; i < N; i++) {
        if (numbers[i] == m) cnt_m++;
    }
    return (cnt_m > (N / 2)) ? m : -1;
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

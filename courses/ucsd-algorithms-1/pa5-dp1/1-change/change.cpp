#include <algorithm>
#include <iostream>

int main() {
    int N;
    std::cin >> N;
    int change[N + 10];

    // base cases
    change[0] = 1;
    change[1] = 1;
    change[2] = 2;
    change[3] = 1;
    change[4] = 1;

    for (int i = 5; i <= N; i++) {
        change[i] = std::min(std::min(change[i - 1] + 1, change[i - 3] + 1),
                             change[i - 4] + 1);
    }

    std::cout << change[N] << std::endl;
}

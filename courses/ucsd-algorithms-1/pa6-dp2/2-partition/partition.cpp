#include <iostream>
#include <vector>

int main() {
    int N, sum = 0;
    std::cin >> N;
    std::vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        std::cin >> numbers[i];
        sum += numbers[i];
    }
    if (sum % 3 != 0) {
        std::cout << 0 << std::endl;
        return 0;
    }
    int size = sum / 3;
    int ks[N + 10][size + 10][size + 10];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= size; j++) {
            for (int k = 0; k <= size; k++) {
                if (i == 0)
                    ks[i][j][k] = 0;
                else if (j == 0 && k == 0)
                    ks[i][j][k] = 0;
                else {
                    int no_take = ks[i - 1][j][k];
                    int take_one =
                        j < numbers[i - 1]
                            ? 0
                            : ks[i - 1][j - numbers[i - 1]][k] + numbers[i - 1];
                    int take_two =
                        k < numbers[i - 1]
                            ? 0
                            : ks[i - 1][j][k - numbers[i - 1]] + numbers[i - 1];
                    ks[i][j][k] =
                        std::max(std::max(no_take, take_one), take_two);
                }
            }
        }
    }
    std::cout << (ks[N][size][size] == 2 * size) << std::endl;
}

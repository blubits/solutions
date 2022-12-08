#include <iostream>

int min_change(int k) {
    int num_coins = 0;
    int denoms[3] = {10, 5, 1};
    for (int i = 0; i < 3; i++) {
        num_coins += k / denoms[i];
        k %= denoms[i];
    }
    return num_coins;
}

int main() {
    int amt;
    std::cin >> amt;
    std::cout << min_change(amt) << std::endl;
    return 0;
}

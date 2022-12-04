#include <algorithm>
#include <iostream>
#include <vector>

typedef long long int ll;

ll max_pairwise_product(std::vector<ll> &numbers) {
    ll a = 0, ai = 0, b = 0;
    for (ll i = 0; i < numbers.size(); i++) {
        if (numbers[i] > a) {
            a = numbers[i];
            ai = i;
        }
    }
    for (ll i = 0; i < numbers.size(); i++) {
        if (numbers[i] > b && i != ai) {
            b = numbers[i];
        }
    }
    return a * b;
}

int main() {
    ll N;
    std::cin >> N;
    std::vector<ll> numbers(N);
    for (ll i = 0; i < N; i++) {
        std::cin >> numbers[i];
    }
    std::cout << max_pairwise_product(numbers) << std::endl;
    return 0;
}

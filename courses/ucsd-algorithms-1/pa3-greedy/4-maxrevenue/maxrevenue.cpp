#include <algorithm>
#include <iostream>
#include <vector>

long long int max_sum_product(int N, std::vector<long long int> a,
                              std::vector<long long int> b) {
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    long long int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long int> a(n), b(n);
    for (long long int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (long long int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    std::cout << max_sum_product(n, a, b) << std::endl;
    return 0;
}

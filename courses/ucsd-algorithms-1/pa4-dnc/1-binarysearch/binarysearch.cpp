#include <algorithm>
#include <iostream>
#include <vector>

int binary_search(std::vector<int> numbers, int qi, int n) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + ((hi - lo) / 2);
        if (numbers[mid] == qi)
            return mid;
        else if (numbers[mid] > qi)
            hi = mid - 1;
        else if (numbers[mid] < qi)
            lo = mid + 1;
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
    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int qi;
        std::cin >> qi;
        std::cout << binary_search(numbers, qi, N) << " ";
    }
    std::cout << std::endl;
    return 0;
}

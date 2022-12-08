#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

std::pair<int, int> partition3(std::vector<int> &arr, int l, int r) {
    int pivot = arr[l], m1 = l, m2 = l;
    for (int i = l + 1; i <= r; i++) {
        if (pivot > arr[i]) {
            m1++;
            m2++;
            std::swap(arr[m2], arr[i]);
            std::swap(arr[m2], arr[m1]);
        } else if (pivot == arr[i]) {
            m2++;
            std::swap(arr[m2], arr[i]);
        }
    }
    std::swap(arr[l], arr[m1]);
    return std::make_pair(m1, m2);
}

void quicksort_r3(std::vector<int> &arr, int l, int r) {
    if (l >= r) return;

    // Select random element and make it the pivot
    int k = l + std::rand() % (r - l + 1);
    std::swap(arr[l], arr[k]);
    auto m = partition3(arr, l, r);

    quicksort_r3(arr, l, m.first - 1);
    quicksort_r3(arr, m.second + 1, r);
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    quicksort_r3(arr, 0, N - 1);
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

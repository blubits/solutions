#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> swaps;

void sift_down(int arr[], int i, int N) {
    int j = i;
    while (2 * j <= N) {
        int child = 2 * j;
        if (child != N && arr[child] > arr[child + 1]) child++;
        if (arr[j] > arr[child]) {
            int temp = arr[j];
            arr[j] = arr[child];
            arr[child] = temp;
            swaps.push_back(std::make_pair(j - 1, child - 1));
            j = child;
        } else {
            return;
        }
    }
}

int main() {
    int N;
    std::cin >> N;
    int arr[N + 10];
    for (int i = 1; i <= N; i++) {
        std::cin >> arr[i];
    }
    // heapify
    for (int i = N / 2; i >= 1; i--) {
        sift_down(arr, i, N);
        // std::cout << i << ": ";
        // for (int i = 1; i <= N; i++) std::cout << arr[i] << " ";
        // std::cout << std::endl;
    }
    std::cout << swaps.size() << std::endl;
    for (auto p : swaps) {
        std::cout << p.first << " " << p.second << std::endl;
    }
}

#include <iostream>
#include <vector>

using namespace std;

int merge_and_count_inversions(std::vector<int> &arr, int l, int m, int r) {
    std::vector<int> hold(r - l + 1);
    int ptr_left = l, ptr_right = m + 1, ptr_new = 0, count = 0;
    while (ptr_left <= m && ptr_right <= r) {
        if (arr[ptr_left] > arr[ptr_right]) {
            count += (m - ptr_left + 1);
            hold[ptr_new++] = arr[ptr_right++];
        } else {
            hold[ptr_new++] = arr[ptr_left++];
        }
    }
    for (int i = ptr_left; i <= m; i++) {
        hold[ptr_new++] = arr[i];
    }
    for (int i = ptr_right; i <= r; i++) {
        hold[ptr_new++] = arr[i];
    }
    for (int i = 0; i < r - l + 1; i++) {
        arr[l + i] = hold[i];
    }
    return count;
}

int sort_and_count_inversions(std::vector<int> &arr, int l, int r) {
    if (l >= r) return 0;
    int mid = l + ((r - l) / 2), count = 0;
    count += sort_and_count_inversions(arr, l, mid);
    count += sort_and_count_inversions(arr, mid + 1, r);
    count += merge_and_count_inversions(arr, l, mid, r);
    return count;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    std::cout << sort_and_count_inversions(arr, 0, N - 1) << std::endl;
}

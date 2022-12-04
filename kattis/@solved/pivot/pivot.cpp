#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    int arr[t];
    // maximum element to the left of index i
    int max_left[t];
    // minimum element to the right of index i
    int min_right[t];
    for (int i = 0; i < t; i++) {
        cin >> arr[i];
    }
    // search max
    int max_el = arr[0];
    max_left[0] = arr[0] - 1;
    for (int i = 1; i < t; i++) {
        max_left[i] = max_el;
        max_el = max(arr[i], max_el);
    }
    // search max
    int min_el = arr[t - 1];
    min_right[t - 1] = arr[t - 1] + 1;
    for (int i = t - 2; i >= 0; i--) {
        min_right[i] = min_el;
        min_el = min(arr[i], min_el);
    }
    // count possible pivots
    // this happens when maximum element to the left of the pivot is
    // less than pivot (max_left[i] < arr[i])
    // and when the minimum element to the right of the pivot is
    // greater than pivot (min_right[i] > arr[i])
    int p = 0;
    for (int i = 0; i < t; i++) {
        if (max_left[i] < arr[i] && min_right[i] > arr[i]) {
            // cout << max_left[i] << "-" << min_right[i] << endl;
            // cout << i << " " << arr[i] << endl;
            p++;
        }
    }
    cout << p << endl;
    return 0;
}

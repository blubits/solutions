#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int n, k, max_requests = 0, curr_requests = 0;
    int requests[101001] = {};
    cin >> n >> k;
    while (n--) {
        int ti;
        cin >> ti;
        requests[ti] += 1;
        requests[ti + 1000] -= 1;
    }
    for (int i = 0; i <= 101000; i++) {
        curr_requests += requests[i];
        max_requests = max(max_requests, curr_requests);
    }
    cout << int(ceil(max_requests / double(k))) << endl;
    return 0;
}

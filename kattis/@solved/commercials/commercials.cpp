#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    long long listeners[n];
    for (int i = 0; i < n; i++) {
        cin >> listeners[i];
        listeners[i] -= p;
    }
    int sum = 0, m = 0;
    for (int i = 0; i < n; i++) {
        sum += listeners[i];
        m = max(m, sum);
        if (sum < 0) sum = 0;
    }
    cout << m << endl;
}

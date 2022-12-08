#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, c = 1;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<long long> v1(k), v2(k);
        for (int i = 0; i < k; i++) cin >> v1[i];
        for (int i = 0; i < k; i++) cin >> v2[i];
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        long long sp = 0;
        for (int i = 0; i < k; i++) {
            sp += v1[i] * v2[k - i - 1];
        }
        cout << "Case #" << c++ << ": " << sp << endl;
    }
    return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;
    cin >> k;
    vector<int> n(k);
    while (k--) {
        cin >> n[k];
    }
    sort(n.begin(), n.end());
    // for (int i = 0; i < n.size(); i++) cout << n[i] << endl;
    int ans = n.size();
    for (int i = 0; i < n.size(); i++) {
        ans = min(ans, i + n[n.size() - i - 1]);
    }
    cout << ans << endl;
    return 0;
}

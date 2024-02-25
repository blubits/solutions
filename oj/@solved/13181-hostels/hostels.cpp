#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string k;
    while (getline(cin, k)) {
        vector<int> x_pos;
        for (int i = 0; i < k.size(); i++) {
            if (k[i] == 'X') x_pos.push_back(i);
        }
        int ks = k.size();
        int ans = max(x_pos[0] - 1, (ks - 1) - x_pos[x_pos.size() - 1] - 1);
        // cout << ans << endl;
        for (int i = 0; i < x_pos.size() - 1; i++) {
            int mid = (x_pos[i + 1] + x_pos[i]) / 2;
            // cout << "->" << mid << endl;
            ans = max(ans, min(x_pos[i + 1] - mid - 1, mid - x_pos[i] - 1));
        }
        cout << ans << endl;
    }
}

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int s, a, f;
        cin >> s >> a >> f;
        vector<int> frands_x(f), frands_y(f);
        for (int i = 0; i < f; i++) {
            cin >> frands_x[i] >> frands_y[i];
        }
        sort(frands_x.begin(), frands_x.end());
        sort(frands_y.begin(), frands_y.end());
        auto mid = (f - 1) / 2;
        cout << "(Street: " << frands_x[mid] << ", Avenue: " << frands_y[mid]
             << ")\n";
    }
}

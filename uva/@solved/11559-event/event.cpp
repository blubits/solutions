#include <iostream>

using namespace std;

int main() {
    int n, b, h, w;
    while (cin >> n >> b >> h >> w) {
        int ans = 1000000000;
        for (int i = 0; i < h; i++) {
            int cost, min_bed = 0;
            cin >> cost;
            for (int j = 0; j < w; j++) {
                int bed;
                cin >> bed;
                min_bed = max(bed, min_bed);
            }
            if (min_bed >= n && (n * cost) <= b) {
                ans = min(ans, n * cost);
            }
        }
        if (ans != 1000000000)
            cout << ans;
        else
            cout << "stay home";
        cout << endl;
    }
}

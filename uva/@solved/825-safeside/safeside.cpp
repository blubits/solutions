#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int w, n;
set<ii> unsafe;
map<ii, int> num_paths;

int main() {
    int T;
    cin >> T;
    while (T--) {
        unsafe.clear();
        num_paths.clear();
        cin >> w >> n;
        cin.ignore();
        for (int i = 0; i < w; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            int a, b;
            ss >> a;
            while (ss >> b) {
                unsafe.emplace(a - 1, b - 1);
            }
        }
        num_paths[{0, 0}] = 1;
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < n; j++) {
                if (unsafe.count({i, j}) == 1) continue;
                if (i != w - 1 && unsafe.count({i + 1, j}) == 0) num_paths[{i + 1, j}] += num_paths[{i, j}];
                if (j != n - 1 && unsafe.count({i, j + 1}) == 0) num_paths[{i, j + 1}] += num_paths[{i, j}];
            }
        }
        cout << num_paths[{w - 1, n - 1}] << endl;
        if (T) cout << endl;
    }
    return 0;
}
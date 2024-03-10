#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

vector<double> radii;

int main() {
    int t;
    while (cin >> t) {
        if (t == 0) break;
        radii.clear();
        radii.resize(t);
        for (int i = 0; i < t; i++) cin >> radii[i];
        sort(radii.begin(), radii.end());
        double sum = 0, p = 0;
        bool possible = false;
        for (int i = 0; i < t; i++) {
            sum += radii[i];
            if (radii[i] * 2 <= sum) possible = true;
        }
        if (possible) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}
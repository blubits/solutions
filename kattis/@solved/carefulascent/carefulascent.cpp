#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int x, y;
int n;
vector<tuple<int, int, float>> shields;

int main() {
    cin >> x >> y >> n;
    for (int i = 0; i < n; i++) {
        int l, u;
        double f;
        cin >> l >> u >> f;
        shields.push_back({l, u, f});
    }
    sort(shields.begin(), shields.end());
    double altitude = 0, distance = 0;
    for (auto &[l, u, f]: shields) {
        distance += l - altitude;       // += 1 * (curr_lower - curr_alt)
        altitude = u;
        distance += (u - l) * f;
    }
    distance += y - altitude;
    cout << fixed << setprecision(11);
    cout << x / distance << endl;
    return 0;
}
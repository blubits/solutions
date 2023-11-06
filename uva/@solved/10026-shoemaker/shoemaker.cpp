#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

vector<tuple<int, int, int>> jobs;

bool comp(const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
    double aratio = double(get<1>(a)) / double(get<0>(a));
    double bratio = double(get<1>(b)) / double(get<0>(b));
    return aratio > bratio; 
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        jobs.clear();
        for (int i = 1; i <= N; i++) {
            int a, b;
            cin >> a >> b;
            jobs.push_back({a, b, i});
        }
        stable_sort(jobs.begin(), jobs.end(), comp);
        int posn = 0;
        for (auto &[a, b, i]: jobs) {
            if (posn++ != 0) cout << " ";
            cout << i;
        }
        cout << endl;
        if (T) cout << endl;
    }
    return 0;
}
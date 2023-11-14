#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

vi goes_to;
vi percent;
vi has_superpower;

int main() {
    int N;
    cin >> N;
    goes_to.assign(N, 0);
    percent.assign(N, 0);
    has_superpower.assign(N, 0);
    goes_to[0] = 0; 
    for (int i = 0; i < N - 1; i++) {
        int a, b, per, sup;
        cin >> a >> b >> per >> sup;
        a--; b--;
        goes_to[b] = a;
        percent[b] = per;
        has_superpower[b] = sup;
    }
    double max_flow = 0;
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        if (k == -1) continue;
        int curr_node = i;
        double curr_val = k;
        while (curr_node != 0) {
            if (has_superpower[curr_node]) curr_val = sqrt(curr_val);
            curr_val *= (100.0 / percent[curr_node]);
            curr_node = goes_to[curr_node];
        }
        max_flow = max(max_flow, curr_val);
    }
    cout << fixed << setprecision(10) << max_flow << endl;
}
#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & (-S))

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const int NINF = 0xcfcfcfcf;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;

int main() {
    int hh, mm, H, D, C, N;
    cin >> hh >> mm >> H >> D >> C >> N;
    int minutes_to_8pm = abs(1200 - (hh * 60 + mm));
    cout << fixed << setprecision(4);
    if (hh >= 20) {
        cout << (C * .80) * ceil(double(H) / N);
    } else {
        double buy_now = C * ceil(double(H) / N);
        double buy_later = (C * .80) * ceil((double(H) + D * minutes_to_8pm) / N);
        cout << min(buy_now, buy_later);
    }
    cout << endl;
    return 0;
}
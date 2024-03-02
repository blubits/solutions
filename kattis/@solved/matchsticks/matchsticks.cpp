#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        // smallest
        switch (x) {
            case 2: cout << 1; break;
            case 3: cout << 7; break;
            case 4: cout << 4; break;
            case 5: cout << 2; break;
            case 6: cout << 6; break;
            case 7: cout << 8; break;
            case 8: cout << 10; break;
            case 9: cout << 18; break;
            case 10: cout << 22; break;
            case 11: cout << 20; break;
            case 12: cout << 28; break;
            case 13: cout << 68; break;
            case 14: cout << 88; break;
            default:
            {
                int idx = (x - 1) % 7;
                int no_of_eights = ((x - 1) / 7) - 2;
                switch (idx) {
                    case 0: cout << 108; break;
                    case 1: cout << 188; break;
                    case 2: cout << 200; break;
                    case 3: cout << 208; break;
                    case 4: cout << 288; break;
                    case 5: cout << 688; break;
                    case 6: cout << 888; break;
                }
                for (int i = 0; i < no_of_eights; i++) cout << 8;
                break;
            }
        }
        cout << " ";
        // biggest
        if (x % 2 == 0) cout << 1;
        else cout << 7;
        int no_of_ones = (x / 2) - 1;
        for (int i = 0; i < no_of_ones; i++) cout << 1;
        cout << endl;
    }
    return 0;
}
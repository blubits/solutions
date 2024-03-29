#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int h, w;
char s;
bool structure[100][100];

double dx = 0;
int x = 0;

int main() {
    cin >> h >> w;
    cin.ignore();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> s;
            if (s == '.') structure[i][j] = false;
            else {
                structure[i][j] = true;
                dx += j;
                x++;
            }
        }
        cin.ignore();
    }
    double cogx = dx / double(x);

    int lb, rb;
    for (int j = 0; j < w; j++) {
        if (structure[h - 1][j]) {
            lb = j;
            break;
        }
    }
    for (int j = w - 1; j >= 0; j--) {
        if (structure[h - 1][j]) {
            rb = j;
            break;
        }
    }

    // each tile's cog is always between it (not at an exact even number, but at 0.5)
    //
    // -#---#-
    // 0123456
    // lb: 0.5, rb: 5.5
    if (lb - 0.5 > cogx) {
        cout << "left";
    } else if (rb + 0.5 < cogx) {
        cout << "right";
    } else {
        cout << "balanced";
    }
    cout << endl;
    return 0;
}
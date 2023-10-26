#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

bool al1[26][26];
bool al2[26][26];

int main() {
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                al1[i][j] = al2[i][j] = false;
            }
        }
        int N;
        cin >> N;
        while (N--) {
            char a, b;
            cin >> a >> b;
            al1[int(a - 'A')][int(b - 'A')] = al1[int(b - 'A')][int(a - 'A')] = true;
        }
        int M;
        cin >> M;
        while (M--) {
            char a, b;
            cin >> a >> b;
            al2[int(a - 'A')][int(b - 'A')] = al2[int(b - 'A')][int(a - 'A')] = true;
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    al1[i][j] |= (al1[i][k] & al1[k][j]);
                    al2[i][j] |= (al2[i][k] & al2[k][j]);
                }
            }
        }
        bool equal = true;
        for (int i = 0; i < 26 && equal; i++) {
            for (int j = 0; j < 26 && equal; j++) {
                if (al1[i][j] != al2[i][j]) {
                    equal = false;
                }
            }
        }
        cout << (equal ? "YES" : "NO") << endl << endl;
    }
    return 0;
}
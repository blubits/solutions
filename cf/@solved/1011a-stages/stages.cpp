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
    int n, k;
    cin >> n >> k;
    vector<char> letters;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        letters.push_back(c);
    }
    sort(letters.begin(), letters.end());
    int ans = 0;
    int num_k = 0;
    char last_letter = letters[0];
    for (int i = 0; i < n && num_k < k; i++) {
        if (i == 0 || (letters[i] != last_letter + 1 && letters[i] != last_letter)) {
            ans += letters[i] - 'a' + 1;
            num_k++;
            last_letter = letters[i];
        }
    }
    if (num_k == k) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}
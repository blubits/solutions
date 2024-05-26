#include <bits/stdc++.h>
#define LSOne(S) ((S) & (-S))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const int NINF = 0xcfcfcfcf;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;

int dp[1 << 20];
int adj[26][26];
set<char> charuniq;
vector<int> characters;
int N;

int main() {
    string S;
    cin >> S;
    memset(adj, 0, sizeof(adj));
    for (auto c: S) {
        charuniq.insert(c);
    }
    N = charuniq.size();
    for (auto c: charuniq) {
        characters.push_back(c - 'a');
    }
    for (int i = 0; i < S.size() - 1; i++) {
        adj[S[i] - 'a'][S[i + 1] - 'a']++;
    }
    dp[0] = 1;
    for (int mask = 1; mask < (1 << N); mask++) {
        dp[mask] = S.size();
        int temp = mask;
        while (temp) {
            int two_pow_j = LSOne(temp);
            int j = __builtin_ctz(two_pow_j);
            int prev = mask ^ two_pow_j;
            int prev_temp = mask;
            int sum = dp[prev];
            while (prev_temp) {
                int two_pow_k = LSOne(prev_temp);
                int k = __builtin_ctz(two_pow_k);
                sum += adj[characters[j]][characters[k]];
                prev_temp -= two_pow_k;
            }
            dp[mask] = min(dp[mask], sum);
            temp -= two_pow_j;
        }
    }
    cout << dp[(1 << N) - 1] << endl;
    return 0;
}
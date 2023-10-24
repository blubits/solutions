#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

map<string, int> currencies;
double adj[250][250];

int main() {
    int N;
    while (cin >> N && N != 0) {
        memset(adj, 0, sizeof(adj));
        currencies.clear();
        for (int i = 0; i < N; i++) {
            string curr;
            cin >> curr;
            currencies[curr] = i;
            adj[i][i] = 1.0;
        }
        int R;
        cin >> R;
        while (R--) {
            string fr, to;
            int a, b;
            cin >> fr >> to >> a;
            cin.ignore(256, ':');    
            cin >> b;
            adj[currencies[fr]][currencies[to]] = double(b) / double(a);
        }
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    adj[i][j] = max(adj[i][j], adj[i][k] * adj[k][j]);
                }
            }
        }
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < N; j++) {
        //         printf("%.3f ", adj[i][j]);
        //     }
        //     printf("\n");
        // }
        bool arbitrage = false;
        for (int i = 0; i < N; i++) {
            if (adj[i][i] != 1.0) {
                arbitrage = true;
                break;
            } 
        }
        if (arbitrage) cout << "Arbitrage";
        else cout << "Ok";
        cout << endl;
    }
    return 0;
}
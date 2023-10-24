#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int adj_matrix[150][150];
vii distances;
int V;

int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(adj_matrix, sizeof(adj_matrix), 0);
        distances.clear();
        int N;
        cin >> N;
        V = N+2;
        for (int i = 0; i < V; i++) {
            int x, y;
            cin >> x >> y;
            distances.push_back({x, y});
        }
        for (int i = 0; i < V; i++) {
            for (int j = i; j < V; j++) {
                int dist = abs(distances[i].first - distances[j].first) + abs(distances[i].second - distances[j].second);
                if (dist <= 1000) {
                    adj_matrix[i][j] = 1;
                    adj_matrix[j][i] = 1;
                } else {
                    adj_matrix[i][j] = 0;
                    adj_matrix[j][i] = 0;
                }
            }
        }
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    adj_matrix[i][j] |= (adj_matrix[i][k] & adj_matrix[k][j]);
                }
            }
        }
        if (adj_matrix[0][V-1]) cout << "happy";
        else cout << "sad";
        cout << endl;
    }
    return 0;
}
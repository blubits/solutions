#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int num_tiles;
vector<int> tiles(40);
int num_choice, target;

long long int C[40][40];
// num_ways(k, i, V)
// number of ways to sum up k coins to V, not considering the ith coin
long long int num_ways[40][40][10010];

int count(int k, int i, int V) {
    cout << k << "," << i << "," << V << endl;
    if (k == 0 && V == 0) return 1;
    if (k == 0 && V != 0) return 0;
    if (k != 0 && V == 0) return 0;
    if (V < 0) return 0;
    if (i == num_tiles) return 0;
    long long int &ans = num_ways[k][i][V];
    if (ans != -1) return ans;
    return ans = count(k, i + 1, V) + count(k - 1, i + 1, V - tiles[i]);
}

int main() {
    int game = 1;
    for (int n = 1; n <= 30; n++) {
        for (int r = 0; r <= n; r++) {
            if (r == 0 || r == n) C[n][r] = 1;
            else C[n][r] = C[n-1][r] + C[n-1][r-1];
        }
    }
    int T;
    cin >> T;
    while (T--) {
        cin >> num_tiles;
        for (int i = 0; i < num_tiles; i++) cin >> tiles[i];
        cin >> num_choice >> target;
        for (int k = 0; k <= num_choice; k++) {
            for (int i = 0; i <= num_tiles; i++) {
                for (int v = 0; v <= target; v++) {
                    num_ways[k][i][v] = -1;
                }
            }
        }
        long long int ans = count(num_choice, 0, target);
        printf("Game %d -- %d : %d\n", game++, ans, C[num_tiles][num_choice] - ans);
    }
}
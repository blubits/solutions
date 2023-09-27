#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

#define INF 1000000000

using namespace std;

int coins[101];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, B;
        cin >> V >> B;
        for (int i = 0; i < B; i++) {
            cin >> coins[i];
        }
        
        // coin THEN position (think why)
        vector<int> ways(10001, INF);
        ways[0] = 0;
        for (int i = 0; i < B; i++) {
            for (int j = 10000 - coins[i]; j >= 0; j--) {
                ways[j + coins[i]] = min(ways[j + coins[i]], ways[j] + 1);
            }
        }

        for (int i = V; i <= 10000; i++) {
            if (ways[i] < INF / 2) {
                cout << i << " " << ways[i] << endl;
                break;
            }
        }

    }
    return 0;
}
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define MAX 10000000
using namespace std;

int main() {
    int n, h, l;
    cin >> n >> h >> l;

    vector<vector<int>> similarity(n + 1);

    while (h--) {
        int t;
        cin >> t;
        similarity[n].push_back(t);
        similarity[t].push_back(n);
    }

    while (l--) {
        int f, t;
        cin >> f >> t;
        similarity[f].push_back(t);
        similarity[t].push_back(f);
    }

    // bfs to check what to consider
    queue<int> bfs;
    vector<int> hi(n + 1, MAX);
    vector<bool> visited(n + 1, false);
    bfs.push(n);
    hi[n] = -1;
    while (!bfs.empty()) {
        // Pop off the top node
        int cn = bfs.front();
        bfs.pop();

        visited[cn] = true;

        for (auto nn : similarity[cn]) {
            if (!visited[nn]) bfs.push(nn);
            if (hi[nn] == MAX) hi[nn] = hi[cn] + 1;
        }
    }

    // for (auto c : hi) cout << c << " ";
    // cout << endl;

    int m = -1, mi = 0;
    for (int i = 0; i < n; i++) {
        if (hi[i] > m) {
            m = hi[i];
            mi = i;
        }
    }
    cout << mi << endl;
}

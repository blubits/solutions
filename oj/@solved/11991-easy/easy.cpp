#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj_list;

int main() {
    int n, m;
    while (cin >> n >> m) {
        adj_list.assign(1000000, vector<int>());
        int d;
        for (int i = 0; i < n; i++) {
            cin >> d;
            adj_list[d].push_back(i+1);
        }
        int k, v;
        while (m--) {
            cin >> k >> v;
            if (adj_list[v].size() >= k) {
                cout << adj_list[v][k - 1];
            } else {
                cout << 0;
            }
            cout << endl;
        }
    }
    return 0;
}

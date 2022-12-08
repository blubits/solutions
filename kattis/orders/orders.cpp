#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> menu;

int main() {
    int M;
    cin >> M;
    menu.resize(M);
    for (int i = 0; i < M; i++) cin >> menu[i];

    // calculate unbounded knapsack
    vector<int> knapsack(40000, -1);
    knapsack[0] = 0;
    for (int i = 0; i < M; i++) {
        int cost = menu[i];
        for (int j = 0; j <= 30000; j++) {
            if (knapsack[j] >= 0) {
                if (knapsack[j + cost] == -1) {
                    knapsack[j + cost] = i;
                } else {
                    knapsack[j + cost] = -2;
                }
            }
            if (knapsack[j] == -2) {
                knapsack[j + cost] = -2;
            }
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int val;
        cin >> val;
        vector<int> ans;
        if (knapsack[val] == -1) cout << "Impossible";
        else if (knapsack[val] == -2) cout << "Ambiguous";
        else {
            while (val > 0) {
                ans.push_back(knapsack[val] + 1);
                val -= menu[knapsack[val]];
            }
            sort(ans.begin(), ans.end());
            for (auto &i: ans) cout << i << " ";
        }
        cout << endl;
    }
}
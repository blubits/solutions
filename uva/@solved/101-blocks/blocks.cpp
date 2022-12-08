#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int k;
    cin >> k;
    vector<vector<int>> stacks(k);  // stacks
    int loc[k];                     // location of each block, stack-wise
    for (int i = 0; i < k; i++) {
        stacks[i].push_back(i);
        loc[i] = i;
    }
    string word;
    while (cin >> word && word != "quit") {
        int i, j;
        string word2;
        cin >> i >> word2 >> j;
        int li = loc[i], lj = loc[j];
        if (i == j) continue;
        if (li == lj) continue;
        if (word == "move" && word2 == "onto") {
            // Put block i onto block j after returning any blocks that are
            // stacked on top of blocks i and j to their initial positions.
            while (stacks[li].back() != i) {
                int k = stacks[li].back();
                stacks[li].pop_back();
                stacks[k].push_back(k);
                loc[k] = k;
            }
            while (stacks[lj].back() != j) {
                int k = stacks[lj].back();
                stacks[lj].pop_back();
                stacks[k].push_back(k);
                loc[k] = k;
            }
            stacks[li].pop_back();
            stacks[lj].push_back(i);
            loc[i] = lj;
        } else if (word == "move" && word2 == "over") {
            while (stacks[li].back() != i) {
                int k = stacks[li].back();
                stacks[li].pop_back();
                stacks[k].push_back(k);
                loc[k] = k;
            }
            stacks[li].pop_back();
            stacks[lj].push_back(i);
            loc[i] = lj;
        } else if (word == "pile" && word2 == "onto") {
            vector<int> pile;
            while (stacks[li].back() != i) {
                int k = stacks[li].back();
                stacks[li].pop_back();
                pile.push_back(k);
            }
            int k = stacks[li].back();
            stacks[li].pop_back();
            pile.push_back(k);
            while (stacks[lj].back() != j) {
                int k = stacks[lj].back();
                stacks[lj].pop_back();
                stacks[k].push_back(k);
                loc[k] = k;
            }
            while (!pile.empty()) {
                int k = pile.back();
                pile.pop_back();
                stacks[lj].push_back(k);
                loc[k] = lj;
            }
        } else if (word == "pile" && word2 == "over") {
            vector<int> pile;
            while (stacks[li].back() != i) {
                int k = stacks[li].back();
                stacks[li].pop_back();
                pile.push_back(k);
            }
            int k = stacks[li].back();
            stacks[li].pop_back();
            pile.push_back(k);
            while (!pile.empty()) {
                int k = pile.back();
                pile.pop_back();
                stacks[lj].push_back(k);
                loc[k] = lj;
            }
        }
        // cout << word << " " << word2 << i << "-> " << loc[i] << ", " << j
        //      << "-> " << loc[j] << endl;
        // for (int i = 0; i < k; i++) {
        //     cout << i << ":";
        //     for (auto j : stacks[i]) {
        //         cout << " " << j;
        //     }
        //     cout << endl;
        // }
    }
    for (int i = 0; i < k; i++) {
        cout << i << ":";
        for (auto j : stacks[i]) {
            cout << " " << j;
        }
        cout << endl;
    }
    return 0;
}

#include <iostream>
#include <set>
#include <string>

using namespace std;

int keypad[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};

string curr;
set<int> possible;

void search(int i, int j) {
    if (curr.size() > 4 || keypad[i][j] == -1 ||
        !(0 <= i && i < 4 && 0 <= j && j < 3)) {
        if (curr.size() != 0) possible.insert(stoi(curr));
        return;
    }
    // exclude
    // - move down
    search(i + 1, j);
    // - move right
    search(i, j + 1);
    // include
    curr.push_back(char('0' + keypad[i][j]));
    // - stay
    search(i, j);
    // - move down
    search(i + 1, j);
    // - move right
    search(i, j + 1);
    curr.pop_back();
}

int main() {
    search(0, 0);
    int t;
    cin >> t;
    // for (auto i : possible) {
    //     if (i > 200) break;
    //     cout << i << endl;
    // }
    while (t--) {
        int k, bef = 0;
        cin >> k;
        for (auto i : possible) {
            if (i < k) {
                bef = i;
            } else if (i == k) {
                cout << k << endl;
                break;
            } else if (i > k) {
                if (k - bef < i - k) {
                    cout << bef << endl;
                } else {
                    cout << i << endl;
                }
                break;
            }
        }
    }
}

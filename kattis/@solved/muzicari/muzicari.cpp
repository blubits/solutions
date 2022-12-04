#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int solution[510][5010];
bool mark[510][5010];

int main() {
    int t, n;
    cin >> t >> n;
    memset(mark, false, sizeof(mark));
    int brk[n];
    for (int i = 0; i < n; i++) {
        cin >> brk[i];
    }
    for (int j = 0; j <= t; j++) {
        solution[0][j] = -j;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= t; j++) {
            // SOL[i][j] =
            // if (you can take a break before the concert ends)
            if (brk[i - 1] <= j &&
                solution[i - 1][j] - 1 < solution[i - 1][j - brk[i - 1]]) {
                solution[i][j] = solution[i - 1][j - brk[i - 1]];
                mark[i][j] = true;
            } else {
                solution[i][j] = solution[i - 1][j] - 1;
            }
        }
    }
    vector<int> belong(n, 0);
    int nn = n, tt = t;
    while (nn && tt) {
        if (mark[nn][tt]) {
            belong[nn - 1] = 1;
            tt -= brk[nn - 1];
        }
        nn--;
    }
    int one = 0, two = 0;
    for (int i = 0; i < n; i++) {
        if (belong[i] == 1) {
            cout << one;
            one += brk[i];
        } else {
            cout << two;
            two += brk[i];
        }
        cout << " ";
    }
    cout << endl;
}

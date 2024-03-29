#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int n, k;
char board[5][5];
bool state[5][5];
int ships[5];

int sol = 0;

void backtrack(int ship_no) {
    if (ship_no == k) {
        bool valid = true;
        // check if any hit cell does not have a boat
        for (int i = 0; i < n && valid; i++) {
            for (int j = 0; j < n && valid; j++) {
                if (board[i][j] == 'O' && !state[i][j]) {
                    valid = false;
                }
            }
        }
        if (valid) sol++;
        return;
    }
    int ship_length = ships[ship_no];
    // for each cell...
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // place horizontally
            if (j + ship_length <= n) {
                bool can_place = true;
                for (int d = 0; d < ship_length; d++) {
                    if (board[i][j + d] == 'X' || state[i][j + d]) {
                        // either cell cannot be placed (1)
                        // or there is already a ship there
                        can_place = false;
                        break;
                    }
                }
                if (can_place) {
                    for (int d = 0; d < ship_length; d++) state[i][j + d] = true;
                    backtrack(ship_no + 1);
                    for (int d = 0; d < ship_length; d++) state[i][j + d] = false;
                }
            }
            // place vertically; skip if single-length
            if (ship_length != 1 && i + ship_length <= n) {
                bool can_place = true;
                for (int d = 0; d < ship_length; d++) {
                    if (board[i + d][j] == 'X' || state[i + d][j]) {
                        // either cell cannot be placed (1)
                        // or there is already a ship there
                        can_place = false;
                        break;
                    }
                }
                if (can_place) {
                    for (int d = 0; d < ship_length; d++) state[i + d][j] = true;
                    backtrack(ship_no + 1);
                    for (int d = 0; d < ship_length; d++) state[i + d][j] = false;
                }
            }
        }
    }
}

int main() {
    cin >> n >> k;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
        cin.ignore();
    }
    for (int i = 0; i < k; i++) cin >> ships[i];
    memset(state, 0, sizeof(state));
    backtrack(0);
    cout << sol << endl;
    return 0;
}
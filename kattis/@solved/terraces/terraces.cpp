#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int board[501][501];
bool visited[501][501];
bool sink = true;
int sz = 0;
int x, y;

int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, -1, 1};

void floodfill(int i, int j) {
    if (visited[i][j]) return;
    visited[i][j] = true;
    sz++;
    for (int d = 0; d < 4; d++) {
        int ni = i + dirx[d], nj = j + diry[d];
        if (ni < 0 || ni >= x || nj < 0 || nj >= y) continue;
        if (board[ni][nj] < board[i][j]){
            sink = false;
        }
        if (board[ni][nj] == board[i][j]){
            floodfill(ni, nj);
        }
    }
}

int main() {
    cin >> y >> x;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> board[i][j];
        }
    }
    int ct = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (visited[i][j]) continue;
            sink = true;
            sz = 0;
            floodfill(i, j);
            if (sink) ct += sz;
        }
    }
    cout << ct << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int N, M, S;
int stickers;
char grid[110][110];
char instructions[50010];
int si, sj, sdir;

int dir[4] = {0, 1, 2, 3};
const int NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int i, int j, int dir, int idx) {
    if (idx == S) return;
    // read instruction
    if (instructions[idx] == 'D') {
        dfs(i, j, (dir + 1) % 4, idx + 1);
    } else if (instructions[idx] == 'E') {
        dfs(i, j, (dir + 3) % 4, idx + 1);
    } else if (instructions[idx] == 'F') {
        // attempt to move forward
        int ni = i + dx[dir], nj = j + dy[dir];
        if (!(0 <= ni && ni < N && 0 <= nj && nj < M))
            dfs(i, j, dir, idx + 1);
        else if (grid[ni][nj] == '#')
            dfs(i, j, dir, idx + 1);
        else {
            if (grid[ni][nj] == '*') {
                stickers++;
                grid[ni][nj] = '.';
            }
            dfs(ni, nj, dir, idx + 1);
        }
    }
}

int main() {
    while (cin >> N >> M >> S && (N + M + S != 0)) {
        stickers = 0;
        cin.ignore();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'N' || grid[i][j] == 'S' ||
                    grid[i][j] == 'L' || grid[i][j] == 'O') {
                    si = i;
                    sj = j;
                    switch (grid[i][j]) {
                        case 'N':
                            sdir = NORTH; break;
                        case 'S':
                            sdir = SOUTH; break;
                        case 'L':
                            sdir = EAST; break;
                        case 'O':
                            sdir = WEST; break;
                    }
                }
            }
            cin.ignore();
        }
        for (int i = 0; i < S; i++) {
            cin >> instructions[i];
        }
        dfs(si, sj, sdir, 0);
        cout << stickers << endl;
    }
    return 0;
}
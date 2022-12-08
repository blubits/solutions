#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int solutions = 0;
vector<pair<int, int>> holes;
vector<pair<int, int>> queen_positions;

bool is_valid(int i, int j) {
    for (auto h : holes) {
        if (h.first == i && h.second == j) return false;
    }
    for (auto q : queen_positions) {
        if (q.first == i || q.second == j ||
            abs(q.first - i) == abs(q.second - j))
            return false;
    }
    return true;
}

void solve_n_queens(int r) {
    if (r == N) {
        solutions++;
        return;
    }
    for (int j = 0; j < N; j++) {
        if (is_valid(r, j)) {
            queen_positions.push_back({r, j});
            solve_n_queens(r + 1);
            queen_positions.pop_back();
        }
    }
    return;
}

int main() {
    int h;
    while (cin >> N >> h && !(N == 0 && h == 0)) {
        holes.clear();
        queen_positions.clear();
        solutions = 0;
        while (h--) {
            int i, j;
            cin >> i >> j;
            holes.push_back({i, j});
        }
        solve_n_queens(0);
        cout << solutions << endl;
    }
}

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int paths[30][30];
    int visited[30][30];
    bool is_grave[30][30];
    bool is_hole[30][30];
    int hole_coor[30][30][3];
    while (1) {
        int W, H;
        cin >> W >> H;
        if (W == 0 && H == 0) return 0;

        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                paths[i][j] = 0;
                visited[i][j] = 0;
                is_grave[i][j] = false;
                is_hole[i][j] = false;
                hole_coor[i][j][0] = -1;  // x-coor of dest
                hole_coor[i][j][1] = -1;  // y-coor of dest
                hole_coor[i][j][2] = 0;   // net distance
            }
        }
        int G;
        cin >> G;
        while (G--) {
            int ig, jg;
            cin >> ig >> jg;
            is_grave[jg][ig] = true;
        }
        int X;
        cin >> X;
        while (X--) {
            int is, js, id, jd, t;
            cin >> is >> js >> id >> jd >> t;
            is_hole[js][is] = true;
            hole_coor[js][is][0] = jd;
            hole_coor[js][is][1] = id;
            hole_coor[js][is][2] = t;
        }
        // modified BFS
        queue<pair<int, int>> to_visit;
        auto p = make_pair(0, 0);
        bool at_end = false;
        to_visit.push(p);
        while (to_visit.size() != 0) {
            auto x = to_visit.front();
            to_visit.pop();
            auto jx = x.first, ix = x.second;
            cout << jx << " " << ix << endl;
            if (ix == W - 1 and jx == H - 1) {
                at_end = true;
                cout << paths[jx][ix] << endl;
                break;
            }
            // } else if (visited[ix][jx] == 2) {
            //     at_end = true;
            //     cout << "Never" << endl;
            //     break;
            // }
            visited[ix][jx] = 2;
            // haunted hole
            if (is_hole[ix][jx]) {
                cout << "hole" << endl;
                auto id = hole_coor[ix][jx][0];
                auto jd = hole_coor[ix][jx][1];
                auto t = hole_coor[ix][jx][2];
                paths[id][jd] = paths[ix][jx] + t;
                visited[id][jd] = 1;
                auto p = make_pair(id, jd);
                to_visit.push(p);
                continue;
            }
            // N
            if (ix + 1 < W && !visited[ix + 1][jx] && !is_grave[ix + 1][jx]) {
                paths[ix + 1][jx] = paths[ix][jx] + 1;
                visited[ix + 1][jx] = 1;
                auto p = make_pair(ix + 1, jx);
                to_visit.push(p);
            }
            // S
            if (ix - 1 > 0 && !visited[ix - 1][jx] && !is_grave[ix - 1][jx]) {
                paths[ix - 1][jx] = paths[ix][jx] + 1;
                visited[ix - 1][jx] = 1;
                auto p = make_pair(ix - 1, jx);
                to_visit.push(p);
            }
            // E
            if (jx - 1 > 0 && !visited[ix][jx - 1] && !is_grave[ix][jx - 1]) {
                paths[ix][jx - 1] = paths[ix][jx] + 1;
                visited[ix][jx - 1] = 1;
                auto p = make_pair(ix, jx - 1);
                to_visit.push(p);
            }
            // W
            if (jx + 1 < H && !visited[ix][jx + 1] && !is_grave[ix][jx + 1]) {
                paths[ix][jx + 1] = paths[ix][jx] + 1;
                visited[ix][jx + 1] = 1;
                auto p = make_pair(ix, jx + 1);
                to_visit.push(p);
            }
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    cout << paths[i][j] << " ";
                }
                cout << endl;
            }
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cout << paths[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cout << is_hole[i][j] << " ";
            }
            cout << endl;
        }
        if (!at_end) cout << "Impossible" << endl;
    }
}

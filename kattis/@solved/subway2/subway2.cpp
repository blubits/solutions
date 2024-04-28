#include <bits/stdc++.h>
#define LSOne(S) ((S) & (-S))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const int NINF = 0xcfcfcfcf;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;

const int HOME = 0, SCHOOL = 1;
int SUBWAY_LINE_CTR = 0;
int N;

vector<ii> coordinates;
vector<vi> subway_lines;
vector<int> subway_line_idx;

double adj_matrix[210][210];

double dist(ii a, ii b) {
    return hypot(a.second - b.second, a.first - b.first);
}

double sp() {
    int SRC = 0, DEST = 1;
    vector<double> dist(N, 1e9);
    dist[SRC] = 0;
    set<pair<double, int>> pq;
    for (int i = 0; i < N; i++) pq.emplace(dist[i], i);
    while (!pq.empty()) {
        auto [d, u] = *pq.begin();
        //cout << u << " " << d << endl;
        pq.erase(pq.begin());
        for (int v = 0; v < N; v++) {
            //cout << u << " " << v << " " << dist[u] + adj_matrix[u][v] << " " << dist[v] << endl;
            if (dist[u] + adj_matrix[u][v] >= dist[v]) continue;
            pq.erase(pq.find({dist[v], v}));
            dist[v] = dist[u] + adj_matrix[u][v];
            pq.emplace(dist[v], v);
        }
    }
    return round(dist[DEST]);
}

int main() {
    int hx, hy, sx, sy;
    cin >> hx >> hy >> sx >> sy;
    coordinates.push_back({hx, hy});
    coordinates.push_back({sx, sy});
    subway_line_idx.push_back(-1);
    subway_line_idx.push_back(-1);
    int tx, ty;
    subway_lines.push_back(vi());
    while (cin >> tx >> ty) {
        if (tx == -1 && ty == -1) {
            SUBWAY_LINE_CTR++;
            subway_lines.push_back(vi());
            continue;
        }
        subway_lines[SUBWAY_LINE_CTR].push_back(coordinates.size());
        coordinates.push_back({tx, ty});
        subway_line_idx.push_back(SUBWAY_LINE_CTR);
    }
    N = coordinates.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                adj_matrix[i][j] = 0; continue;
            }
            if ((i + j != 1) && abs(j - i) == 1 && subway_line_idx[j] == subway_line_idx[i]) {
                    //cout << i << " " << j << ": subway connection" << endl;
                    // subway connection
                    adj_matrix[i][j] = dist(coordinates[i], coordinates[j]) / (40.0 * 1000 / 60);
                } else {
                    // walking connection
                    adj_matrix[i][j] = dist(coordinates[i], coordinates[j]) / (10.0 * 1000 / 60);
                }
        }
    }
    cout << fixed << setprecision(0) << sp() << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int V, E;
double adj[150][150];
double newadj[150][150];
double dist[150][150];
bool has_edge[150][150];
vii intersections;

double distance(ii a, ii b) {
    return hypot(double(b.first - a.first), double(b.second - a.second));
}

int main() {
    int V;
    cout << fixed;
    cout.precision(8);
    while (cin >> V && V != 0) {
        fill_n(&adj[0][0], 150*150, 1e8);
        memset(has_edge, false, sizeof(has_edge));
        intersections.clear();
        for (int i = 0; i < V; i++) {
            int a, b;
            cin >> a >> b;
            intersections.push_back({a, b});
            adj[i][i] = 0;
        }
        int E;
        cin >> E;
        for (int i = 0; i < E; i++) {
            int a, b;
            cin >> a >> b;
            double dist = distance(intersections[a], intersections[b]);
            adj[a][b] = adj[b][a] = dist;
            has_edge[a][b] = has_edge[b][a] = true;
        }
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        double basemin = 0;
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                basemin += adj[i][j];
            }
        }
        double actmin = INF;
        int imin = 0, jmin = 0;
        // for (int i = 0; i < V; i++) {
        //     for (int j = 0; j < V; j++) {
        //         cout << adj[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for (int i = 0; i < V; i++) {
            for (int j = i+1; j < V; j++) {
                if (!has_edge[i][j]) {
                    for (int i = 0; i < V; i++) {
                        for (int j = 0; j < V; j++) {
                            newadj[i][j] = adj[i][j];
                        }
                    }
                    newadj[i][j] = distance(intersections[i], intersections[j]);
                    newadj[j][i] = distance(intersections[j], intersections[i]);
                    for (int k = 0; k < V; k++) {
                        for (int l = 0; l < V; l++) {
                            newadj[k][l] = min(newadj[k][l], newadj[k][i] + newadj[i][j] + newadj[j][l]);
                            newadj[k][l] = min(newadj[k][l], newadj[k][j] + newadj[j][i] + newadj[i][l]);
                        }
                    }
                    double currmin = 0;
                    for (int k = 0; k < V; k++) {
                        for (int l = k + 1; l < V; l++) {
                            currmin += newadj[k][l];
                        }
                    }
                    if (actmin - currmin > EPS) {
                        actmin = currmin;
                        imin = i;
                        jmin = j;
                        // cout << i << " " << j << " " << distance(intersections[i], intersections[j]) << " " << currmin << endl;
                        // for (int i = 0; i < V; i++) {
                        //     for (int j = 0; j < V; j++) {
                        //         cout << newadj[i][j] << " ";
                        //     }
                        //     cout << endl;
                        // }
                    }
                }
            }
        }
        if (basemin - actmin < EPS) {
            cout << "no addition reduces " << basemin << endl;
        } else {
            cout << "adding " << imin << " " << jmin;
            cout << " reduces " << basemin << " to " << actmin << endl;
        }
    }
    return 0;
}
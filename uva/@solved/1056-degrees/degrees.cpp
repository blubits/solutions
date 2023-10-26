#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

set<string> names;
map<string, int> mapping;
vector<pair<string, string>> connections;

int graph[60][60];

int main() {
    int P, R, T = 1;
    while (cin >> P >> R && !(P == 0 && R == 0)) {
        names.clear();
        mapping.clear();
        connections.clear();
        for (int i = 0; i < P; i++) {
            for (int j = 0; j < P; j++) {
                graph[i][j] = INF;
            }
        }
        for (int i = 0; i < R; i++) {
            string a, b;
            cin >> a >> b;
            names.emplace(a);
            names.emplace(b);
            connections.emplace_back(a, b);
        }
        int i = 0;
        for (auto name: names) {
            mapping[name] = i++;
        }
        for (auto &[fr, to]: connections) {
            graph[mapping[fr]][mapping[to]] = graph[mapping[to]][mapping[fr]] = 1;
        }
        for (int k = 0; k < P; k++) {
            for (int i = 0; i < P; i++) {
                for (int j = 0; j < P; j++) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
        int degrees_of_separation = 0;
        for (int i = 0; i < P; i++) {
            for (int j = i + 1; j < P; j++) {
                degrees_of_separation = max(degrees_of_separation, graph[i][j]);
            }
        }
        cout << "Network " << T++ << ": ";
        if (degrees_of_separation == INF) {
            cout << "DISCONNECTED";
        } else {
            cout << degrees_of_separation;
        }
        cout << endl << endl;
    }
    return 0;
}
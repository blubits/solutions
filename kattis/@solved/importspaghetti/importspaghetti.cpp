#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int adj[510][510];
int parent[510][510];
map<string, int> files;
vector<string> itofiles;

int main() {
    int V;
    cin >> V;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = INF;
            parent[i][j] = i;
        }
    }
    for (int i = 0; i < V; i++) {
        string file;
        cin >> file;
        files[file] = i;
        itofiles.push_back(file);
    }
    for (int i = 0; i < V; i++) {
        string file;
        int lines;
        cin >> file >> lines;
        int u = files[file];
        cin.ignore();
        for (int l = 0; l < lines; l++) {
            string line;
            getline(cin, line);
            line = line.substr(7);
            stringstream ss(line);
            string item;
            while (getline(ss, item, ',')) {
                if (item[0] == ' ') item = item.substr(1);
                int v = files[item];
                adj[u][v] = 1;
            }
        }
    }  
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][k] + adj[k][j] < adj[i][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }
    int min_cycle = INF, min_cycle_file = -1;
    for (int i = 0; i < V; i++) {
        if (adj[i][i] != 0 && adj[i][i] < min_cycle) {
            min_cycle = adj[i][i];
            min_cycle_file = i;
        }
    }
    if (min_cycle_file == -1) {
        cout << "SHIP IT";
    } else {
        stack<string> path;
        int j = parent[min_cycle_file][min_cycle_file];
        while (j != min_cycle_file) {
            path.push(itofiles[j]);
            j = parent[min_cycle_file][j];
        }
        path.push(itofiles[j]);
        while (!path.empty()) {
            cout << path.top();
            path.pop();
            if (!path.empty()) cout << " ";
        }
    }
    cout << endl;
    return 0;
}
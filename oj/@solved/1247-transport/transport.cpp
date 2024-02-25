#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int graph[26][26];
int num_edges[26][26];
int parent[26][26];

int main() {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            graph[i][j] = INF;
            num_edges[i][j] = INF;
            parent[i][j] = i;
        }
    }
    int s, p;
    cin >> s >> p;
    while (p--) {
        char i, j;
        int d;
        cin >> i >> j >> d;
        graph[int(i - 'A')][int(j - 'A')] = graph[int(j - 'A')][int(i - 'A')] = d;
        num_edges[int(i - 'A')][int(j - 'A')] = num_edges[int(j - 'A')][int(i - 'A')] = 1;
    }
    for (int k = 0; k < s; k++) {
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    num_edges[i][j] = num_edges[i][k] + num_edges[k][j];
                    parent[i][j] = parent[k][j];
                } else if (graph[i][j] == graph[i][k] + graph[i][j]) {
                    if (num_edges[i][j] > num_edges[i][k] + num_edges[k][j]) {
                        num_edges[i][j] = num_edges[i][k] + num_edges[k][j];
                        parent[i][j] = parent[k][j];
                    }
                }
            }
        }
    }
    int n;
    cin >> n;
    while (n--) {
        char a, b;
        cin >> a >> b;
        int i = a - 'A', j = b - 'A';
        int curr = j;
        stack<int> path;
        path.push(j);
        while (curr != i) {
            curr = parent[i][curr];
            path.push(curr);
        }
        while (!path.empty()) {
            cout << char('A' + path.top());
            path.pop();
            if (!path.empty()) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
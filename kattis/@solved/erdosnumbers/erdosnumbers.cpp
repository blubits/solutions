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

map<string, int> label;
vector<int> erdos_number;
vector<string> firsts;
vector<vector<int>> graph;
int label_idx = 0;
int erdos_idx = 0;

int get_label(string &name) {
    if (label.count(name) == 0) {
        label[name] = label_idx++;
    }
    return label[name];
}

void get_erdos() {
    queue<ii> q;
    q.push({0, erdos_idx});
    while (!q.empty()) {
        auto &[w, v] = q.front(); q.pop();
        if (erdos_number[v] != NINF) continue;
        erdos_number[v] = w;
        for (auto n : graph[v]) {
            q.push({w + 1, n});
        }
    }
}

int main() {
    string line;
    graph.resize(10001);
    erdos_number.resize(10001);
    while (getline(cin, line)) {
        stringstream ss(line);
        string name, coauthor;
        ss >> name;
        firsts.push_back(name);
        int name_idx = get_label(name);
        if (name == "PAUL_ERDOS") erdos_idx = name_idx;
        erdos_number[name_idx] = NINF;
        while (ss >> coauthor) {
            int coauthor_idx = get_label(coauthor);
            erdos_number[coauthor_idx] = NINF;
            graph[name_idx].push_back(coauthor_idx);
            graph[coauthor_idx].push_back(name_idx);
        }
    }
    get_erdos();
    for (auto &name : firsts) {
        cout << name << " ";
        if (erdos_number[label[name]] == NINF) {
            cout << "no-connection";
        } else {
            cout << erdos_number[label[name]];
        }
        cout << endl;
    }
    return 0;
}
    #include <bits/stdc++.h>
    using namespace std;

    #define INF 1e9

    typedef long long int ll;
    typedef pair<int, int> ii;
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    typedef vector<ii> vii;

    vector<vi> graph;
    vi ts;
    queue<int> tsq;
    vi indegree;
    vi dist;
    vi len;

    void toposort() {
        while (!tsq.empty()) {
            int v = tsq.front();
            ts.push_back(v);
            tsq.pop();
            for (auto w: graph[v]) {
                indegree[w]--;
                if (indegree[w] == 0) {
                    tsq.emplace(w);
                }
            }
        }
        // for (auto c: ts) {
        //     cout << char('A' + c) << " ";
        // }
        // cout << endl;
    }

    void longest_path() {
        int a = 0;
        for (auto u: ts) {
            for (auto v: graph[u]) {
                if (dist[v] < dist[u] + len[u]) {
                    dist[v] = dist[u] + len[u];
                }
            }
            cout << char('A' + u) << " " << dist[u] + len[u] << endl;
        }
        for (int i = 0; i < 26; i++) {
            a = max(a, dist[i] + len[i]);
        }
        //cout << a << endl;
    }

    int main() {
        int T;
        cin >> T;
        cin.ignore();
        cin.ignore();
        for (int i = 0; i < T; i++) {
            string line;
            graph.clear();
            graph.resize(26);
            indegree.clear();
            indegree.resize(26);
            dist.clear();
            dist.resize(26);
            ts.clear();
            len.clear();
            len.resize(26);
            while (getline(cin, line) && !line.empty()) {
                stringstream strin(line);
                char vertex;
                int length;
                string pred;
                strin >> vertex >> length;
                if (strin.peek() != -1) {
                    strin >> pred;
                } else {
                    tsq.emplace(int(vertex - 'A'));
                }
                len[int(vertex - 'A')] = length;
                indegree[int(vertex - 'A')] = pred.size();
                for (char c: pred) {
                    graph[int(c - 'A')].push_back(int(vertex - 'A'));
                }
                //cout << vertex << length << pred << endl;
            }
            if (i != 0) cout << endl;
            toposort();
            longest_path();
        }
        return 0;
    }
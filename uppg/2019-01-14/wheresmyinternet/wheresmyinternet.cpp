#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    /**
     * input code
     */
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    while (m--) {
        int fr, to;
        cin >> fr >> to;
        graph[fr - 1].push_back(to - 1);
        graph[to - 1].push_back(fr - 1);
    }

    // Recall: The problem states that house 1 is connected to
    // the internet. Therefore, all houses directly connected
    // to house 1 are also directed to the internet.
    //
    // We use graph search to check which nodes are connected
    // to a certain node. Graph search (DFS/BFS) is the most
    // basic technique to check for graph connectivity in
    // undirected graphs (iba ang terminology sa directed graphs lmao)

    // We keep track of all the nodes we visited in this array
    bool visited[n];
    for (int i = 0; i < n; i++) visited[i] = false;

    // This queue will help us keep track of what nodes we've visited
    // Narealize ko lang na BFS pala dapat to, pero ignore HAHA
    // Graph search, BFS or DFS, will work here naman
    queue<int> dfs;

    // We first visit the source: 0, where the Internet is connected.
    dfs.push(0);

    // This is the main loop for graph search

    // While there are no nodes left to visit...
    while (!dfs.empty()) {
        // Pop off the top node
        int cn = dfs.front();
        dfs.pop();

        // We've visited it
        visited[cn] = true;

        // Mark all the next nodes as to-visit
        for (auto nn : graph[cn]) {
            if (!visited[nn]) dfs.push(nn);
        }
    }

    // By the end of it, you should have visited all nodes
    // that can be reached from house 0.
    // All nodes marked "false" cannot be reached from house 0,
    // and are not connected to the internet.
    bool all_visited = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << i + 1 << endl;
            all_visited = false;
        }
    }
    if (all_visited) cout << "Connected" << endl;
    return 0;
}

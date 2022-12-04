#include <cstdio>

using namespace std;

int path[9] = {-1};

int graph[5][5] = {{0, 1, 1, 0, 1},
                   {1, 0, 1, 0, 1},
                   {1, 1, 0, 1, 1},
                   {0, 0, 1, 0, 1},
                   {1, 1, 1, 1, 0}};

void dfs(int curr, int depth) {
    path[depth] = curr;
    if (depth == 8) {
        for (int i = 0; i < 9; i++) printf("%d", path[i] + 1);
        printf("\n");
        return;
    }
    for (int next = 0; next < 5; next++) {
        if (graph[curr][next] == 1 && graph[next][curr] == 1) {
            // temporarily remove edge
            graph[curr][next] = 0;
            graph[next][curr] = 0;
            dfs(next, depth + 1);
            graph[curr][next] = 1;
            graph[next][curr] = 1;
        }
    }
}

int main() {
    dfs(0, 0);
    return 0;
}

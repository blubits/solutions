#include <iostream>

using namespace std;

int main() {
    int t;
    while (cin >> t && t != -1) {
        bool graph[t][t];
        bool weak[t];
        for (int i = 0; i < t; i++) {
            weak[i] = true;
            for (int j = 0; j < t; j++) {
                cin >> graph[i][j];
            }
        }

        for (int b = 0; b < t; b++) {
            if (!weak[b]) continue;
            for (int j = 0; j < t; j++) {
                for (int k = j + 1; k < t; k++) {
                    if (graph[b][j] && graph[b][k] && graph[j][k]) {
                        weak[b] = false;
                        weak[j] = false;
                        weak[k] = false;
                    }
                }
            }
        }

        for (int b = 0; b < t; b++) {
            if (weak[b]) cout << b << " ";
        }
        cout << endl;
    }
}

#include <iostream>
#include <string>

using namespace std;

int main() {
    int t, c = 1;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        int matrix[m][m];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                char k;
                cin >> k;
                matrix[i][j] = k - '0';
            }
        }
        int k;
        cin >> k;
        while (k--) {
            string command;
            int i, j;
            cin >> command;
            if (command == "row") {
                cin >> i >> j;
                i--;
                j--;
                for (int a = 0; a < m; a++) {
                    int swap = matrix[i][a];
                    matrix[i][a] = matrix[j][a];
                    matrix[j][a] = swap;
                }
            } else if (command == "col") {
                cin >> i >> j;
                i--;
                j--;
                for (int a = 0; a < m; a++) {
                    int swap = matrix[a][i];
                    matrix[a][i] = matrix[a][j];
                    matrix[a][j] = swap;
                }
            } else if (command == "inc") {
                for (int a = 0; a < m; a++) {
                    for (int b = 0; b < m; b++) {
                        matrix[a][b] = (matrix[a][b] + 1) % 10;
                    }
                }
            } else if (command == "dec") {
                for (int a = 0; a < m; a++) {
                    for (int b = 0; b < m; b++) {
                        matrix[a][b] = (matrix[a][b] + 9) % 10;
                    }
                }
            } else if (command == "transpose") {
                int transposed[m][m];
                for (int a = 0; a < m; a++) {
                    for (int b = 0; b < m; b++) {
                        transposed[a][b] = matrix[b][a];
                    }
                }
                for (int a = 0; a < m; a++) {
                    for (int b = 0; b < m; b++) {
                        matrix[a][b] = transposed[a][b];
                    }
                }
            }
        }
        cout << "Case #" << c++ << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cout << matrix[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

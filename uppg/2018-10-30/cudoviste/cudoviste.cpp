#include <iostream>
using namespace std;

int main() {
    int l, w;
    int squishes[5] = {0, 0, 0, 0, 0};
    cin >> l >> w;
    string lot[l];
    for (int i = 0; i < l; i++) {
        cin >> lot[i];
    }
    for (int i = 0; i < l - 1; i++) {
        for (int j = 0; j < w - 1; j++) {
            int squish = 0;
            if (lot[i][j] == '#' || lot[i][j + 1] == '#' ||
                lot[i + 1][j] == '#' || lot[i + 1][j + 1] == '#')
                continue;
            if (lot[i][j] == 'X') squish++;
            if (lot[i][j + 1] == 'X') squish++;
            if (lot[i + 1][j] == 'X') squish++;
            if (lot[i + 1][j + 1] == 'X') squish++;
            squishes[squish]++;
        }
    }
    for (int i = 0; i < 5; i++) cout << squishes[i] << endl;
    return 0;
}

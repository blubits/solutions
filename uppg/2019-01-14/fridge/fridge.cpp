#include <iostream>
#include <string>

using namespace std;

int main() {
    int occ[10] = {0};
    string line;
    getline(cin, line);
    for (auto c : line) {
        occ[int(c - '0')]++;
    }
    // find min
    int mi, mocc = 1001;
    for (int i = 0; i < 9; i++) {
        if (occ[i] < mocc || (occ[i] == mocc && mi == 0 && i != 0)) {
            mocc = occ[i];
            mi = i;
        }
    }
    if (mi == 0) {
        cout << 1;
    }
    for (int i = 0; i <= mocc; i++) {
        cout << mi;
    }
    cout << endl;
}

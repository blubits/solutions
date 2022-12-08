#include <iostream>
#include <string>

using namespace std;

int main() {
    string A, B;
    cin >> A >> B;
    int ra, cb;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            if (A[i] == B[j]) {
                ra = j;
                cb = i;
                goto print;
            }
        }
    }
print:
    for (int r = 0; r < B.size(); r++) {
        for (int c = 0; c < A.size(); c++) {
            if (r == ra)
                cout << A[c];
            else if (c == cb)
                cout << B[r];
            else
                cout << ".";
        }
        cout << endl;
    }
    return 0;
}

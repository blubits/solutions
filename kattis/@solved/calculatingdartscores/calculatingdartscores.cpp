#include <iostream>
#include <string>

using namespace std;

int main() {
    int k;
    bool done = false;
    string rep[4] = {"", "single", "double", "triple"};
    cin >> k;
    for (int a = 1; a <= 3 && !done; a++) {
        for (int s1 = 1; s1 <= 20 && !done; s1++) {
            for (int b = 1; b <= 3 && !done; b++) {
                for (int s2 = 0; s2 <= 20 && !done; s2++) {
                    for (int c = 1; c <= 3 && !done; c++) {
                        for (int s3 = 0; s3 <= 20 && !done; s3++) {
                            if (a * s1 + b * s2 + c * s3 == k) {
                                done = true;
                                cout << rep[a] << " " << s1 << endl;
                                if (s2) cout << rep[b] << " " << s2 << endl;
                                if (s3) cout << rep[c] << " " << s3 << endl;
                            }
                        }
                    }
                }
            }
        }
    }
    if (!done) cout << "impossible" << endl;
    return 0;
}

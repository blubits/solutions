#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int cyc1 = a + b, cyc2 = c + d;
    for (int i = 0; i < 3; i++) {
        int dogs = 0, time;
        cin >> time;
        if (0 < (time % cyc1) && (time % cyc1) <= a) dogs++;
        if (0 < (time % cyc2) && (time % cyc2) <= c) dogs++;
        if (dogs == 2) cout << "both";
        if (dogs == 1) cout << "one";
        if (dogs == 0) cout << "none";
        cout << endl;
    }
    return 0;
}

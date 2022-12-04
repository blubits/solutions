#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int t;
    double d;
    while (cin >> d >> t && (d || t)) {
        double x[t], y[t];
        bool issour[t];
        for (int i = 0; i < t; i++) {
            cin >> x[i] >> y[i];
            issour[i] = false;
        }
        for (int i = 0; i < t; i++) {
            for (int j = i + 1; j < t; j++) {
                if (issour[j]) continue;
                double dij = abs(hypot(x[i] - x[j], y[i] - y[j]));
                if (dij <= d) {
                    issour[i] = true;
                    issour[j] = true;
                }
            }
        }
        int sour = 0, sweet = 0;
        for (int i = 0; i < t; i++) {
            if (issour[i])
                sour++;
            else
                sweet++;
        }
        cout << sour << " sour, " << sweet << " sweet" << endl;
    }
}

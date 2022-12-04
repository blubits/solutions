#include <iostream>

using namespace std;

int main() {
    double h, u, d, f;
    while (cin >> h >> u >> d >> f && h != 0) {
        int day = 1;
        double ht = 0, du = u, dd = d, ff = (f / 100) * u;
        while (true) {
            ht += du;
            // cout << ht << " (+ " << du << ")" << endl;
            if (ht > h) {
                cout << "success on day " << day << endl;
                break;
            }
            if (du - ff >= 0) du -= ff;
            ht -= dd;
            // cout << ht << endl;
            if (ht < 0) {
                cout << "failure on day " << day << endl;
                break;
            }
            day++;
        }
    }
}

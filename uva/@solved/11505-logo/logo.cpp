#include <cmath>
#include <iostream>
#include <string>

#define PI atan(1.0) * 4

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        double deg = 0, vx = cos(deg), vy = sin(deg);
        double x = 0, y = 0;
        int c;
        cin >> c;
        while (c--) {
            string cd;
            int k;
            cin >> cd >> k;
            if (cd == "fd") {
                x += k * vx;
                y += k * vy;
            } else if (cd == "bk" || cd == "bc") {
                x -= k * vx;
                y -= k * vy;
            } else if (cd == "lt") {
                deg += (k / 180.0) * PI;
                if (deg < 0) deg += 2 * PI;
                if (deg >= 2 * PI) deg -= 2 * PI;
                vx = cos(deg);
                vy = sin(deg);
            } else if (cd == "rt") {
                deg -= (k / 180.0) * PI;
                if (deg < 0) deg += 2 * PI;
                if (deg >= 2 * PI) deg -= 2 * PI;
                vx = cos(deg);
                vy = sin(deg);
            }
        }
        int d = round(hypot(x, y));
        cout << d << endl;
    }
}

#include <cmath>
#include <iostream>
using namespace std;

#define PI atan(1.0) * 4

int main() {
    double a, n;
    scanf("%lf %lf", &a, &n);
    if (a <= (n * n) / (4 * PI))
        cout << "Diablo is happy!";
    else
        cout << "Need more materials!";
    cout << endl;
}

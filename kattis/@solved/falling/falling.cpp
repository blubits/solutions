#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long int D;
    cin >> D;
    // fix i as the smaller number
    for (long long int i = 0; i <= (D/2)+1; i++) {
        long long int j = (long long int)(sqrt(D + i*i));
        if (j*j - i*i == D) {
            cout << i << " " << j << endl;
            return 0;
        }
    }
    cout << "impossible" << endl;
    return 0;
}
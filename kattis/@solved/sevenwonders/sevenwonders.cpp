#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int t = 0, c = 0, g = 0;
    for (auto k : s) {
        if (k == 'T') t++;
        if (k == 'C') c++;
        if (k == 'G') g++;
    }
    printf("%d\n", t * t + c * c + g * g + 7 * min(min(t, c), g));
}

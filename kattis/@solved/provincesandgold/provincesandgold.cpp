#include <iostream>
#include <string>

using namespace std;

int main() {
    int g, s, c;
    cin >> g >> s >> c;
    int bp = (g * 3) + (s * 2) + c;
    string vc, tc;
    if (bp >= 8)
        vc = "Province or ";
    else if (bp >= 5)
        vc = "Duchy or ";
    else if (bp >= 2)
        vc = "Estate or ";
    if (bp >= 6)
        tc = "Gold";
    else if (bp >= 3)
        tc = "Silver";
    else
        tc = "Copper";
    cout << vc << tc << endl;
    return 0;
}

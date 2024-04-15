#include <iostream>
#include <string>

using namespace std;

int main() {
    string names[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    int k, l = 5, i = 1;
    cin >> k;
    k -= 1;
    while (k >= l) {
        // cout << k << " " << l << " " << i << endl;
        k -= l;
        i *= 2;
        l *= 2;
    }
    cout << names[(k / i)] << endl;
}

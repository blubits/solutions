#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string a;
    getline(cin, a);
    if (next_permutation(a.begin(), a.end()))
        cout << a << endl;
    else
        cout << 0 << endl;
}

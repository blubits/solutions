#include <iostream>
#include <string>

using namespace std;

int main() {
    string qk;
    getline(cin, qk);
    int i = 0, j = 0;
    for (auto c : qk) {
        if (c == '1' || c == '3') i += 1;
        if (c == '2' || c == '3') j += 1;
        i *= 2;
        j *= 2;
    }
    cout << qk.size() << " " << i / 2 << " " << j / 2 << endl;
    return 0;
}

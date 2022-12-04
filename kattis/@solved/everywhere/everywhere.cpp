#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int t, x;
    string s;
    cin >> t;
    while (t--) {
        set<string> places;
        cin >> x;
        while (x--) {
            cin >> s;
            places.insert(s);
        }
        cout << places.size() << endl;
    }
    return 0;
}

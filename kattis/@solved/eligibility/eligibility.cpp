#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string name;
        cin >> name;
        int sy, sm, sd, by, bm, bd, courses;
        char d;
        cin >> sy >> d >> sm >> d >> sd >> by >> d >> bm >> d >> bd >> courses;
        if (sy >= 2010) {
            cout << name << " eligible";
        } else if (by >= 1991) {
            cout << name << " eligible";
        } else if (courses >= 41) {
            cout << name << " ineligible";
        } else {
            cout << name << " coach petitions";
        }
        cout << endl;
    }
    return 0;
}

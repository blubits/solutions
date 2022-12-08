#include <iostream>
#include <sstream>
using namespace std;

int count[10] = {};

void add_to_count(string s) {
    for (auto c : s) {
        int i = c - '0';
        count[i]++;
    }
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        for (int i = 0; i < 10; i++) {
            count[i] = 0;
        }
        string street, noaddr_line;
        getline(cin, street);
        getline(cin, noaddr_line);

        stringstream noaddr(noaddr_line);
        int a;
        noaddr >> a;

        while (a) {
            string first;
            cin >> first;
            if (first == "+") {
                int lo, hi, step;
                cin >> lo >> hi >> step;
                for (int n = lo; n <= hi; n += step) {
                    add_to_count(to_string(n));
                    a--;
                }
            } else {
                add_to_count(first);
                a--;
            }
            cin.ignore();
        }

        cout << street << endl << noaddr_line << endl;
        int s = 0;
        for (int i = 0; i < 10; i++) {
            s += count[i];
            cout << "Make " << count[i] << " digit " << i << endl;
        }
        cout << "In total " << s << " digit" << (s == 1 ? "" : "s") << endl;
    }
    return 0;
}

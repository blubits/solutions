#include <iostream>
#include <string>

using namespace std;

int main() {
    string n, m;
    getline(cin, n);
    getline(cin, m);
    int zeroes = m.size() - 1;
    // count n's trailing zeroes
    int a;
    for (a = n.size() - 1; a > 0 && n[a] == '0'; a--)
        ;
    if (n.size() < m.size()) {
        int trailing_zeroes = zeroes - n.size();
        cout << "0.";
        for (int i = 0; i < trailing_zeroes; i++) cout << "0";
        for (int i = 0; i < n.size(); i++) {
            if (i <= a) cout << n[i];
        }
        cout << endl;
    } else {
        int bd = n.size() - zeroes;
        for (int i = 0; i < bd; i++) cout << n[i];
        if (bd <= a) cout << ".";
        for (int i = bd; i < n.size(); i++) {
            if (i <= a) cout << n[i];
        }
        cout << endl;
    }
    return 0;
}

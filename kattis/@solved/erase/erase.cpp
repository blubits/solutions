#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    string a, b;
    getline(cin, a);
    getline(cin, b);
    bool deleted = true;
    for (int i = 0; i < a.size(); i++) {
        if (n % 2 == 0 && a[i] != b[i]) {
            deleted = false;
            break;
        } else if (n % 2 == 1 && a[i] == b[i]) {
            deleted = false;
            break;
        }
    }
    if (deleted)
        cout << "Deletion succeeded";
    else
        cout << "Deletion failed";
    cout << endl;
    return 0;
}

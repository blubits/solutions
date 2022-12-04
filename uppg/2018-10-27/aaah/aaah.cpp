#include <iostream>
#include <string>

using namespace std;

int main() {
    string jon, doc;
    cin >> jon >> doc;
    if (jon.size() >= doc.size()) {
        cout << "go" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string w;
    bool sense = true;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w;
        if (w != "mumble" && stoi(w) != i) {
            sense = false;
            break;
        }
    }
    if (sense)
        cout << "makes sense";
    else
        cout << "something is fishy";
    cout << endl;
    return 0;
}

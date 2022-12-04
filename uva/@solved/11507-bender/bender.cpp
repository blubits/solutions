#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    while (1) {
        cin >> t;
        if (t == 0) break;
        string o = "+x", c;
        t--;
        while (t--) {
            cin >> c;
            if (c == "No")
                continue;
            else if (c == "+y") {
                if (o == "+x")
                    o = "+y";
                else if (o == "-x")
                    o = "-y";
                else if (o == "+y")
                    o = "-x";
                else if (o == "-y")
                    o = "+x";
            } else if (c == "-y") {
                if (o == "+x")
                    o = "-y";
                else if (o == "-x")
                    o = "+y";
                else if (o == "+y")
                    o = "+x";
                else if (o == "-y")
                    o = "-x";
            } else if (c == "+z") {
                if (o == "+x")
                    o = "+z";
                else if (o == "-x")
                    o = "-z";
                else if (o == "+z")
                    o = "-x";
                else if (o == "-z")
                    o = "+x";
            } else if (c == "-z") {
                if (o == "+x")
                    o = "-z";
                else if (o == "-x")
                    o = "+z";
                else if (o == "+z")
                    o = "+x";
                else if (o == "-z")
                    o = "-x";
            }
        }
        cout << o << endl;
    }
    return 0;
}

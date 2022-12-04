#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, lang;
    int c = 1;
    while (1) {
        cin >> s;
        if (s == "#") break;
        if (s == "HELLO")
            lang = "ENGLISH";
        else if (s == "HOLA")
            lang = "SPANISH";
        else if (s == "HALLO")
            lang = "GERMAN";
        else if (s == "BONJOUR")
            lang = "FRENCH";
        else if (s == "CIAO")
            lang = "ITALIAN";
        else if (s == "ZDRAVSTVUJTE")
            lang = "RUSSIAN";
        else
            lang = "UNKNOWN";
        cout << "Case " << c << ": " << lang << endl;
        c++;
    }
    return 0;
}

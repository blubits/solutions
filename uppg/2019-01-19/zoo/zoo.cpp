#include <cctype>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main() {
    int t, c = 1;
    while (cin >> t && t) {
        cin.ignore();
        string line;
        map<string, int> zoo;
        while (t--) {
            getline(cin, line);
            stringstream ss(line);
            string token;
            while (ss >> token) {
            }
            for (int i = 0; i < token.size(); i++) token[i] = tolower(token[i]);
            if (zoo.find(token) == zoo.end())
                zoo[token] = 1;
            else
                zoo[token]++;
        }
        cout << "List " << c++ << ":" << endl;
        for (auto p : zoo) {
            cout << p.first << " | " << p.second << endl;
        }
    }
}

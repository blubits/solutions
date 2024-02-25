#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    map<char, char> dat = {
        {'A', '2'}, {'B', '2'}, {'C', '2'}, {'D', '3'}, {'E', '3'}, {'F', '3'},
        {'G', '4'}, {'H', '4'}, {'I', '4'}, {'J', '5'}, {'K', '5'}, {'L', '5'},
        {'M', '6'}, {'N', '6'}, {'O', '6'}, {'P', '7'}, {'R', '7'}, {'S', '7'},
        {'T', '8'}, {'U', '8'}, {'V', '8'}, {'W', '9'}, {'X', '9'}, {'Y', '9'}};

    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        vector<string> numbers(n);
        for (int i = 0; i < n; i++) {
            string s, pn = "";
            cin >> s;
            for (auto c : s) {
                if ('0' <= c && c <= '9')
                    pn += c;
                else if ('A' <= c && c <= 'Z')
                    pn += dat[c];
                if (pn.size() == 3) pn += "-";
            }
            numbers[i] = pn;
        }
        sort(numbers.begin(), numbers.end());
        string ps = numbers[0];
        int i = 0;
        bool no_duplicates = true;
        for (auto n : numbers) {
            if (n == ps)
                i++;
            else {
                if (i > 1) {
                    cout << ps << " " << i << endl;
                    no_duplicates = false;
                }
                i = 1;
            }
            ps = n;
        }
        if (i > 1) {
            cout << ps << " " << i << endl;
            no_duplicates = false;
        }
        if (no_duplicates) cout << "No duplicates." << endl;
        if (k != 0) cout << endl;
    }
    return 0;
}

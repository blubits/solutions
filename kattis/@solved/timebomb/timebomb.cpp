#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    map<string, char> digits = {
        {"**** ** ** ****", '0'}, {"  *  *  *  *  *", '1'},
        {"***  *****  ***", '2'}, {"***  ****  ****", '3'},
        {"* ** ****  *  *", '4'}, {"****  ***  ****", '5'},
        {"****  **** ****", '6'}, {"***  *  *  *  *", '7'},
        {"**** ***** ****", '8'}, {"**** ****  ****", '9'}};
    vector<string> code;
    string line;
    while (getline(cin, line)) code.push_back(line);
    int chars = (code[0].size() + 1) / 4;
    string number;
    int start = 0;
    for (int i = 0; i < chars; i++) {
        string digit;
        for (int a = 0; a <= 4; a++) {
            for (int b = 0; b <= 2; b++) {
                digit += code[a][start + b];
            }
        }
        if (digits.find(digit) == digits.end()) {
            number = "-1";
            break;
        } else {
            number += digits[digit];
        }
        start += 4;
    }
    int num = stoi(number);
    if (num % 6 == 0)
        cout << "BEER!!" << endl;
    else
        cout << "BOOM!!" << endl;
}

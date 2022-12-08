#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int s;
    char p;
    string v;
    cin >> s;
    map<char, int> scores;
    while (s != -1) {
        // code
        cin >> p >> v;
        if (v == "wrong") {
            if (scores.find(p) != scores.end()) {
                scores[p] -= 1;
            } else {
                scores[p] = -1;
            }
        } else {
            if (scores.find(p) != scores.end()) {
                scores[p] = s + abs(20 * scores[p]);
            } else {
                scores[p] = s;
            }
        }
        cin >> s;
    }
    int score = 0;
    int problems = 0;
    for (auto x : scores) {
        if (x.second > 0) {
            score += x.second;
            problems++;
        }
    }
    cout << problems << " " << score << endl;
    return 0;
}

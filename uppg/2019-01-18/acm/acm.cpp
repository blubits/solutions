#include <iostream>
#include <string>

using namespace std;

int main() {

    int t;

    int penalties[26] = {0};
    
    int sp = 0, st = 0;

    while (cin >> t && t != -1) {
        char problem;
        string verdict;
        cin >> problem >> verdict;
        if (verdict == "wrong") {
            penalties[int(problem - 'A')]++;
        } else {
            sp++;
            st += t + (penalties[int(problem - 'A')]) * 20;
        }
    }

    cout << sp << " " << st << endl;
    
    return 0;
}
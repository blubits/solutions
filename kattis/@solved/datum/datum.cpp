#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int m, d;
    scanf("%d %d", &d, &m);

    string day[7] = {"Thursday", "Friday",  "Saturday", "Sunday",
                     "Monday",   "Tuesday", "Wednesday"};
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int displ = 0;
    for (int i = 0; i < m - 1; i++) {
        displ += month[i];
    }
    displ += d - 1;

    cout << day[displ % 7] << endl;
    return 0;
}

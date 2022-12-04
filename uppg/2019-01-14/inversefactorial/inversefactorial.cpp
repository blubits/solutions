#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string num;
    getline(cin, num);
    if (num == "1")
        cout << 1;
    else if (num == "2")
        cout << 2;
    else if (num == "6")
        cout << 3;
    else if (num == "24")
        cout << 4;
    else if (num == "120")
        cout << 5;
    else if (num == "720")
        cout << 6;
    else if (num == "5040")
        cout << 7;
    else if (num == "40320")
        cout << 8;
    else if (num == "362880")
        cout << 9;
    else if (num == "3628800")
        cout << 10;
    else if (num == "39916800")
        cout << 11;
    else if (num == "479001600")
        cout << 12;
    else if (num == "6227020800")
        cout << 13;
    else if (num == "87178291200")
        cout << 14;
    else if (num == "1307674368000")
        cout << 15;
    else if (num == "20922789888000")
        cout << 16;
    else if (num == "355687428096000")
        cout << 17;
    else if (num == "6402373705728000")
        cout << 18;
    else if (num == "121645100408832000")
        cout << 19;
    else if (num == "2432902008176640000")
        cout << 20;
    else {
        double est = 0;
        int sz = num.size(), k = 21;
        for (int i = 1; i <= 20; i++) est += log10(i);
        while (true) {
            est += log10(k);
            if (ceil(est) == sz) {
                cout << k;
                break;
            }
            k++;
        }
    }
    cout << endl;
    return 0;
}

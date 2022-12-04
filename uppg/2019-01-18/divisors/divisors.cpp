#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> primes = {
        2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,
        47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107,
        109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
        191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263,
        269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
        353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431};
    vector<vector<int>> pf(432);
    for (int i = 0; i < pf.size(); i++) {
        pf[i].resize(primes.size());
    }

    for (int i = 2; i < pf.size(); i++) {
        int num = i;
        for (int j = 0; j < primes.size() && num != 1; j++) {
            int p = primes[j];
            while (num % p == 0) {
                num /= p;
                pf[i][j]++;
            }
        }
    }

    // for (int i = 2; i < pf.size(); i++)
    // {
    //     cout << i << " = ";
    //     for (int j = 0; j < primes.size(); j++)
    //     {
    //         if (pf[i][j] != 0)
    //             cout << primes[j] << "^" << pf[i][j] << " * ";
    //     }
    //     cout << endl;
    // }

    // precompute divs
    vector<vector<unsigned long long int>> divs(432);
    for (int i = 0; i < divs.size(); i++) divs[i].resize(432);

    // base cases
    divs[0][0] = 1;
    divs[1][0] = 1;
    divs[1][1] = 1;
    // nc0, ncn
    for (int i = 2; i <= 431; i++) {
        divs[i][0] = 1;
        divs[i][i] = 1;
    }
    // nc1, nc(n - 1)
    for (int i = 2; i <= 431; i++) {
        unsigned long long int ans = 1;
        for (auto e : pf[i]) {
            if (e != 0) ans *= (e + 1);
        }
        divs[i][1] = ans;
        divs[i][i - 1] = ans;
    }

    for (int n = 4; n <= 431; n++) {
        vector<int> pf_nck = pf[n];
        for (int k = 2; k <= n / 2; k++) {
            // add top pf: n - k + 1
            for (int i = 0; i < pf[n - k + 1].size(); i++) {
                pf_nck[i] += pf[n - k + 1][i];
            }
            // subtract bottom pf: k
            for (int i = 0; i < pf[k].size(); i++) {
                pf_nck[i] -= pf[k][i];
            }

            unsigned long long int ans = 1;
            for (auto e : pf_nck) {
                if (e != 0) ans *= (e + 1);
            }
            divs[n][k] = ans;
            divs[n][n - k] = ans;
        }
    }

    int n, k;
    while (cin >> n >> k) {
        cout << divs[n][k] << endl;
    }

    return 0;
}

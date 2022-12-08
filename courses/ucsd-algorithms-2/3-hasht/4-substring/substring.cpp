#include <iostream>
#include <string>
#include <vector>

long long int hash(const std::string &s, long long int p, long long int x) {
    long long int h = 0;
    for (int i = 0; i < s.size(); i++) {
        h = (((h * x + s[i]) % p) + p) % p;
    }
    return h;
}

class SubstringMatcher {
   private:
    std::string str;
    long long int pa, pb, x;
    std::vector<long long int> hasha, hashb, powa, powb;

   public:
    SubstringMatcher(std::string s)
        : str(s), pa(1000000007), pb(1000000009), x(263) {
        int slen = s.length();
        hasha.resize(slen + 1);
        hashb.resize(slen + 1);
        powa.resize(slen + 1);
        powb.resize(slen + 1);
        hasha[0] = hashb[0] = 0;
        powa[0] = powb[0] = 1;
        for (int i = 1; i <= slen; i++) {
            hasha[i] = (x * hasha[i - 1] + s[i - 1]) % pa;
            hashb[i] = (x * hashb[i - 1] + s[i - 1]) % pb;
            powa[i] = (powa[i - 1] * x) % pa;
            powb[i] = (powb[i - 1] * x) % pb;
        }
    }

    // Returns True if s.substr(i, l) = b.substr(j, l).
    bool query(int i, int j, int l) {
        long long int xpl_a = powa[l];
        long long int hashia =
            (((hasha[i + l] - (xpl_a * hasha[i])) % pa) + pa) % pa;
        long long int hashja =
            (((hasha[j + l] - (xpl_a * hasha[j])) % pa) + pa) % pa;
        if (hashia != hashja) return false;
        long long int xpl_b = powb[l];
        long long int hashib =
            (((hashb[i + l] - (xpl_b * hashb[i])) % pb) + pb) % pb;
        long long int hashjb =
            (((hashb[j + l] - (xpl_b * hashb[j])) % pb) + pb) % pb;
        if (hashib != hashjb) return false;
        return true;
    }
};

int main() {
    std::string s;
    std::cin >> s;
    SubstringMatcher sm(s);
    int q;
    std::cin >> q;
    while (q--) {
        int i, j, l;
        std::cin >> i >> j >> l;
        if (sm.query(i, j, l)) {
            std::cout << "Yes";
        } else {
            std::cout << "No";
        }
        std::cout << std::endl;
    }
    return 0;
}

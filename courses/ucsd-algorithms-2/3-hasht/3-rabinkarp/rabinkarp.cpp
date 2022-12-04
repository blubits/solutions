#include <iostream>
#include <string>
#include <vector>

unsigned long long int pow(unsigned long long int x, unsigned long long int y,
                           unsigned long long int p) {
    unsigned long long int ans = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            ans = (ans * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return ans;
}

bool equal(const std::string &text, const std::string &pattern, int k) {
    for (int i = 0; i < pattern.size(); i++) {
        if (pattern[i] != text[k + i]) return false;
    }
    return true;
}

unsigned long long int hash(const std::string &s) {
    unsigned long long int p = 1000000007, x = 31, h = 0;
    for (int i = 0; i < s.size(); i++) {
        h = (((h * x + s[i]) % p) + p) % p;
    }
    return h;
}

unsigned long long int hash_first(const std::string &s, int k) {
    unsigned long long int p = 1000000007, x = 31, h = 0;
    for (int i = 0; i < k; i++) {
        h = (((h * x + s[i]) % p) + p) % p;
    }
    return h;
}

void get_all_matches(const std::string &text, const std::string &pattern) {
    int ts = text.size(), ps = pattern.size();
    unsigned long long int p = 1000000007, x = 31;
    // execute Rabin-Karp
    // (1) calculate the hash of pattern
    unsigned long long int hashp = hash(pattern);
    unsigned long long int hasht = hash_first(text, ps);
    unsigned long long int y = pow(x, ps, p);
    // std::cout << hasht << " " << text.substr(0, ps) << " "
    //           << hash(text.substr(0, ps)) << std::endl;
    for (int i = 0; i <= ts - ps; i++) {
        // std::cout << i << std::endl;
        // std::cout << hashp << " " << hashes[i] << std::endl;
        if (hashp == hasht && equal(text, pattern, i)) {
            std::cout << i << " ";
        }
        long long int ans = (x * hasht - (text[i] * y) + text[i + ps]);
        while (ans < 0) {
            ans += p;
        }
        hasht = ans % p;
        // std::cout << hasht << " " << text.substr(i, ps) << " "
        //           << hash(text.substr(i, ps)) << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::string text, pattern;
    std::cin >> pattern >> text;
    get_all_matches(text, pattern);
}

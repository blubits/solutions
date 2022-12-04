#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

struct LCSResult {
    bool found;
    int start_a;
    int start_b;
    int len;
};

long long int hash(const std::string &s, long long int p, long long int x) {
    long long int h = 0;
    for (int i = 0; i < s.size(); i++) {
        h = (((h * x + s[i]) % p) + p) % p;
    }
    return h;
}

std::ostream &operator<<(std::ostream &os, LCSResult const &lr) {
    if (lr.found) {
        return os << lr.start_a << " " << lr.start_b << " " << lr.len;
    } else {
        return os << "0 0 0";
    }
}

class LCSFinder {
   private:
    // inputs to the hashing algorithm
    long long int p1, p2, x;

    // strings to find the LCS of
    std::string str_a, str_b;

    // h[i] = hash of str[0:i], with h[0] = 0
    std::vector<long long int> hasha_1, hasha_2, hashb_1, hashb_2;

    // pow[i] = x^i % p, i in [0..l] inclusive
    std::vector<long long int> pow_1, pow_2;

    // hmap[l][HASH] = i <=> the substring str[i:i+l] has hash HASH.
    std::unordered_map<int, std::unordered_map<long long int, int>> hmap_a_1,
        hmap_b_1;

    // hmap[l][i] = i <=> the substring str[i:i+l] has hash HASH.
    std::unordered_map<int, std::unordered_map<int, long long int>> hmap_a_2,
        hmap_b_2;

   public:
    LCSFinder(std::string sa, std::string sb)
        : str_a(sa), str_b(sb), p1(1000000007), p2(1000000009), x(263) {
        int slen_a = str_a.length(), slen_b = str_b.length();
        hasha_1.resize(slen_a + 1);
        hasha_2.resize(slen_a + 1);
        hashb_1.resize(slen_b + 1);
        hashb_2.resize(slen_b + 1);
        hasha_1[0] = hasha_2[0] = hashb_1[0] = hashb_2[0] = 0;
        // preprocessing step 1:
        // generate all hashes of leading substrings in O(n)
        for (int i = 1; i <= slen_a; i++) {
            hasha_1[i] = (x * hasha_1[i - 1] + sa[i - 1]) % p1;
            hasha_2[i] = (x * hasha_2[i - 1] + sa[i - 1]) % p2;
        }
        for (int i = 1; i <= slen_b; i++) {
            hashb_1[i] = (x * hashb_1[i - 1] + sb[i - 1]) % p1;
            hashb_2[i] = (x * hashb_2[i - 1] + sb[i - 1]) % p2;
        }
        // prepreocessing step 2:
        // generate all possible p^l % pn
        int slen_min = std::min(slen_a, slen_b);
        pow_1.resize(slen_min + 1);
        pow_2.resize(slen_min + 1);
        pow_1[0] = pow_2[0] = 1;
        for (int i = 1; i <= slen_min; i++) {
            pow_1[i] = (pow_1[i - 1] * x) % p1;
            pow_2[i] = (pow_2[i - 1] * x) % p2;
        }
    }

    LCSResult find_lcs() {
        // std::cout << str_a << " " << str_b << std::endl;
        // initialize the LCS result struct
        LCSResult res;
        res.found = false;
        // binary search on the maximum length of the LCS
        int lo = 0, hi = std::min(str_a.length(), str_b.length());
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            LCSResult res1 = find_cs_with_length(mid);
            if (res1.found == 1) {
                // a result was found for LCS with length l;
                // try to find the CSes with length < l
                // std::cout << mid << " -> " << res1 << std::endl;
                res = res1;
                lo = mid + 1;
            } else {
                // the length of the LCS must be less than l
                // std::cout << mid << " -> " << res1 << std::endl;
                hi = mid - 1;
            }
        }
        return res;
    }

   private:
    LCSResult find_cs_with_length(int l) {
        // initialize result struct
        LCSResult res;
        res.found = false;

        if (l == 0) return res;

        // generate all substrings of length l for str_a
        long long int hash1 = hasha_1[l], hash2 = hasha_2[l];
        hmap_a_1[l][hash1] = 0;
        hmap_a_2[l][0] = hash2;
        for (int i = 1; i <= str_a.size() - l; i++) {
            long long int add1 = (x * hash1) + str_a[i + l - 1];
            long long int sub1 = pow_1[l] * str_a[i - 1];
            hash1 = (((add1 - sub1) % p1) + p1) % p1;
            hmap_a_1[l][hash1] = i;
            long long int add2 = (x * hash2) + str_a[i + l - 1];
            long long int sub2 = pow_2[l] * str_a[i - 1];
            hash2 = (((add2 - sub2) % p2) + p2) % p2;
            hmap_a_2[l][i] = hash2;
            // std::cout << str_a.substr(i, l) << " (p1) : " << hash1
            //           << " ?= " << hash(str_a.substr(i, l), p1, x) <<
            //           std::endl;
            // std::cout << str_a.substr(i, l) << " (p2) : " << hash2
            //           << " ?= " << hash(str_a.substr(i, l), p2, x) <<
            //           std::endl;
        }

        // std::cout << "---" << std::endl;

        // generate all substrings of length l for str_b
        hash1 = hashb_1[l], hash2 = hashb_2[l];
        hmap_b_1[l][hash1] = 0;
        hmap_b_2[l][0] = hash2;
        for (int i = 1; i <= str_b.size() - l; i++) {
            long long int add1 = (x * hash1) + str_b[i + l - 1];
            long long int sub1 = pow_1[l] * str_b[i - 1];
            hash1 = (((add1 - sub1) % p1) + p1) % p1;
            hmap_b_1[l][hash1] = i;
            long long int add2 = (x * hash2) + str_b[i + l - 1];
            long long int sub2 = pow_2[l] * str_b[i - 1];
            hash2 = (((add2 - sub2) % p2) + p2) % p2;
            hmap_b_2[l][i] = hash2;
            // std::cout << str_b.substr(i, l) << " (p1) : " << hash1
            //           << " ?= " << hash(str_b.substr(i, l), p1, x) <<
            //           std::endl;
            // std::cout << str_b.substr(i, l) << " (p2) : " << hash2
            //           << " ?= " << hash(str_b.substr(i, l), p2, x) <<
            //           std::endl;
        }

        for (auto p : hmap_a_1[l]) {
            // std::cout << p.first << " " << p.second << std::endl;
            long long int hash = p.first;
            int loc_a = p.second;
            auto place_in_second = hmap_b_1[l].find(hash);
            if (place_in_second != hmap_b_1[l].end()) {
                // HASH was found in str_b's substrings, we have a possible
                // match; check the second hf
                int loc_b = place_in_second->second;
                // std::cout << loc_a << " " << loc_b << std::endl;
                if (hmap_a_2[l][loc_a] == hmap_b_2[l][loc_b]) {
                    res.found = true;
                    res.len = l;
                    res.start_a = loc_a;
                    res.start_b = loc_b;
                    return res;
                }
            }
        }
        return res;
    }
};

int main() {
    std::string a, b;
    while (std::cin >> a >> b) {
        LCSFinder lf(a, b);
        std::cout << lf.find_lcs() << std::endl;
    }
}

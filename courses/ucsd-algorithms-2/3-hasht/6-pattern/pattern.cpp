#include <iostream>
#include <string>
#include <vector>

class FuzzySearch {
   private:
    // inputs to the hashing algorithm
    long long int p1, p2, x;

    // string representing the text
    std::string str_a;

    // string representing the pattern
    std::string str_b;

    // h[i] = hash of str[0:i], with h[0] = 0
    std::vector<long long int> hasha_1, hasha_2, hashb_1, hashb_2;

    // pow[i] = x^i % p, i in [0..l] inclusive
    std::vector<long long int> pow_1, pow_2;

   public:
    FuzzySearch(std::string sa, std::string sb)
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

    std::vector<int> fuzzy_find(int mismatches) {
        std::vector<int> answer;
        for (int i = 0; i <= str_a.size() - str_b.size(); i++) {
            // std::cout << str_a.substr(i, str_b.size()) << std::endl;
            int count = count_mismatches(0, str_b.size(), i);
            // std::cout << count << std::endl;
            if (mismatches >= count) {
                answer.push_back(i);
            }
        }
        return answer;
    }

   private:
    int count_mismatches(int lo, int hi, int i) {
        // std::cout << lo << " " << hi << " " << i << std::endl;
        if (lo <= hi) {
            int mid = lo + ((hi - lo) / 2);
            int count = (str_a[i + mid] == str_b[mid]) ? 0 : 1;
            if (!query(i + lo, i + mid, lo, mid)) {
                count += count_mismatches(lo, mid, i);
            }
            if (!query(i + mid + 1, i + hi, mid + 1, hi)) {
                count += count_mismatches(mid + 1, hi, i);
            }
            return count;
        }
        return 0;
    }

    // Returns True if str_a[i1:i2] = str_b[j1:j2] (inclusive _1, exclusive _2).
    bool query(int i1, int i2, int j1, int j2) {
        long long int xpl_1 = pow_1[i2 - i1];
        long long int hashi_1 =
            (((hasha_1[i2] - (xpl_1 * hasha_1[i1])) % p1) + p1) % p1;
        long long int hashj_1 =
            (((hashb_1[j2] - (xpl_1 * hashb_1[j1])) % p1) + p1) % p1;
        if (hashi_1 != hashj_1) return false;
        long long int xpl_2 = pow_2[j2 - j1];
        long long int hashi_2 =
            (((hasha_2[i2] - (xpl_2 * hasha_2[i1])) % p2) + p2) % p2;
        long long int hashj_2 =
            (((hashb_2[j2] - (xpl_2 * hashb_2[j1])) % p2) + p2) % p2;
        if (hashi_2 != hashj_2) return false;
        return true;
    }
};

int main() {
    int k;
    std::string pattern, text;
    while (std::cin >> k >> pattern >> text) {
        FuzzySearch fs(pattern, text);
        auto ans = fs.fuzzy_find(k);
        std::cout << ans.size() << " ";
        for (auto i : ans) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}

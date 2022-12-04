#include <cstdio>
#include <vector>

using namespace std;

typedef unsigned long long int ull;

ull lds(vector<int> seq) {
    // lds[i] is the maximal length of the LDS **ending** at index i
    // base: lds[i] is always min. 1 (i.e. the LDS ending at i
    // contains at least itself)
    vector<ull> lds(seq.size(), 1);

    // compute all LDS from 1..n
    // obviously, lds[0] == 1 (there is only 1 sequence ending at index 0)
    // so we don't compute that anymore
    for (ull j = 1; j < seq.size(); j++) {
        for (ull i = 0; i < j; i++) {
            /*
             * Imagine an LDS of length $l$ you've already detected that
             * ends at i.
             *
             * Now check all elements to the **right** of this LDS,
             * and try adding them to the existing LDS. A new LDS, ending at
             * this new element (let's call it j), will only be formed if
             * this j is smaller than or equal to i.
             *
             * Now say that you've found this LDS (it is very possible
             * that you can't). The LDS is *maximal* owing to its name; if
             * there already exists a bigger LDS at j, don't change
             * the LDS array, as a longer LDS already has been found.
             *
             * In summary:
             *      For all j from 1...n,
             *
             *      lds[j] = 1 + max(lds[i])
             *               for all i strictly before j (i > j > 0)
             *               such that seq[j] is less than or equal to seq[i].
             *
             *               If no i satisfies this, lds[j] = 1.
             */
            if (seq[j] <= seq[i] && lds[j] < lds[i] + 1) {
                lds[j] = lds[i] + 1;
            }
        }
    }

    ull max = 0;
    for (ull i = 0; i < seq.size(); i++) {
        if (max < lds[i]) max = lds[i];
    }

    return max;
}

int main() {
    vector<int> heights;
    int k, c = 1;
    while (scanf("%d", &k) == 1) {
        if (k == -1) {
            if (heights.size() == 0) break;
            if (c != 1) printf("\n");
            ull ans = lds(heights);
            // process and output
            printf("Test #%d:\n  maximum possible interceptions: %llu\n", c++,
                   ans);
            heights.clear();
        } else {
            heights.push_back(k);
        }
    }
}

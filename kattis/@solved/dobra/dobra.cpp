#include <cstdio>
#include <vector>

using namespace std;

char str[110];
int len = 0;
vector<int> posns;
bool l = false;

const int VOWEL = 1, L = 2, NON_L = 3;

const int IS_VOWEL = 10, IS_CONSONANT = 20;

int ltype(char c) {
    switch (c) {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return IS_VOWEL;
        case '_':
            return -1000;
        default:
            return IS_CONSONANT;
    }
}

// IS_VOWEL = vowel
// IS_CONSONANT = consonant
int type_r(int i) {
    if (i < 2) return -1;
    return (ltype(str[i - 1]) + ltype(str[i - 2])) / 2;
}
int type_c(int i) {
    if (i < 1 || i > len - 2) return -1;
    return (ltype(str[i - 1]) + ltype(str[i + 1])) / 2;
}
int type_l(int i) {
    if (i > len - 3) return -1;
    return (ltype(str[i + 1]) + ltype(str[i + 2])) / 2;
}

long long int count_rec(int i, int last_placed, bool has_l) {
    //for (int k = 0; k < i; k++) printf("  "); 
    //printf("%d %c %d\n", i, str[posns[i - 1]], has_l);
    if (i == posns.size()) {
        printf("%s\n", str);
        return 1;
    }
    int curr_pos = posns[i];
    long long int sum = 0;
    // if this is the last position and has_l is false, you're boxed into L
    if (i == posns.size() - 1 && !has_l) {
        //printf("%d %d %d\n", type_r(curr_pos), type_c(curr_pos), type_l(curr_pos));
        if (type_r(curr_pos) != IS_CONSONANT && type_c(curr_pos) != IS_CONSONANT && type_l(curr_pos) != IS_CONSONANT) {
            str[curr_pos] = 'L';
            sum += count_rec(i + 1, L, true);
            str[curr_pos] = '_';
        }
        return sum;
    }
    // consonant
    if (type_r(curr_pos) != IS_CONSONANT && type_c(curr_pos) != IS_CONSONANT && type_l(curr_pos) != IS_CONSONANT) {
        str[curr_pos] = 'B';
        sum += 20 * count_rec(i + 1, NON_L, has_l);
        str[curr_pos] = '_';
    long long int sum = 0;
    // i
        str[curr_pos] = 'L';
        sum += count_rec(i + 1, L, true);
        str[curr_pos] = '_';
    }
    // vowel
    if (type_r(curr_pos) != IS_VOWEL && type_c(curr_pos) != IS_VOWEL && type_l(curr_pos) != IS_VOWEL) {
        str[curr_pos] = 'A';
        sum += 5 * count_rec(i + 1, VOWEL, has_l);
        str[curr_pos] = '_';
    }
    return sum;
}

long long int count() {
    if (posns.size() == 0) {
        if (!l) return 0;
        for (int i = 0; i < len - 2; i++) {
            if (ltype(str[i]) + ltype(str[i + 1]) + ltype(str[i + 2]) == 30) return 0;
            if (ltype(str[i]) + ltype(str[i + 1]) + ltype(str[i + 2]) == 60) return 0;
        }
        return 1;
    }
    return count_rec(0, 0, l);
}

int main() {
    scanf("%s", &str);
    int i = 0;
    while (str[i]) {
        if (str[i] == '_') posns.push_back(i);
        if (str[i] == 'L') l = true;
        i++;
        len++;
    }
    //for (auto i: posns) printf("%d\n", i);
    printf("%lld\n", count());
}


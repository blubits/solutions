#include <iostream>
#include <vector>

int main() {
    int Na, Nb;
    std::cin >> Na;
    std::vector<int> a(Na + 10);
    for (int i = 0; i < Na; i++) std::cin >> a[i];
    std::cin >> Nb;
    std::vector<int> b(Nb + 10);
    for (int i = 0; i < Nb; i++) std::cin >> b[i];
    int lcs[Na + 10][Nb + 10];
    for (int i = 0; i <= Na; i++) {
        lcs[i][0] = 0;
    }
    for (int j = 0; j <= Nb; j++) {
        lcs[0][j] = 0;
    }
    for (int i = 1; i <= Na; i++) {
        for (int j = 1; j <= Nb; j++) {
            int insertion = lcs[i][j - 1];
            int deletion = lcs[i - 1][j];
            int match_or_mismatch =
                lcs[i - 1][j - 1] + ((a[i - 1] == b[j - 1]) ? 1 : 0);
            lcs[i][j] =
                std::max(std::max(insertion, deletion), match_or_mismatch);
        }
    }
    std::cout << lcs[Na][Nb] << std::endl;
}

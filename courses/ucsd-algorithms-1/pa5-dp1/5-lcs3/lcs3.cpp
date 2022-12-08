#include <iostream>
#include <vector>

int main() {
    int Na, Nb, Nc;
    std::cin >> Na;
    std::vector<int> a(Na + 10);
    for (int i = 0; i < Na; i++) std::cin >> a[i];
    std::cin >> Nb;
    std::vector<int> b(Nb + 10);
    for (int i = 0; i < Nb; i++) std::cin >> b[i];
    std::cin >> Nc;
    std::vector<int> c(Nc + 10);
    for (int i = 0; i < Nc; i++) std::cin >> c[i];
    int lcs[Na + 10][Nb + 10][Nc + 10];
    for (int i = 0; i <= Na; i++) {
        for (int j = 0; j <= Nb; j++) {
            for (int k = 0; k <= Nc; k++) {
                if (i == 0 || j == 0 || k == 0) {
                    lcs[i][j][k] = 0;
                } else if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) {
                    lcs[i][j][k] = 1 + lcs[i - 1][j - 1][k - 1];
                } else {
                    int a = lcs[i - 1][j][k];
                    int b = lcs[i][j - 1][k];
                    int c = lcs[i][j][k - 1];
                    int d = lcs[i - 1][j - 1][k];
                    int e = lcs[i - 1][j][k - 1];
                    int f = lcs[i][j - 1][k - 1];
                    lcs[i][j][k] =
                        std::max(std::max(std::max(a, b), std::max(c, d)),
                                 std::max(std::max(e, f), 0));
                }
            }
        }
    }
    std::cout << lcs[Na][Nb][Nc] << std::endl;
}

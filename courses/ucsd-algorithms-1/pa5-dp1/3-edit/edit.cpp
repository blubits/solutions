#include <iostream>
#include <string>

int main() {
    std::string a, b;
    std::getline(std::cin, a);
    std::getline(std::cin, b);
    int edit_distance[a.size() + 10][b.size() + 10];
    for (int i = 0; i <= a.size(); i++) {
        edit_distance[i][0] = i;
    }
    for (int j = 0; j <= b.size(); j++) {
        edit_distance[0][j] = j;
    }
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            int insertion = edit_distance[i][j - 1] + 1;
            int deletion = edit_distance[i - 1][j] + 1;
            int match_or_mismatch =
                edit_distance[i - 1][j - 1] + ((a[i - 1] == b[j - 1]) ? 0 : 1);
            edit_distance[i][j] =
                std::min(std::min(insertion, deletion), match_or_mismatch);
        }
    }
    std::cout << edit_distance[a.size()][b.size()] << std::endl;
}

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

long long int perform_operation(long long int a, char op, long long int b) {
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
    else
        return -1;
}

int main() {
    std::string expr;
    std::getline(std::cin, expr);
    int N = expr.size() / 2 + 1;
    std::vector<int> numbers(N), operations(N - 1);
    for (int i = 0; i < expr.size(); i++) {
        if (i % 2 == 0)
            numbers[i / 2] = expr[i] - '0';
        else
            operations[i / 2] = expr[i];
    }
    long long int min_val[20][20];
    long long int max_val[20][20];
    for (int i = 0; i < N; i++) {
        min_val[i][i] = numbers[i];
        max_val[i][i] = numbers[i];
    }
    for (int sz = 1; sz <= N - 1; sz++) {
        for (int i = 0; i < N - sz; i++) {
            int j = i + sz;
            // calculate the maximum and minimum values of the expression
            long long int min = INT64_MAX, max = INT64_MIN;
            for (int k = i; k < j; k++) {
                long long int a = perform_operation(
                    min_val[i][k], operations[k], min_val[k + 1][j]);
                long long int b = perform_operation(
                    min_val[i][k], operations[k], max_val[k + 1][j]);
                long long int c = perform_operation(
                    max_val[i][k], operations[k], min_val[k + 1][j]);
                long long int d = perform_operation(
                    max_val[i][k], operations[k], max_val[k + 1][j]);
                min = std::min(std::min(min, std::min(a, b)), std::min(c, d));
                max = std::max(std::max(max, std::max(a, b)), std::max(c, d));
            }
            min_val[i][j] = min;
            max_val[i][j] = max;
        }
    }
    std::cout << max_val[0][N - 1] << std::endl;
    return 0;
}

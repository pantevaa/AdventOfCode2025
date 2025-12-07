#include<bits/stdc++.h>

int main() {
    std::ifstream input("07_input.txt");
    if (!input.is_open()) {
        std::cerr << "Open file error" << std::endl;
        return 1;
    }
    std::string s;
    std::vector<std::string> matrix;
    while (input >> s) {
        matrix.push_back(s);
    }
    std::vector<std::vector<long long>> dp(matrix.size(), std::vector<long long>(matrix[0].size()));
    dp[0][matrix[0].find('S')] = 1;
    for (int i = 1; i < dp.size(); ++i) {
        for (int j = 0; j < dp[0].size(); ++j) {
            if (matrix[i][j] == '.') {
                dp[i][j] += dp[i - 1][j];
            } else {
                dp[i][j - 1] += dp[i - 1][j];
                dp[i][j + 1] += dp[i - 1][j];
            }
        }
    }
    long long ans = 0;
    for (const auto &x : dp.back()) {
        ans += x;
    }
    std::cout << ans;
}

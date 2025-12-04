#include<bits/stdc++.h>

int main() {
    std::ifstream input("4_input.txt");
    if (!input.is_open()) {
        std::cerr << "Open file error" << std::endl;
        return 1;
    }
    std::vector<std::vector<int> > matrix;
    std::string s;
    while (input >> s) {
        matrix.push_back({0});
        for (const auto &s_i: s) {
            if (s_i == '.') {
                matrix.back().push_back(0);
            } else {
                matrix.back().push_back(1);
            }
        }
        matrix.back().push_back(0);
    }
    matrix.push_back(std::vector<int>(matrix[0].size(), 0));
    matrix.insert(matrix.begin(), std::vector<int>(matrix[0].size(), 0));
    long long ans = 0;
    for (int i = 1; i + 1 < matrix.size(); ++i) {
        for (int j = 1; j + 1 < matrix[0].size(); ++j) {
            if (matrix[i][j] == 1 && matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i - 1][j + 1] +
                matrix[i][j - 1] + matrix[i][j + 1] +
                matrix[i + 1][j - 1] + matrix[i + 1][j] + matrix[i + 1][j + 1] < 4) {
                ++ans;
            }
        }
    }
    std::cout << ans;
}

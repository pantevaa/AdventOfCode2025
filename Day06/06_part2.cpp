#include<bits/stdc++.h>

int main() {
    std::ifstream input("06_input.txt");
    if (!input.is_open()) {
        std::cerr << "Open file error" << std::endl;
        return 1;
    }
    std::vector<std::string> vec;
    std::string s;
    while (std::getline(input, s)) {
        vec.push_back(s);
    }
    long long ans = 0;
    std::vector<int> nums;
    for (int i = vec[0].size() - 1; i >= 0; --i) {
        std::string num;
        for (int j = 0; j + 1 < vec.size(); ++j) {
            if (vec[j][i] != ' ') {
                num += vec[j][i];
            }
        }
        if (!num.empty()) {
            nums.push_back(std::stoi(num));
        }
        if (vec.back()[i] == '*') {
            ans += std::accumulate(nums.begin(), nums.end(), 1LL, [](long long a, long long b) {
                return a * b;
            });
            nums.clear();
        }
        if (vec.back()[i] == '+') {
            ans += std::accumulate(nums.begin(), nums.end(), 0LL, [](long long a, long long b) {
                return a + b;
            });
            nums.clear();
        }
    }
    std::cout << ans;
}

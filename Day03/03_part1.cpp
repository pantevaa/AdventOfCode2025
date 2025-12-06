#include<bits/stdc++.h>

int main() {
    std::ifstream input("03_input.txt");
    if (!input.is_open()) {
        std::cerr << "Open file error" << std::endl;
        return 1;
    }
    std::vector<std::string> banks;
    std::string b;
    while (input >> b) {
        banks.push_back(b);
    }
    int ans = 0;
    for (auto s : banks) {
        int max_1 = 0;
        int max_2 = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] - '0' > max_1 && i != s.size() - 1) {
                max_2 = 0;
                max_1 = s[i] - '0';
            } else if (s[i] - '0' > max_2) {
                max_2 = s[i] - '0';
            }
        }
        ans += (max_1 * 10) + max_2;
    }
    std::cout << ans;
}
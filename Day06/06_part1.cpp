#include<bits/stdc++.h>

int main() {
    std::ifstream input("06_input.txt");
    if (!input.is_open()) {
        std::cerr << "Open file error" << std::endl;
        return 1;
    }
    std::vector<int> nums;
    std::vector<std::string> oper;
    std::string s;
    while (input >> s) {
        if (s == "+" || s == "*") {
            oper.push_back(s);
        } else {
            nums.push_back(stoi(s));
        }
    }
    int len_cycle = oper.size();
    long long ans = 0;
    for (int i = 0; i < len_cycle; ++i) {
        long long ans_col = oper[i] == "*" ? 1: 0;
        for (int j = i; j < nums.size(); j += len_cycle) {
            if (oper[i] == "*") {
                ans_col *= nums[j];
            } else {
                ans_col += nums[j];
            }
        }
        ans += ans_col;
    }
    std::cout << ans;
}

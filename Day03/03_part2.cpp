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
    long long ans = 0;
    for (auto s : banks) {
        std::vector<int> nums(12);
        for (int i = 0; i < s.size(); ++i) {
            int idx_change = 12;
            for (int j = std::max(0, 12 - (int(s.size()) - i)); j < 12; ++j) {
                if (nums[j] < s[i] - '0') {
                    nums[j] = s[i] - '0';
                    idx_change = j;
                    break;
                }
            }
            for (int j = idx_change + 1; j < 12; ++j) {
                nums[j] = 0;
            }
        }
        std::string s_num;
        for (int i = 0; i < 12; ++i) {
            s_num += std::to_string(nums[i]);
        }
        ans += stoll(s_num);
    }
    std::cout << ans;
}
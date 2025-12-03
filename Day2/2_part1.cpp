#include<bits/stdc++.h>

int main() {
    std::ifstream input("2_input.txt");
    if (!input.is_open()) {
        std::cerr << "Open file error" << std::endl;
        return 1;
    }
    long long ans = 0;
    std::string token;
    while (std::getline(input, token, ',')) {
        int pos = token.find('-');
        long long l = stoll(token.substr(0, pos));
        long long r = stoll(token.substr(pos + 1));
        for (long long i = l; i <= r; ++i) {
            std::string i_s = std::to_string(i);
            int m = i_s.size() / 2;
            if (i_s.substr(0, m) == i_s.substr(m)) {
                ans += i;
            }
        }
    }
    std::cout << ans;
}
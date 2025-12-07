#include<bits/stdc++.h>

int main() {
    std::ifstream input("07_input.txt");
    if (!input.is_open()) {
        std::cerr << "Open file error" << std::endl;
        return 1;
    }
    std::string s;
    input >> s;
    std::set<int> indices;
    indices.insert(s.find('S'));
    int ans = 0;
    while (input >> s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '^' && indices.contains(i)) {
                ans++;
                indices.insert(i - 1);
                indices.insert(i + 1);
                indices.erase(i);
            }
        }
    }
    std::cout << ans;
}

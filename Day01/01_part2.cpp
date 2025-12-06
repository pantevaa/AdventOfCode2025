#include<bits/stdc++.h>

int main() {
    std::ifstream inputFile("01_input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Open file error" << std::endl;
        return 1;
    }
    int pos = 50;
    int ans = 0;
    std::string act;
    while (inputFile >> act) {
        int cnt = std::stoi(act.substr(1));
        for (int i = 0; i < cnt; ++i) {
            if (act[0] == 'L') {
                pos = (pos - 1 + 100) % 100;
            } else {
                pos = (pos + 1) % 100;
            }
            if (pos == 0) {
                ans++;
            }
        }
    }
    std::cout << ans;
}

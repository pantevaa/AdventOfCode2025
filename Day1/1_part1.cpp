#include<bits/stdc++.h>

int main() {
    std::ifstream inputFile("1_input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Open file error" << std::endl;
        return 1;
    }
    int pos = 50;
    int ans = 0;
    std::string act;
    while (inputFile >> act) {
        int amt = stoi(act.substr(1));
        if (act[0] == 'L') {
            pos = (pos - amt) % 100;
        } else {
            pos = (pos + amt) % 100;
        }
        if (pos == 0) {
            ans++;
        }
    }
    std::cout << ans;
}
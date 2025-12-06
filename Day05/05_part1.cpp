#include<bits/stdc++.h>

int main() {
    std::ifstream input("05_input.txt");
    if (!input.is_open()) {
        std::cerr << "Open file error" << std::endl;
        return 1;
    }

    struct Point {
        long long p, type;
        auto operator<=>(const Point&) const = default;
    };
    std::vector<Point> points;
    std::string s;
    while (input >> s) {
        int pos = s.find('-');
        if (pos != std::string::npos) {
            long long start = stoll(s.substr(0, pos));
            long long end = stoll(s.substr(pos + 1));
            points.emplace_back(start, -1);
            points.emplace_back(end, 1);
        } else {
            points.emplace_back(stoll(s), 0);
        }
    }
    std::ranges::sort(points);
    int in_interval = 0;
    int ans = 0;
    for (const auto &p : points) {
        if (p.type == -1) {
            in_interval++;
        } else if (p.type == 1) {
            in_interval--;
        } else {
            if (in_interval) {
                ans++;
            }
        }
    }
    std::cout << ans;
}

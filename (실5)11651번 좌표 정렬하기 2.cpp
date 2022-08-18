#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x, y;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; std::cin >> N;
    std::vector<Point> vec;

    for (int i=0; i<N; i++) {
        int temp_x, temp_y;
        std::cin >> temp_x >> temp_y;
        Point temp_point = {temp_x, temp_y};
        vec.push_back(temp_point);
    }

    std::sort(vec.begin(), vec.end(), [](const Point& pt1, const Point& pt2) -> bool {
        if (pt1.y == pt2.y)
            return pt1.x < pt2.x;
        else
            return pt1.y < pt2.y;
    });

    for (const auto& it : vec) {
        std::cout << it.x << " " << it.y << "\n";
    }
}
#include <iostream>
#include <vector>
#include <algorithm>

class Point{
public:
    int _x;
    int _y;
    Point(int x, int y) {
        _x = x;
        _y = y;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; std::cin >> N;
    std::vector<Point> vec;
    while (N --> 0) {
        int temp_x, temp_y;
        std::cin >> temp_x >> temp_y;
        vec.emplace_back(Point(temp_x, temp_y));
    }

    std::sort(vec.begin(), vec.end(), [](const Point& point1, const Point& point2) -> bool {
        if (point1._x != point2._x)
            return point1._x < point2._x;
        else
            return point1._y < point2._y;
    });

    for (const auto& it : vec)
        std::cout << it._x << " " << it._y << "\n";

}
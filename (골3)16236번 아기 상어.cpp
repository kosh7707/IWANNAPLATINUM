#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

class Shark {
private:
    pair<int, int> pos;
    int shark_exp;
    int shark_level;
public:
    Shark() {
        shark_level = 2;
        shark_exp = 0;
    }
    void eatFish() {
        shark_exp += 1;
        if (shark_exp == shark_level) {
            shark_level += 1;
            shark_exp = 0;
        }
    }
    pair<int, int> getPos() {
        return pos;
    }
    int getLevel() {
        return shark_level;
    }
    void setPos(pair<int, int> _pos) {
        pos = _pos;
    }
};

struct Point {
    int x;
    int y;
    int distance;
    Point(int _y, int _x, int _distance) {
        x = _x; y = _y;
        distance = _distance;
    }
};

struct comp {
    bool operator() (const Point& p1, const Point& p2) {
        if (p1.distance == p2.distance) {
            if (p1.y == p2.y) return p1.x > p2.x;
            return p1.y > p2.y;
        }
        return p1.distance > p2.distance;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    bool visited[21][21] = {false};
    int map[21][21];
    pair<int, int> dir[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    priority_queue<Point, vector<Point>, comp> qu;
    Shark shark;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) shark.setPos({i, j});
        }

    int cost = 0;
    qu.push(Point(shark.getPos().first, shark.getPos().second, 0));
    map[shark.getPos().first][shark.getPos().second] = 0;
    while(!qu.empty()) {
        auto next = qu.top(); qu.pop();
        if (next.x < 0 or next.y < 0 or next.x >= N or next.y >= N or visited[next.y][next.x]
                or map[next.y][next.x] > shark.getLevel())
            continue;
        visited[next.y][next.x] = true;
        if (map[next.y][next.x] != 0 and map[next.y][next.x] < shark.getLevel()) {
            shark.eatFish();
            cost += next.distance;
            map[shark.getPos().first][shark.getPos().second] = 0;
            map[next.y][next.x] = 0;
            shark.setPos({next.y, next.x});
            memset(visited, false, sizeof(visited));
            qu = priority_queue<Point, vector<Point>, comp>();
            qu.push(Point(shark.getPos().first, shark.getPos().second, 0));
        }
        else {
            for (int i=0; i<4; i++)
                qu.push({next.y + dir[i].first, next.x + dir[i].second, next.distance + 1});
        }
    }

    cout << cost;
}
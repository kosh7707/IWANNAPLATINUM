#include <iostream>

int N, r, c;
int answer = 0;

void dc(int y, int x, int size) {
    if (y == r and x == c) {
        std::cout << answer << "\n";
        return ;
    }
    if (r >= y and r < y+size and c >= x and c < x+size) {
        // 1사분면
        dc(y, x, size/2);
        // 2사분면
        dc(y, x+size/2, size/2);
        // 3사분면
        dc(y+size/2, x, size/2);
        // 4사분면
        dc(y+size/2, x+size/2, size/2);
    }
    else {
        answer += size*size;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> r >> c;
    dc(0, 0, (1 << N));
}


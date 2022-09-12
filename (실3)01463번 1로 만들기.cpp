#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N; std::cin >> N;
    int count = 0;

    std::queue<int> q;
    std::vector<int> vec(N+1, 10000001);
    q.push(N);
    vec[N] = 0;
    while (!q.empty()) {
        int temp = q.front(); q.pop();
        if (temp == 1) break;
        if (temp%3 == 0) {
            vec[temp/3] = (vec[temp/3] > vec[temp] + 1) ? vec[temp] + 1 : vec[temp/3];
            q.push(temp/3);
        }
        if (temp%2 == 0) {
            vec[temp/2] = (vec[temp/2] > vec[temp] + 1) ? vec[temp] + 1 : vec[temp/2];
            q.push(temp/2);
        }
        vec[temp-1] = (vec[temp-1] > vec[temp] + 1) ? vec[temp] + 1 : vec[temp-1];
        q.push(temp-1);
    }
    std::cout << vec[1] << "\n";
}


#include <iostream>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, K; std::cin >> N >> K;
    std::queue<int> qu;

    for(int i=1; i<N+1; i++)
        qu.push(i);

    std::cout << "<";
    while (qu.size() > 1) {
        for (int i=0; i<K-1; i++) {
            int temp = qu.front();
            qu.pop();
            qu.push(temp);
        }
        std::cout << qu.front() << ", ";
        qu.pop();
    }
    std::cout << qu.front() << ">";


}
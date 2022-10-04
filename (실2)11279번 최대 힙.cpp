#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; std::cin >> N;
    struct customComparator{
        bool operator()(const int a, const int b) {
            return a < b;
        }
    };
    priority_queue<int, std::vector<int>, customComparator> pq; int temp;
    while (N --> 0) {
        cin >> temp;
        if (temp == 0) {
            if (pq.empty()) cout << "0\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(temp);
        }
    }
}
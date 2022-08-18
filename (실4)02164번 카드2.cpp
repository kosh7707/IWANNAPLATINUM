#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<int> dq;

    int N; cin >> N;
    for (int i=1; i<=N; i++)
        dq.push_front(i);


    while (dq.size() != 1) {
        int temp;
        dq.pop_back();
        temp = dq.back();
        dq.pop_back();
        dq.push_front(temp);
    }
    std::cout << dq.front();
}
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct absComparator{
    bool operator() (const int l, const int r) const {
        if (abs(l) == abs(r)) return l > r;
        else return abs(l) > abs(r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<int, vector<int>, absComparator> absQueue;
    queue<int> output;

    int temp, t; cin >> t;
    for (int i=0; i<t; i++) {
        cin >> temp;
        if (temp == 0 and absQueue.empty())
            output.push(0);
        else if (temp == 0) {
            output.push(absQueue.top());
            absQueue.pop();
        }
        else
            absQueue.push(temp);
    }
    while (!output.empty()) {
        cout << output.front() << endl;
        output.pop();
    }

}
#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;
void method1() {
    int T; cin >> T;
    int k, n; char cmd;
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    unordered_map<int, int> um;

    while (T --> 0) {
        while (!min_pq.empty()) min_pq.pop();
        while (!max_pq.empty()) max_pq.pop();
        um.clear();
        cin >> k;
        while (k --> 0) {
            cin >> cmd >> n;
            if (cmd == 'I') {
                min_pq.push(n);
                max_pq.push(n);
                if (um[n] == 0) um[n] = 1;
                else um[n]++;
            }
            else if (cmd == 'D' and n == 1 and !max_pq.empty()) {
                if (um[max_pq.top()] > 0) um[max_pq.top()]--;
                max_pq.pop();
            }
            else if (cmd == 'D' and n == -1 and !min_pq.empty()) {
                if (um[min_pq.top()] > 0) um[min_pq.top()]--;
                min_pq.pop();
            }
            while (!max_pq.empty() and um[max_pq.top()] == 0) max_pq.pop();
            while (!min_pq.empty() and um[min_pq.top()] == 0) min_pq.pop();
        }
        if (min_pq.empty() and max_pq.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << max_pq.top() << " " << min_pq.top() << endl;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t; cin >> t;
    while (t --> 0) {
        int k, n; cin >> k;
        char cmd;
        multiset<int> s;
        while (k --> 0) {
            cin >> cmd >> n;
            if (cmd == 'I') {
                s.insert(n);
            }
            else if (cmd == 'D' and !s.empty()) {
                if (n == 1) s.erase(--s.end());
                else s.erase(s.begin());
            }
        }
        if (s.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << *(--s.end()) << " " << *(s.begin()) << endl;
        }
    }
}
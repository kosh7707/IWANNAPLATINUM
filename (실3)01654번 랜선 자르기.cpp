#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool check(const vector<int>& ties, const int& N, const long long& cut_value) {
    auto sum = accumulate(ties.begin(), ties.end(), 0, [&cut_value](long long current_count, long long current_element) -> long long {
        return current_count + current_element/cut_value;
    });
    if (sum >= N)
        return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, N;
    cin >> K >> N;

    vector<int> ties(K);
    for (int i=0; i<K; i++)
        cin >> ties[i];

    long long start = 1;
    long long end = *max_element(ties.begin(), ties.end());

    while (start+1 < end) {
        long long middle = (start + end)/2;
        if (check(ties, N, middle)) start = middle;
        else end = middle;
    }


    if (check(ties, N, start+1)) cout << start+1 << "\n";
    else cout << start << "\n";

}
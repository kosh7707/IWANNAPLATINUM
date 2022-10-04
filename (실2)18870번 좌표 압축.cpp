#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void method_1() {
    int N; cin >> N;
    vector<int> vec; int temp;
    for (int i=0; i<N; i++) {
        cin >> temp;
        vec.push_back(temp);
    }
    vector<int> copy_vec(vec);
    std::sort(copy_vec.begin(), copy_vec.end());
    copy_vec.erase(unique(copy_vec.begin(), copy_vec.end()), copy_vec.end());

    for (int i=0; i<N; i++) {
        auto it = lower_bound(copy_vec.begin(), copy_vec.end(), vec[i]);
        cout << it - copy_vec.begin() << " ";
    }
}

void method_2() {
    int N; cin >> N;
    // index, value
    vector<pair<int, int>> vec; int temp;
    for (int i=0; i<N; i++) {
        cin >> temp;
        vec.push_back({i, temp});
    }
    std::sort(vec.begin(), vec.end(), [](const auto& pair1, const auto& pair2) -> bool {
        return pair1.second < pair2.second;
    });
    // index, com_value
    vector<pair<int, int>> copy_vec;
    int rank = 0;
    copy_vec.push_back({vec[0].first, rank});
    for (int i=1; i<N; i++) {
        if (vec[i-1].second == vec[i].second) {
            copy_vec.push_back({vec[i].first, rank});
        }
        else {
            copy_vec.push_back({vec[i].first, ++rank});
        }
    }
    std::sort(copy_vec.begin(), copy_vec.end(), [](const auto& pair1, const auto& pair2) -> bool {
        return pair1.first < pair2.first;
    });
    for (const auto& it : copy_vec) {
        std::cout << it.second << " ";
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // method_1();
    method_2();
}
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M; string temp;
    cin >> N >> M >> temp;
    string PN = "I";
    for (int i=0; i<N; i++)
        PN += "OI";

    map<int, int> map1; // N, count
    int idx = 0;
    int temp_count = 0;
    while (idx < temp.length()) {
        temp_count = 0;
        if (temp[idx] == 'I') {
            while (idx + 2 < temp.length() and temp[idx+1] == 'O' and temp[idx+2] == 'I') {
                temp_count++;
                idx += 2;
            }
        }
        if (temp_count != 0 and temp_count >= N) {
            if (map1.find(temp_count) == map1.end()) map1.insert({temp_count, 1});
            else map1[temp_count]++;
        }
        idx++;
    }
    int count = 0;
    for (const auto& it : map1) {
        count += (it.first - N + 1) * it.second;
    }
    cout << count;
}
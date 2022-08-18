#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; std::cin >> N >> M;
    std::set<int> set1;

    while (N --> 0) {
        int temp; std::cin >> temp;
        set1.insert(temp);
    }

    std::vector<int> vec1(set1.begin(), set1.end());
    std::vector<int> vec2(vec1.size(), 0);
    vec2[vec2.size()-1] = 1; vec2[vec2.size()-2] = 1; vec2[vec2.size()-3] = 1;

    int max = 0;
    do{
        int temp = 0;
        for(int i=0; i<vec2.size(); i++) {
            if (vec2[i] == 1)
                temp += vec1[i];
        }
        if (temp == M) {
            max = temp;
            break;
        }
        else if (temp < M and max < temp)
            max = temp;
    } while(next_permutation(vec2.begin(), vec2.end()));
    std::cout << max;
}
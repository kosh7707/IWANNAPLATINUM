#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[26][26];
bool visited[26][26];
int N;
int _count = 0;

void dfs(int y, int x) {
    if (y >= 0 and y < N and x >= 0 and x < N)
    if (arr[y][x] == 1 and !visited[y][x]) {
        visited[y][x] = true;
        _count += 1;
        dfs(y, x+1);
        dfs(y, x-1);
        dfs(y+1, x);
        dfs(y-1, x);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N;
    for (int i=0; i<N; i++) {
        string temp; cin >> temp;
        for (int j=0; j<N; j++)
            arr[i][j] = temp[j] - '0';
    }

    vector<int> answer;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) {
            _count = 0;
            dfs(i, j);
            if (_count != 0) answer.push_back(_count);
        }

    sort(answer.begin(), answer.end());
    cout << answer.size() << endl;
    for (const auto& it : answer)
        cout << it << endl;
}
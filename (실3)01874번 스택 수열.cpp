#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> vec(N);
    for (int i=0; i<N; i++)
        cin >> vec[i];

    string answer;
    stack<int> st;
    int i=1, idx = 0;
    while (i <= N) {
        if (st.empty() || st.top() != vec[idx]) {
            answer += "+\n";
            st.push(i);
            i++;
        }
        while (!(st.empty()) and st.top() == vec[idx]) {
            answer += "-\n";
            idx++;
            st.pop();
        }
    }

    if (!(st.empty())) cout << "NO\n";
    else cout << answer;


}
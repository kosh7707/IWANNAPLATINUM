#include <iostream>
#include <stack>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; std::cin >> N;
    std::stack<int> st;
    int sum = 0;
    for (int i=0; i<N; i++) {
        int temp; std::cin >> temp;
        if (temp != 0) {
            st.push(temp);
        }
        else {
            st.pop();
        }
    }

    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }

    std::cout << sum;
}
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool ValidationCheck(const std::string& temp) {
    std::stack<char> st1;
    for (const auto& it : temp) {
        if (st1.empty()) {
            if (it == ')') return false;
            else st1.push(it);
        }
        else {
            if (st1.top() == '(' and it == ')') st1.pop();
            else st1.push(it);
        }
    }
    if (st1.empty()) return true;
    if (st1.size() != 2) return false;
    char temp1 = st1.top(); st1.pop();
    char temp2 = st1.top();
    if (temp1 == '(' and temp2 == ')') return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; std::cin >> N;

    while (N --> 0) {
        std::string temp; std::cin >> temp;
        if (ValidationCheck(temp)) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}
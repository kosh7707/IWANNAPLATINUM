#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string cmd;
    int N; std::cin >> N;
    std::stack<int> st;
    while (N --> 0) {
        std::cin >> cmd;
        if (cmd == "push") {
            int temp; std::cin >> temp;
            st.push(temp);
        }
        else if (cmd == "pop") {
            if (st.empty()) std::cout << "-1\n";
            else {
                std::cout << st.top() << std::endl;
                st.pop();
            }
        }
        else if (cmd == "size") {
            std::cout << st.size() << std::endl;
        }
        else if (cmd == "empty") {
            if (st.empty()) std::cout << "1\n";
            else std::cout << "0\n";
        }
        else if (cmd == "top") {
            if (st.empty()) std::cout << "-1\n";
            else {
                std::cout << st.top() << std::endl;
            }
        }
    }


}

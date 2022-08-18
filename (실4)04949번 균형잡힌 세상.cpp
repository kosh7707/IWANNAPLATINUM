#include <iostream>
#include <string>
#include <stack>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    while (true) {
        std::string str;
        std::getline(std::cin, str);
        if (str == ".")
            break;

        std::stack<char> bracket_stack;

        bool answer = true;
        for (const auto& it : str) {
            if (it == '(' or it == '[')
                bracket_stack.push(it);
            else if (it == ')' or it == ']') {
                if (!bracket_stack.empty()) {
                    if ( (it == ')' and bracket_stack.top() == '(') or (it == ']' and bracket_stack.top() == '[') )
                        bracket_stack.pop();
                    else {
                        answer = false;
                        break;
                    }

                }
                else {
                    answer = false;
                    break;
                }
            }
        }

        if (answer and bracket_stack.empty())
            std::cout << "yes\n";
        else
            std::cout << "no\n";

    }

}
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string exp; std::cin >> exp;
    std::vector<char> op;
    std::vector<int> number;

    int begin = 0;
    int n = 0;
    while (begin < exp.length()) {
        if (exp[begin+n] >= '0' and exp[begin+n] <= '9') {
            n++;
        }
        else {
            number.push_back(std::stoi(exp.substr(begin, n)));
            begin += n;
            n = 0;
            if (exp[begin] != '\0') {
                op.push_back(exp[begin]);
                begin++;
            }
        }
    }
    int sum = number[0];
    bool find_minus = false;
    for (int i=0; i<op.size(); i++) {
        if (op[i] == '-') {
            find_minus = true;
        }
        if (find_minus) sum -= number[i+1];
        else sum += number[i+1];
    }
    std::cout << sum;
}
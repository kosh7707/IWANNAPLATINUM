#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Customer {
    int number=0;
    int age=0;
    string name;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; std::cin >> N;

    std::vector<Customer> vec1(N);
    for (int i=0; i<N; i++) {
        Customer temp;
        temp.number = i;
        std::cin >> temp.age;
        std::cin >> temp.name;
        vec1[i] = temp;
    }
    std::sort(vec1.begin(), vec1.end(), [](const auto& it1, const auto& it2) -> bool {
        if (it1.age < it2.age) return true;
        else if (it1.age == it2.age and it1.number < it2.number) return true;
        return false;
    });
    for_each(vec1.begin(), vec1.end(), [](const auto& it) {
        std::cout << it.age << " " << it.name << "\n";
    });
}
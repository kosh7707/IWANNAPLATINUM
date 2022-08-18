#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    std::vector<int> birth_day = std::vector<int>(3);
};

Student make_student() {
    Student student;
    std::cin >> student.name;
    std::cin >> student.birth_day[0] >> student.birth_day[1] >> student.birth_day[2];
    return student;
}

bool comp(const Student& st1, const Student& st2) {
    if (st1.birth_day[2] < st2.birth_day[2])
        return true;
    else if (st1.birth_day[2] == st2.birth_day[2]) {
        if (st1.birth_day[1] < st2.birth_day[1])
            return true;
        else if (st1.birth_day[1] == st2.birth_day[1]) {
            if (st1.birth_day[0] < st2.birth_day[1])
                return true;
        }
    }
    return false;
}

int main() {
    int count;
    std::cin >> count;
    std::vector<Student> student(count);
    for (int i=0; i<count; i++) {
        student[i] = make_student();
    }

    auto youngest = *std::max_element(student.begin(), student.end(), comp);
    auto oldest = *std::min_element(student.begin(), student.end(), comp);

    std::cout << youngest.name << "\n" << oldest.name << "\n";

    return 0;
}
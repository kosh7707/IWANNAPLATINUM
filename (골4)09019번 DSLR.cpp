#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <queue>

using namespace std;

int commandD(int A) {
    A = (A*2)%10000;
    return A;
}

int commandS(int A) {
    A = (A == 0) ? 9999 : A-1;
    return A;
}

int commandL(int A) {
    int d1, d2, d3, d4, temp_d;
    d1 = A/1000; d2 = (A%1000)/100;
    d3 = (A%100)/10; d4 = (A%10);
    temp_d = d1;
    d1 = d2; d2 = d3;
    d3 = d4; d4 = temp_d;
    return d1*1000 + d2*100 + d3*10 + d4;
}

int commandR(int A) {
    int d1, d2, d3, d4, temp_d;
    d1 = A/1000; d2 = (A%1000)/100;
    d3 = (A%100)/10; d4 = (A%10);
    temp_d = d4;
    d4 = d3; d3 = d2;
    d2 = d1; d1 = temp_d;
    return d1*1000 + d2*100 + d3*10 + d4;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t --> 0) {
        int A, B; cin >> A >> B;
        bool visited[10000] = {false};
        visited[A] = true;
        string temp = "";
        queue<pair<int, string>> qu; qu.push({A, ""});
        int D, S, L, R, temp_A;
        while (true) {
            temp_A = qu.front().first;
            temp = qu.front().second;
            qu.pop();
            if (temp_A == B) {
                cout << temp << endl;
                break;
            }
            D = commandD(temp_A);
            if (!visited[D]) {
                qu.push({D, temp+"D"});
                visited[D] = true;
            }
            S = commandS(temp_A);
            if (!visited[S]) {
                qu.push({S, temp+"S"});
                visited[S] = true;
            }
            L = commandL(temp_A);
            if (!visited[L]) {
                qu.push({L, temp+"L"});
                visited[L] = true;
            }
            R = commandR(temp_A);
            if (!visited[R]) {
                qu.push({R, temp+"R"});
                visited[R] = true;
            }
        }

    }
}
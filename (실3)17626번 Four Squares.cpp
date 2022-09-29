#include <iostream>
#include <cmath>
using namespace std;

void brute_forcing(int N) {
    int sn = sqrt(N);
    for(int b=0; b<=sn; b++) {
        for(int c=b; c<=sn; c++) {
            for(int d=c; d<=sn; d++) {
                if(b*b+c*c+d*d==N) {
                    if(c==0) cout << 1;
                    else if(b==0) cout << 2;
                    else cout << 3;
                    exit(0);
                }
            }
        }
    }
    cout << 4;
}

void dp(int N) {
    int arr[50001] = {0, 1};
    for (int i=2; i<=N; i++) {
        if (arr[i] >= 4) continue;
        arr[i] = arr[i-1] + 1;
        for (int j=2; j*j<=i; j++)
            arr[i] = min(arr[i], arr[i-j*j] + 1);
    }
    cout << arr[N];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; cin >> N;
    // brute_forcing(N);
    dp(N);
}
#include <cstdio>


int main() {

    int h1, m1, s1;
    int h2, m2, s2;
    int t1, t2, ret;
    int h3, m3, s3;

    std::scanf("%d:%d:%d", &h1, &m1, &s1);
    std::scanf("%d:%d:%d", &h2, &m2, &s2);

    t1 = h1 * 3600 + m1 * 60 + s1;
    t2 = h2 * 3600 + m2 * 60 + s2;

    if (t1 > t2)
        t2 += 60*60*24;

    ret = t2 - t1;
    h3 = ret/3600;
    m3 = (ret%3600)/60;
    s3 = (ret%3600)%60;


    printf("%02d:%02d:%02d", h3, m3, s3);

    return 0;
}

#include "./euclidean_gcd.cpp"

#include <cstdio>
#include <cmath>

using namespace std;

bool find_one_solution(int a, int b, int c, int& x, int& y, int& g) {
    g = gcdWithCoef(abs(a), abs(b), x, y);
    if (c % g) {
        return false;
    }
    x *= c / g;
    y *= c / g;
    if (a < 0) {
        x = -x;
    }
    if (b < 0) {
        y = -y;
    }
    return true;
}

void shift(int& x, int& y, int a, int b, int count) {
    x += count * b;
    y -= count * a;
}

int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (!find_one_solution(a, b, c, x, y, g)) {
        return 0;
    }
    a /= g;
    b /= g;

    int sign_a = (a > 0)? 1 : -1;
    int sign_b = (b > 0)? 1 : -1;

    shift(x, y, a, b, (minx - x)/b);
    if (x < minx) {
        shift(x, y, a, b, sign_b);
    }
    if (x > maxx) {
        return 0;
    }
    int lx1 = x;

    shift(x, y, a, b, (maxx - x)/b);
    if (x > maxx) {
        shift(x, y, a, b, -sign_b);
    }
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}

int main() {
    
}
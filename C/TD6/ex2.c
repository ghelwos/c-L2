#include <stdio.h>

int ackermann(int m, int n);

int main(void) {
    printf("%d", ackermann(5, 5));
}

int ackermann(int m, int n) {
    if (m == 0) {
        return(n + 1);
    }
    else if (m > 0 && n == 0) {
        return(ackermann(m - 1, 1));
    }
    else if (m > 0 && n > 0) {
        return(ackermann(m - 1, ackermann(m, n - 1)));
    }
    else {
        return 0;
    }
}
#include <stdio.h>
#include <math.h>

int power(int base, int exponent)
{
    int result=1;
    for (exponent; exponent>0; exponent--)
        {
            result = result * base;
        }
    return result;
}

int reverse(int x) {
    if (x != 0) {
        int y = x, len;
        while (y != 0) {
            len++;
            y /= 10;
        }

        int res = 0;

        while (x != 0) {
            res += (x % 10) * power(10, len-1);
            x /= 10;
            len--;
        }

        return res;
    }
    return x;
}

int main() {
    int x = 123;
    printf("%d", reverse(x));

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int reverse(int rev, int num); // Function prototype

int main()
{
    int num = 1234;
    int rev = 0;
    int reversed;

    reversed = reverse(rev, num);
    printf("%d\n", reversed);

    return 0;
}

int reverse(int rev, int num) {
    if (num == 0) {
        return rev;
    } else {
        rev = rev * 10 + (num % 10);
        return reverse(rev, num / 10);
    }
}

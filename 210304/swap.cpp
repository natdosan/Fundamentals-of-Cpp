#include <cstdio>

// Does not swap
void swap1(int x, int y)
{
    int c = x;
    x = y;
    y = c;
}

void swap2(int *xp, int *yp)
{
    int c = *xp; // dereferences the pointer (gets the value)
    *xp = *yp;   // NOT xp = yp
    *yp = c;     // You also need * on the left side
}

// Do not do this
void swap3(int &x, int &y)
{
    int c = x;
    x = y;
    y = c;
}

// OK to use pass by reference when you dont want to make a copy
// Useful when the values being passed are large
void dump(const int &x, const int &y)
{ // const promises it wont change
}
int main()
{
    int a = 10, b = 20;
    printf("a = %d, b = %d\n", a, b);

    dump(a, b);

    // Does not swap
    swap1(a, b);
    dump(a, b);
    // printf("a = %d, b = %d\n", a, b);

    // Swaps, and it's clear the values can change
    swap2(&a, &b);
    dump(a, b);
    // printf("a = %d, b = %d\n", a, b);

    // Swaps, but it's not clear the value can change
    swap3(a, b);
    dump(a, b);
    // printf("a = %d, b = %d\n", a, b);

    // printf("%p, %ld\n", &a, &a);
}
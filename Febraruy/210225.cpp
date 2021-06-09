#include <iostream>

#include <cstdio>
#include <cstring>

int main()
{
    const char *s1 = "Hello";
    const char *s2 = "!";
    char *s3 = new char[0x100](); // new char is allocated space of 256 bytes; zero'd by the ()
    printf("s3 = '%s'\n", s3);    // empty
    strncat(s3, s1, strlen(s1));  // concatonates
    printf("s3 = '%s'\n", s3);
    strncat(s3, s2, strlen(s2)); // concatonates
    printf("s3 = '%s'\n", s3);
}
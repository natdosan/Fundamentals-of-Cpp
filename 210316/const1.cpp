#include <cstdio>

int main()
{ // The value is constant
  const int i1 = 100;
  int i2;
  // pointer whose contents can't be changed
  // pointer itself can be changed
  const int *i2p = &i2;
  i2p = nullptr;
  // can;t do *i2p = 200

  // Pointer whose contents of i3p can be changed
  // pointer itself cannot be altered
  int *const i3p = &i2;
  // can't do i3p = something else
  *i3p = 200;
  printf("i2 = %d\n", i2);

  // Neither pointer nor its contents can be changed
  const int *const i4p = nullptr;

  // "Constant C string"
  const char *msg = "annyeonghaseyo!";
  printf("%s\n", msg);
}

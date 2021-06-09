#include <iostream>

class Adder
{
private:
  int total;

public:
  // constructor
  Adder(int i = 0)
  {
    total = i;
  }

  void addNum(int num)
  {
    total += num;
  }

  int getTotal()
  {
    return total;
  }
};

int main()
{
  Adder a1;

  a1.addNum(10);
  printf("%d\n", a1);
  a1.addNum(20);
  printf("%d\n", a1);
  a1.addNum(30);
  printf("%d\n", a1);

  return 0;
}
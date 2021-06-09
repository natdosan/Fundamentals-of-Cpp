#include <cstdio>

// Pass by value
void inc1(double v)
{
  v++;
}

// Pass by ref, not preferable
void inc2(double &v)
{
  v++;
}

// Pass by pointer, best practice
void inc3(double *vp)
{
  (*vp)++;
}

int main()
{
  double e = 1;
  printf("#1: e = %lf\n", e); // 1
  inc1(e);
  printf("#1: e = %lf\n", e); // 1
  inc2(e);
  printf("#1: e = %lf\n", e); // 2
  inc3(&e);                   // parameters use &
  printf("#1: e = %lf\n", e); // 3

  // By reference
  double &ref = e;
  ref == 100;
  printf("#1: e = %lf\n", e); // 100

  // By pointer
  double *ep = &e;
  *ep = 200;
  printf("#1: e = %lf\n", e); // 200

  // Here, e changes by being referenced by the pointer; e does not directly change, but ep changes,
  // causing e itself to change

  double pi = 3.1459626;
  printf("%lf\n", pi);
  printf("%.2lf\n", pi);

  char buf[0x10]; // allocating 16 bytes
  sprintf(buf, "%.2lf", pi);
  double pillow;
  sscanf(buf, "%lf", &pillow);
  printf("%lf\n", pillow);
}
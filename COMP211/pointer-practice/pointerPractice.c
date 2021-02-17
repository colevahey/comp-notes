#include <stdio.h>

int main() {
  int a = 10;
  int* p;

  p = &a;

  printf("p = %p\n", p);
  printf("*p = %d = %d = a\n", *p, a);

  int b[] = {0, 1, 2, 3};
  int* p0 = b;
  int* p1 = b + 1;

  printf("b[0] = %d = %d = *p0\n", b[0], *p0);
  printf("b[1] = %d = *p1 = %d = *(p0 + 1) = %d\n", b[1], *p1, *(p0 + 1));
}

/*
  static linking:
    gcc -c addvec.c multvec.c
    ar rcs libvector.a addvec.o multvec.o

  dynamic linking:
    gcc -shared -fpic -o libvector.so addvec.c multvec.c
    gcc -o prog21 main2.o ./libvector.so
*/

int addcnt = 0;

void addvec(int *x, int *y, int *z, int n) {
  addcnt += 1;

  for (int i = 0; i < n; i++) {
    z[i] = x[i] + y[i];
  }
}
#include <stdio.h>

int main() {
  int taille = 10;
  int a[taille];
  for (int i=0; i<=10; i++){
    a[i] = 0;
    printf("%d \n", a[i]);
  }
  printf("%d", a);
}

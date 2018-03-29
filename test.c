#include <stdio.h>
#include <stdlib.h>

int main() {
  char *chara = malloc(sizeof(char));
  chara = "a";
  printf("%s \n", chara);
  printf("%d \n", atoi(chara));
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int main(void) {
  // time_t와 짝을 이루는 ctime 함수
  time_t t1;
  time(&t1);

  char *str1 = ctime(&t1);
  printf("ctime result: %s\n", str1);

  // struct tm과 짝을 이루는 asctime 함수
  struct tm *pTm;
  time_t t2;

  t2 = time(NULL);
  pTm = localtime(&t2);

  char *str2 = asctime(pTm);
  printf("asctime result : %s\n", str2);

  return 0;
}
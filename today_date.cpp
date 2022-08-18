#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main(void) {
  struct tm *t; // tm 구조체 : 인간이 알아볼 수 있게 세세하게 변수로 나누어져 만들어져있는 구조체
  string s = "";
  time_t timer; // 64비트 정수값으로 시간 불러옴
  // tm 구조체에 의해 년, 월, 일 에 맞는 시간 가져옴
  timer = time(NULL);// time() 현재 시간 반환

  t = localtime(&timer); // localtime() 현재시간을 struct tm에 넣기 
  s += to_string(t->tm_year + 1900);
  // tm_year은 1900년 부터 시작 (1900을 더해서 사용)
  s += "-";
  if (t->tm_mon + 1 < 10) {
    // tm_mon: 0 - 11월 ( +1을 해야 12월까지 )
    s+= "0";
  }
  s += to_string(t->tm_mon + 1);
  s += "-";
  if (t->tm_mday + 1 < 10) {
    s+= "0";
  }
  s += to_string(t->tm_mday);

  cout << s << endl;
  return 0;
}
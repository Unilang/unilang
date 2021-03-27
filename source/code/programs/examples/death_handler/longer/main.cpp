#include "death_handler.h"

void fun1();
void fun2();
void fun3();
void fun4(int i, int x);
void fun5();

void fun1(){
}
void fun2(){
    fun4(3,6);
}
void fun3(){
}
void fun4(int i, int x){
    fun5();
}
void fun5(){
  int* p = NULL;
  *p = 0;
}



int main() {
  Debug::DeathHandler dh;
  
  fun1();
  fun2();
  fun3();
  
  return 0;
}
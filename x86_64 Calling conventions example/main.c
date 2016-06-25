#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>

#include "test.h"

void hello(int i)
{
  exit(!printf("%s: Got %d\n",__func__, i));
  //exit(0);
}

int main() 
{
  int a = 10; 

  printf("Value from test_func %d (should be 1)\n", test_func()); 
  printf("Value from add_func %d (should be %d)\n", add_func(a, a), a+a); 
  switch_func(hello, 10);
  assert(!printf("Should not be here"));
  return 0; 
}

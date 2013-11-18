#include <iostream>
using namespace std;

extern "C" void testFunction(int a, int b){
  cout << a + b << endl;
}

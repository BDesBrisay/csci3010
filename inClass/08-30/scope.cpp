#include <iostream>
#include <string>

using namespace std;

// Names (be sure to include the initial of your last name(s)!):
// Bryce DesBrisay


// 1) Write a function that tests whether ints are pass-by-value or pass-by-reference
// (do not use pointers or c++ references in this function)
// Answer:

bool intRef(int i) {
  if (i == 5) return true;
  return false;
}

void int5(int i) {
  i = 5;
}


// 2) Write a function that tests whether strings (std::string) are pass-by-value or pass-by-reference
// (do not use pointers or c++ references in this function)
// Answer:

bool stringRef(string str) {
  if (str == "foo") return true;
  return false;
}

void stringFoo(string str) {
  str = "foo";
}


// 3) Write a function that tests whether arrays are pass-by-value or pass-by-reference
// recall: to initialize an array-- type name[] = {comma separated elements};
// (do not use pointers or c++ references in this function)
// Answer:

bool arrayRef(int arr[]) {
  if (arr[0] == 5) return true;
  return false;
}

void array123(int arr[]) {
  arr[0] = 5;
}


int main() {
  // code to test your functions goes here.
  int n = 1;
  string bar;
  int a[] = {1};

  // tries to change int to 5
  int5(n);
  // checks if int is actually changed
  cout << "Int by ref? " << intRef(n) << endl;
  cout << endl;

  // tries to change string to 'foo'
  stringFoo(bar);
  // checks if string is actually changed
  cout << "String by ref? " << stringRef(bar) << endl;
  cout << endl;


  // tries to change array to {1,2,3}
  array123(a);
  // checks if array is actually changed
  cout << "Array by ref? " << arrayRef(a) << endl;
  cout << endl;

  return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Names:
// David Dryja
// Bryce DesBrisay


// 1) implement two functions, AddToValues(std::vector<int> v1, int v2)
// and AddToValues(std::vector<double> v1, double v2)
vector<int> AddToValues(vector<int> v1, int v2) {
  for (int i = 0; i < v1.size(); i++) {
    cout << "i = "<< i << endl;
    v1[i] = v1[i] + v2;
  }
  return v1;
}

vector<double> AddToValues(vector<double> v1, double v2) {
  for (int i : v1) {
    v1[i] += v2;
  }
  return v1;
}

// 2) Do your AddToValues functions have return values? why/ why not?
// Answer:
//// YES, we made it return the new vector with values added


int main() {
    // 3) Instantiate an int vector
    vector<int> i = { 1, 2, 3 };

    // 4) call AddToValues, passing in your int vector and another int.
    vector<int> newV = AddToValues(i, 2);

    for (int i = 0; i < newV.size(); i++) {
      cout << "j = " << newV[i] << endl;
    }

    // 5) compile this file to object code (g++ -std=c++11 -Wall exercises.cpp -o exercises.o),
    // then run `nm -C exercises.o`. How many versions of the AddToValues function are in the
    // compiled object code? Copy + paste the relevant lines here:
    //
/*
      0000000000000210 T AddToValues(std::__1::vector<double, std::__1::allocator<double> >, double)
      0000000000000000 T AddToValues(std::__1::vector<int, std::__1::allocator<int> >, int)
*/
    // To making searching through the output easier, you can pipe the output of nm to grep
    // `nm -C exercises.o | grep "TextToFindHere"`
    //
    // If the -C flag isn't working, you can omit it and still complete the exercise--this flag
    // makes the output easier to read but isn't strictly necessary
}
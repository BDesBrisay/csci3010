#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Names:
// David Dryja
// Bryce DesBrisay

// 6) implement a templated version of AddToValues, "AddToValues2".

template <typename T>
vector<T> AddToValues2(vector<T> v1, T v2) {
  for (int i = 0; i < v1.size(); i++) {
    v1[i] = v1[i] + v2;
  }
  return v1;
}

struct IntField {
  int int_;

  IntField operator+(IntField i) {
    i.int_ = i.int_ + int_;
    return i;
  }
};

int main() {
    // 7) call AddToValues2, passing in an int vector and another int.
    
    vector<int> i = { 1, 2, 3 };

    vector<int> newV = AddToValues2(i, 2);

    for (int i = 0; i < newV.size(); i++) {
      cout << "int = " << newV[i] << endl;
    }

    // 8) compile this file to object code (g++ -std=c++11 -Wall exercises2.cpp -o exercises2.o),
    // then run `nm -C exercises2.o`. How many versions of the AddToValues2 function are in the
    // compiled object code? Copy + paste the relevant lines here:
    //
    // one version
    // 
    // 00000000000001c0 T std::__1::vector<int, std::__1::allocator<int> > AddToValues2<int>(std::__1::vector<int, std::__1::allocator<int> >, int)

    // 9) call AddToValues2, passing in a vector of a non-int type and a value that you can add
    // successfully to the elements

    vector<double> j = { 1.0, 2.5, 3.5 };

    vector<double> newV2 = AddToValues2(j, 2.5);

    for (int i = 0; i < newV2.size(); i++) {
      cout << "double = " << newV2[i] << endl;
    }

    // 10) compile this file to object code (g++ -std=c++11 -Wall exercises2.cpp -o exercises2.o),
    // then run `nm -C exercises2.o`. How many versions of the AddToValues2 function are in the
    // compiled object code? Copy + paste the relevant lines here:
    //
    // two versions
    // 00000000000005b0 T std::__1::vector<double, std::__1::allocator<double> > AddToValues2<double>(std::__1::vector<double, std::__1::allocator<double> >, double)
    // 0000000000000380 T std::__1::vector<int, std::__1::allocator<int> > AddToValues2<int>(std::__1::vector<int, std::__1::allocator<int> >, int)

    // 11) Experiment to find calls to this function that you would like to work but that do
    // not yet work. for each function call that doesn't work, comment about what type of 
    // error is produced.

    // vector<string> s = { "string" };
    // vector<string> newV3 = AddToValues2(s, "newStuff");
    // candidate template ignored: deduced conflicting types for parameter 'T' ('std::__1::basic_string<char>' vs. 'const char *')


    // 12) Create a struct that has an int field. Instantiate a vector of these structs.
    // Instantiate another instance of this struct.
    
    vector<IntField> if1{5};
    IntField if2 = { .int_ = 4 };


    // 13) Call AddToValues2 w/ the vector of structs and single struct from #12
    // Is there an error? If yes, what is it?
    //
    // Answer:
    // error: invalid operands to binary expression ('std::__1::__vector_base<IntField, std::__1::allocator<IntField> >::value_type' (aka 'IntField') and 'IntField')

    vector<IntField> newV3 = AddToValues2(if1, if2);

    for (int i = 0; i < newV3.size(); i++) {
      cout << "IntField = " << newV3[i].int_ << endl;
    }
    // 14) If there was an error, attempt to fix it.
}
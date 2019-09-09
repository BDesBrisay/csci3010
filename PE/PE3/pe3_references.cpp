#include <iostream>

// Name:
// Bryce DesBrisay

// Write any functions you need here!

void takePoint(int * i) {
  std::cout << i << std::endl;
}

void takeRef(int & i) {
  std::cout << i << std::endl;
}

void takeInOut(
  int const * i,
  int & j
) {
  std::cout << i << std::endl;
  std::cout << j << std::endl;
  return;
}

int main() {
    // Add as many prints to cout as you need to answer the questions.
    // Leave them in your code when you turn it in.
    // If you have lines of code that cause errors that test the questions,
    // leave this code in your file but comment it out.
    
    // 1) Declare an int

    int i = 0;

    // 2) Declare a pointer to that int

    int * j = & i;

    // 3) Increment the int via the pointer

    std::cout << i << ',' << j << std::endl;

    j++;

    std::cout << i << ',' << j << std::endl;

    // 4) Declare a reference to your int

    int & k = i;

    // 5) Increment the int via the reference

    k++;

    std::cout << i << ',' << j << ',' << k << std::endl;

    // 6) When you increment the int via the variable declared in #1, from which
    // variables can you see the changes?
    // Answer: 
      // i changes

    // 7) When you increment the int via the pointer declared in #2, from which
    // variables can you see the changes?
    // Answer: 
      // j changes

    // 8) When you increment the int via the reference declared in #4, from which
    // variables can you see the changes?
    // Answer: 
      // both i and k change

    // 9) Write a function that takes an int * parameter. How would you pass the 
    // variable from #1 into this function? (write the function call below)

    takePoint(&i);

    // 10) Can you pass your reference from #4 to the function from #9 without accessing its address?
    // Answer:
      // No

    // 11) Write a function that takes an int & parameter. How would you pass the 
    // variable from #1 into this function? (write the function call below)

    takeRef(i);

    // 12) Can you pass your pointer from #2 to the function from #11 without dereferencing it?
    // Answer:
      // No
      // must be passed as so: takeRef(*j);

    // 13) Can you pass your reference from #4 to the function from #11?
    // Answer:
      // Yes
      // takeRef(k) works

    // 14) Write a function that takes one const reference input parameter and one pointer
    // output parameter. The function should fill in the value of the output parameter based
    // on the value of the input parameter. (what it does exactly is up to you).
    // Call your function 3 times below. Be sure to include output as necessary to be sure
    // your function works as described.

    takeInOut(&i, *j);
    takeInOut(j, k);
    takeInOut(&k, i);

    // 15) What is/are the difference(s) between output parameters and return values?
    // Answer:
      // output parameters allow for multiple returned values while a return value only allows for one
}
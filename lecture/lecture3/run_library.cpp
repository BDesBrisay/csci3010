#include <iostream>
#include <vector>
#include "Library.h"

using namespace std;

// Name(s):
//
// Bryce DesBrisay
//
// Complete numbered coding tasks.
// Answer the questions with "Answer: " in the comments in the comments.
// Turn in run_library.cpp on Canvas before the end of class. (only this file!)

int main() {
    // 1) Instantiate a couple Books. Set their fields equal to some values.
    // Print out the values of the books" fields.

    Book b1;
    b1.title = "Harry Potter";
    b1.author = "JK Rowling";

    Book b2;
    b2.title = "How to Kick Ass";
    b2.author = "Johhny Cage";

    // 2) Instantiate a Library.

    Library lib;
   
    // 3) Add a void Donate(Book b) method to your Library class.
    // Your Library should store the new book at the end of its shelf.

    lib.Donate(b2);

    // 4) Donate one of the Books that you instantiated to your Library.
   
    lib.Donate(b1);

    // 5) Print out the books in the Library (use the given PrintBooks method)
    
    lib.PrintBooks();

    // 6) Change the title and/or author of the book that you donated to
    // something different.
    // Print out the new book information, then print out the books in your
    // Library. Did changing the Book information change it in your Library?
    //
    // Answer (and your hypothesis for why/why not):
      // Did not change title in library. 
      // This is because objects and custom structs are typically pass-by-value, not reference. 
      // So changing the title here won't change the title of the copy

    b2.title = "NEW AND IMPROVED TITLE";
    lib.PrintBooks();
    
    // 7) Create two Books that are separate structs (not pointers or references)
    // but that have the same information.
    // use the == operator to test if they are equal. What happens?
    // if it succeeds, are these equal?
    //
    // Answer: 
      // They are not equal. 
      // Structs cannot be compared with == so it will print out false. 
      // The title and authors when compared would be the same.

    Book b3;
    b3.title = "Harry Potter";
    b3.author = "JK Rowling";

    Book b4;
    b4.title = "Harry Potter";
    b4.author = "JK Rowling";

    // bool eval1 = b3 == b4;
    // cout << eval1 << endl;

    // 8) Create two Book references to your Books from # 7.
    // use the == operator to test if they are equal. What happens?
    // if it succeeds, are these equal?
    //
    // Answer: 
      // These are not equal because the original variables do not share the same address

    Book & b5 = b3;
    Book & b6 = b4;

    // bool eval2 = b5 == b6;
    // cout << eval2 << endl;

    // 9) Create two Book pointers to your Books from # 7.
    // use the == operator to test if they are equal. What happens?
    // if it succeeds, are these equal?
    //
    // Answer:
      // Not equal. Memory addresses are different

    Book * b7 = & b3;
    Book * b8 = & b4;

    // bool eval3 = b7 == b8;
    // cout << eval3 << endl;

    // 10) (Given in lecture)

    // Overloading: two or more functions with same name
    // void Donate(Book b)
    // void Donate(Book b, int copies)

    // overriding: reimplement a function from a base class (or abstract class/functon)
    // override the operator ==:
    bool operator==(const Book &other);

    // define this in the class
    bool Book::operator==(const Book &other) {
      // your custom eval function
    }

    // might have to define it as a friend rather than a member of the class
}
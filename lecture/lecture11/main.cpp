#include <iostream>

#include "Animal.h"

// Name(s): 
// Bryce DesBrisay
// David Dryja

int main() {

  Reptile ralph("alligator");
  // std::cout << ralph.MakeSound() << std::endl;

  // 1) Instantiate another animal 

  Bird chip("chip");

  // 2) Call the Fight method of animal

  chip.Fight(ralph);

  // 3) Go to the Animal.h file and define some new subclasses of animal
  // Define one class that inherits from Animal and
  // one class that inherits from a child class of Animal

    // DONE

  // 4) Instantiate at least one object of each class you defined for #3

  Parrot jake("parrot");

  // 5) Have a tournament between the animals that you have instantiated 

  jake.Fight(chip);
  jake.Fight(ralph);
  ralph.Fight(chip);

  // 6) turn in Animal.h and main.cpp on canvas
    
	return 0;
}
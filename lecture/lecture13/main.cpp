#include <iostream>
#include "Earth.h"

using namespace std;

// Names:
// Bryce DesBrisay
// David Dryja

int main(int argc, char **argv){
    // 0) Implement your Earth's constructor in Earth.cpp

      // DONE

    // 1) Get an instance of your earth object

    Earth& earth1 = Earth::GetInstance();

    // 2) Get another instance of your earth object

    Earth& earth2 = Earth::GetInstance();

    // 3) Test to see if the two Earth instances from #1 and #2 are stored at the same
    // location in memory.

    if (&earth1 == &earth2) {
      cout << "Same Planet" << endl;
    }
    else {
      cout << "Aliens!" << endl;
    }

    // 3) Call IncreasePopulation from one of your Earth instances. Can you see this change
    // from your other Earth instance?

    cout << earth2.get_population() << endl;

    earth1.IncreasePopulation();

    cout << earth2.get_population() << endl;

    // 4) Create a public field in your Earth object. Do you need an instance of an Earth object
    // to access this field?

    // DOES NOT WORK WITHOUT AN INSTANCE
    // cout << Earth::public_field_ << endl;
      // error: invalid use of non-static data member 'public_field_'

    cout << earth1.public_field_ << endl;

	return 0;
}
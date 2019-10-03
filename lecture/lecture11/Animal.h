#ifndef _ANIMAL_H_
#define _ANIMAL_H_

// Name(s):
// Bryce DesBrisay
// David Dryja

class Animal {
public:
	Animal(std::string sound):
	sound_(sound)
	{}

	std::string MakeSound() const {return sound_; }

	void Fight(Animal &opponent);

	virtual int GetPower() { return 0; };

private:
	std::string sound_;
};

class Reptile : public Animal {
public:
	Reptile(std::string sound):
	Animal(sound + " rawr!")
	{}


	int GetPower() { return 2; };

};

// Define your animals here.
// Define one class that inherits from Animal and
// one class that inherits from a child class of Animal

class Bird : public Animal {
public:
	Bird(std::string sound):
	Animal(sound + " chrip!")
	{}


	int GetPower() { return 0; };

};

class Parrot : public Bird {
public:
	Parrot(std::string sound):
	Bird(sound + " coo coo!")
	{}


	int GetPower() { return 1; };

};

#endif  // _ANIMAL_H_
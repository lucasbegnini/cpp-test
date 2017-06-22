#include <iostream>
#include <string>

using namespace std;
class Animal
{
public:
    Animal(){}
    string name;
    string sound;
    /// This is the function which will be called to reproduce the sound each
    /// animal makes.
    void makeSound();

	/// This is our factory. You need to code the missing implementation.
    static Animal* create(const std::string& name, Animal* animal);

	/// This function will terminate the class instance.
	static void destroy(Animal* animal)
	{
		delete animal;
	}
private:
};

// Write your classes here
void Animal::makeSound()
{
    cout << sound;
}
// This is the function you need to change in order to instantiate the required
// classes.
Animal* Animal::create(const std::string& _name, Animal* animal)
{
    //Convert to lowcase
   // transform(_name.begin(), _name.end(), _name.begin(), ::tolower);

    animal->name = _name;

    if(_name == "dog")
        animal->sound = "woof";
    else if(_name == "cat")
        animal->sound = "meow";
    else if(_name == "bird")
        animal->sound = "tweet";
    else if(_name == "mouse")
        animal->sound = "squeek";
    else if(_name == "cow")
        animal->sound = "moo";
    else if(_name == "frog")
        animal->sound = "croak";
    else if(_name == "elephant")
        animal->sound = "toot";
    else if(_name == "duck")
        animal->sound = "quack";
    else if(_name == "fish")
        animal->sound = "blub";
    else if(_name == "seal")
        animal->sound = "ow ow ow";

	return 0;
}

void makeSound(const std::string& name)
{
	// Create our instance
    Animal* animal;
    Animal::create(name,animal);

	animal->makeSound();

	// Destroy our instance
	Animal::destroy(animal);
}

int main(int argc, char** argv)
{
	int n = 0;
	std::cin >> n;

	while(n--)
	{
		std::string animal;

		std::cin.ignore();
		std::cin >> animal;

		makeSound(animal);
	}

	return 0;
}

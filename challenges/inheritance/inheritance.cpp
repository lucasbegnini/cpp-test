#include <iostream>
#include <string>

using namespace std;
class Animal
{
public:
    Animal(string _name="", string _sound =""){
        name = _name;
        sound = _sound;
    }
    /// This is the function which will be called to reproduce the sound each
    /// animal makes.
    void makeSound();

	/// This is our factory. You need to code the missing implementation.
    static Animal* create(const string &name);

	/// This function will terminate the class instance.
	static void destroy(Animal* animal)
	{
        delete animal;
	}
private:
    string name;
    string sound;
};

// Write your classes here
void Animal::makeSound()
{
    cout << sound << endl;
}
// This is the function you need to change in order to instantiate the required
// classes.
Animal* Animal::create(const string &_name)
{
    //Convert to lowcase
   // transform(_name.begin(), _name.end(), _name.begin(), ::tolower);
    string _sound;

    if(_name == "dog")
        _sound = "woof";
    else if(_name == "cat")
        _sound = "meow";
    else if(_name == "bird")
        _sound = "tweet";
    else if(_name == "mouse")
        _sound = "squeek";
    else if(_name == "cow")
        _sound = "moo";
    else if(_name == "frog")
        _sound = "croak";
    else if(_name == "elephant")
        _sound = "toot";
    else if(_name == "duck")
        _sound = "quack";
    else if(_name == "fish")
        _sound = "blub";
    else if(_name == "seal")
        _sound = "ow ow ow";
    Animal *animal = new Animal(_name, _sound);

    return animal;
}

void makeSound(const std::string& name)
{
	// Create our instance
    Animal* animal = Animal::create(name);

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

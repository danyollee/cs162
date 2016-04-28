#include <iostream>
#include <string>

using namespace std;

struct city{
	string name;
	int population;
	string style;
};

int main(){
	struct city Portland, *t;

	Portland.population=100;
	Portland.name="Portland";

	cout << Portland.population << endl;
	cout << Portland.name << endl;

	t=new city;
	t->population=100;
	cout << t->population << endl;

	/*city Portland;

	cout << "Enter a city name: ";
	getline(cin, Portland.name);

	cout << "Enter the city population: ";
	getline(cin, Portland.population);

	cout << "Enter the style of the city: ";
	getline(cin Portland.style);

	cout << Portland.name << endl;*/

	return 0;
}
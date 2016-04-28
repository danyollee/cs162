#include <iostream>
#include <string>

using namespace std;

class BuckysClass{
public:
	BuckysClass(string s){
		setName(s);
	}
	void setName(string x){
		name=x;
	}
	string getName(){
		return name;
	}
private:
	string name;
};

int main(){
	string asdf;
	cout << "Enter a name bro: ";
	getline(cin, asdf);
	BuckysClass bo(asdf);
	BuckysClass bo2(asdf);
	cout << bo.getName() << " " << bo2.getName() << endl;
	return 0;
}
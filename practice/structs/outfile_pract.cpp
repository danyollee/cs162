#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

	ofstream outFile;

	outFile.open("outfile.txt");

	outFile << "First number: " << 5 << endl;

	outFile.close();

	return 0;
}
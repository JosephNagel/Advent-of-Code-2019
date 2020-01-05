//This program is a simple addition program that reads numbers
//from a text document that represent fuel expenditures and adds them all up, displaying the sum.

#include <iostream>
#include <fstream>
using namespace std;


void fuelSum(); //fuelSum() initialization.




int main() {
	fuelSum();
}


void fuelSum() //fuelSum() definition.
{
	int mass = 0, fuel = 0, totFuel = 0;//Variable initialization.
	ifstream sum;
	sum.open("A:\\AOC(1).txt");//Opens file attatched to sum object.
	if (sum.fail()) //Lets user know if file hasn't opened.
	{
		cout << "\nError opening text document." << endl;
	}
	else
	{
		while (sum >> mass)//Had while(sum >> mass, !sum.eof()) but skipped first line this way.
		{
			fuel = (mass / 3) - 2;
			totFuel += fuel;
		}
		cout << fixed << "\n\nThe sum of the fuel expenditures is " << floor(totFuel) << endl;
	}

	sum.close();//closes file attatched to sum object.
}
/*This program solves for both part 1 and part 2 of the Advent of Code for 2019*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

/*This program completes part 1 of Advent of Code Day 2*/

void initialize(int array[], int array2[]); //Declaration of initialize() function;

int main()
{
	opcode();
}

void opcode()//Definition of opcode() function.
{
	int array[145] = { 0 }, array2[145] = { 0 }, array3[145] = { 0 };//Array to store opcode values in.
	int counter = 0;
	int num = 0;
	string line, line2, mystring, mystring2;
	ifstream intcode, opcodes;//File object.
	intcode.open("C:\\AOC_txt\\AOC(2).txt");
	

	

	if (intcode.fail())//File opening error warning.
	{
		cout << "\n\t\tThe document for intcode failed to open." << endl;
	}
	else {
		cout << "\n\t\tThe document was successfully opened." << endl;
		intcode >> line;
		istringstream iss(line);
		while (getline(iss, mystring, ','))//Loop to grab the integers from the list, ommitting the commas.
										   //Pulls integers out as a string, converts it to an integer.
		{
			num = stoi(mystring, nullptr, 10);
			array[counter] = num;
			array2[counter] = num;
			counter++;

		}
		counter = 0;

		array[1] = 12;
		array[2] = 2;
		while (array[counter] <= 144) {//List size = 145 integers. (Up to index 144).
			if (array[counter] == 1) {//Search opcode rules in Advent of Code 2019 Day 2.
				array[array[(counter + 3)]] = (array[array[(counter + 1)]] + array[array[(counter + 2)]]);
				counter += 4;
			}
			else if (array[counter] == 2) {//Search opcode rules in Advent of Code 2019 Day 2.
				array[array[(counter + 3)]] = (array[array[(counter + 1)]] * array[array[(counter + 2)]]);
				counter += 4;
			}
			else if (array[counter] == 99) {//Search opcode rules in Advent of Code 2019 Day 2.
				break;
			}


		}
		cout << "\n\t\tThe value at position 0 for array[1] = 12 and array[2] = 2 is: " << array[0] << endl;

		initialize(array, array2);
		
		for (int noun = 0; noun <= 99; noun++) {
			for (int verb = 0; verb <= 99; verb++) {

				counter = 0;

				array[1] = noun, array[2] = verb;

				while (array[counter] <= 144) {//List size = 145 integers. (Up to index 144).
					if (array[counter] == 1) {//Search opcode rules in Advent of Code 2019 Day 2.
						array[array[(counter + 3)]] = (array[array[(counter + 1)]] + array[array[(counter + 2)]]);
						counter += 4;
					}
					else if (array[counter] == 2) {//Search opcode rules in Advent of Code 2019 Day 2.
						array[array[(counter + 3)]] = (array[array[(counter + 1)]] * array[array[(counter + 2)]]);
						counter += 4;
					}
					else if (array[counter] == 99) {//Search opcode rules in Advent of Code 2019 Day 2.
						break;
					}

				}
				if (array[0] == 19690720)
				{
					cout << "\t\nThe pair of numbers that create an output of 19690720 are\nVerb: " << verb << "\nAnd Noun: " << noun << endl;
					cout << "100 * noun + verb: " << 100 * noun + verb << endl;
					noun = 100, verb = 100;
				}
				else
				{
					initialize(array, array2);
				}


			}

		}		
		intcode.close();
	}
}

void initialize(int array[], int array2[]) //Changes an array back to the initial state.
{
	for (int x = 0; x <= 144; x++)
	{
		array[x] = array2[x];
	}
}
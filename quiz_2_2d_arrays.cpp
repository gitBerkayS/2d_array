#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//function to start to header of the program
void programStart() {
	cout << setw(66) << left << "_________________________________________________________________" << endl;
	cout << setw(42) << right << "Water Depth Table" << endl;
	cout << setw(66) << left << "_________________________________________________________________" << endl;
}

//generating a random number
void generateRandomNum(int& num) {
	num = 1 + (rand() % 500);
}



int main() {
	//setting a time seed for random
	srand(time(NULL));

	int x, y, num = 0;
	float averageWaterDepthSC = 0, averageWaterDepthSolo = 0, averageWaterDepthHH = 0, averageWaterDepthSav = 0, averageWaterDepthSeven = 0, averageWaterDepthTwelve = 0, averageWaterDepthFive = 0, averageWaterDepthNine = 0;
	float temps = 0.00, biggestDepth = 0, smallestDepth = 0;

	//making the 2d array
	string waterDepthTable[5][5]{
	{"", "7:00", "12:00", "5:00", "9:00" },
	{"Surf City", "0", "0", "0", "0" },
	{"Solomons", "0", "0", "0", "0" },
	{"Hilton Head", "0", "0", "0", "0"},
	{"Savannah", "0", "0", "0", "0" }
	};

	//caling the function created earlier.
	programStart();
	
	//basic for loop to display array
	for (x = 0; x < 5; x++) {
		for (y = 0; y < 5; y++) {
			generateRandomNum(num);
			if (waterDepthTable[x][y] == "0") {
				waterDepthTable[x][y] = to_string(num);
			}
			cout << setw(15) << left << waterDepthTable[x][y] << " ";
		}
		cout << endl;
	}
	
	//adding up all the values along the y axis, storing them in one value.
	for (y = 1; y < 5; y++) {
		temps += stof(waterDepthTable[1][y]);
	}
	averageWaterDepthSC = temps /4;
	temps = 0;

	for (y = 1; y < 5; y++) {
		temps += stof(waterDepthTable[2][y]);
	}
	averageWaterDepthSolo = temps / 4;
	temps = 0;

	for (y = 1; y < 5; y++) {
		temps += stof(waterDepthTable[3][y]);
	}
	averageWaterDepthHH = temps / 4;
	temps = 0;

	for (y = 1; y < 5; y++) {
		temps += stof(waterDepthTable[4][y]);
	}
	averageWaterDepthSav = temps / 4;
	temps = 0;

	//adding up all the values along the x axis, storing them in one value.
	for (x = 1; x < 5; x++) {
		temps += stof(waterDepthTable[x][1]);
	}
	averageWaterDepthSeven = temps / 4;
	temps = 0;

	for (x = 1; x < 5; x++) {
		temps += stof(waterDepthTable[x][2]);
	}
	averageWaterDepthTwelve = temps / 4;
	temps = 0;

	for (x = 1; x < 5; x++) {
		temps += stof(waterDepthTable[x][3]);
	}
	averageWaterDepthFive = temps / 4;
	temps = 0;

	for (x = 1; x < 5; x++) {
		temps += stof(waterDepthTable[x][4]);
	}
	averageWaterDepthNine = temps / 4;
	temps = 0;

	//temp value starts at 0. if checked value is > 0 then gets stored. if next value is greater than the one stored then it is replaced into temp, else nothing gets stored.
	temps = 0;
	for (x = 1; x < 5; x++) {
		for (y = 1; y < 5; y++) {
			if (stof(waterDepthTable[x][y]) > temps) {
				temps = stof(waterDepthTable[x][y]);
			}
		}
	}
	biggestDepth = temps;

	//This time temp starts at 500 to check for numbers that are lower than it self. if it finds one, the loop stores such number in temps, untill we find the lowest one.
	temps = 500;
	for (x = 1; x < 5; x++) {
		for (y = 1; y < 5; y++) {
			if (stof(waterDepthTable[x][y]) < temps) {
				temps = stof(waterDepthTable[x][y]);
			}
		}
	}
	smallestDepth = temps;


	//averaging out the depths
	cout << "Average water depth for Surf City is " << averageWaterDepthSC / 4 << endl;
	cout << "Average water depth for Solomons is " << averageWaterDepthSolo / 4 << endl;
	cout << "Average water depth for Hilton is " << averageWaterDepthHH / 4 << endl;
	cout << "Average water depth for Savannah is " << averageWaterDepthSav / 4 << endl;
	cout << "Average water depth for 7:00 is " << averageWaterDepthSeven / 4 << endl;
	cout << "Average water depth for 12:00 is " << averageWaterDepthTwelve / 4 << endl;
	cout << "Average water depth for 5:00 is " << averageWaterDepthFive / 4 << endl;
	cout << "Average water depth for 9:00 is " << averageWaterDepthNine / 4 << endl;
	cout << "\n";

	cout << "The biggest water depth is " << biggestDepth << endl;
	cout << "The smallest water depth is " << smallestDepth << endl;

	
		
	
	

}


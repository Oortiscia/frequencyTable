#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

// Bubble sort
void bubbleSort(int numberList[], int arrSize) {

	int temp{0};


	for (int i= 0; i < arrSize; i += 1) {
		bool swapped{false};
		for (int j = 0; j < (arrSize) -i -1; j +=1){

			if (numberList[j]> numberList[j+1]) {

				temp = numberList[j+1];
				numberList[j+1] = numberList[j];
				numberList[j]= temp;
				swapped = true;
			}
		}

		if (!swapped) {break;}	
	}
}

int main() {
	int size;
	cout << "\n Enter the size of your data: ";
	cin >> size;  // size of our dataSet array.

	int dataSet[size]{};  // our dataSet.
	cout << "\n Enter the population values separated by spaces:\n";
	for (int i = 0; i < size; i++) cin >> dataSet[i];  // inputing data.

	bubbleSort(dataSet, size);  // sorting for future comfort.

	int min = dataSet[0];
	int max = dataSet[size - 1];  // index of the last member.
	int R{max - min};

	int k;  // number of rows.
	cout << "\n Enter number of intervals (k): ";
	cin >> k;

	double c = ceil(static_cast<double>(R) / k);  // rounding c.

	cout << "\n\n_________________________________________________________________"
		"\n";
	cout << "\n  Frequency Distribution\n\n";
	cout << "_________________________________________________________________\n";
	cout << left << setw(16) << "Interval" << right << setw(8) << "fi"
		<< setw(8) << "Fi" << setw(10) << "fci" << setw(10) << "Fci" << endl;
	cout << "_________________________________________________________________\n";

	int Fi = 0;  // frequency.

	cout << fixed
		<< setprecision(
				3);  // making this table was harder than the algorithm.

	int fiCount[k]{};  // having them stored somewhere so that i can find the
			   // largest and calculate stuff&thangs.

	int LMode{};  // real low limit of the row containing Mode.

	for (int i = 0; i < k;
			i++) {  // each iteration in this loop takes us to the next row.
		double intervalMin = min + (i * c);
		double intervalMax =
			(i == k - 1) ? max
			: intervalMin + c;  // i like conditional operator.
		int count{0};

		for (int j = 0; j < size; j++) {
			if (i == k - 1) {  // for the last iteration1.
				if (dataSet[j] >= intervalMin && dataSet[j] <= intervalMax) {
					count++;
					fiCount[i] = count;
				}
			} else {
				if (dataSet[j] >= intervalMin && dataSet[j] < intervalMax) {
					count++;
					fiCount[i] = count;
					// this line is iterated for xCount times
					// for every i but it works doesn't it?
				}
			}
		}

		Fi += count;  // another bunch of frequencies.
		double fci = static_cast<double>(count) / size;
		double Fci = static_cast<double>(Fi) / size;

		string intervalStr = "[" + to_string((int)intervalMin) +
			" - " +  // i didn't do this part.
			to_string((int)intervalMax) +
			(i == k - 1 ? "]" : ")");

		cout << left << setw(16) << intervalStr << right << setw(8) << count
			<< setw(8) << Fi << setw(10) << fci << setw(10) << Fci << setw(10)
			<< endl;
	}

	bubbleSort(fiCount, k);
	short rowWithMode = fiCount[k - 1];

	cout << " \nTotal data count: " << size << endl;
	cout << endl << "\nfi row with Mode: " << rowWithMode << endl;
}

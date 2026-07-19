#include <cmath>
#include <iomanip>
#include <iostream>

#include "utils/bubbleSort.hpp"
#include "utils/getDataset.hpp"

using namespace std;

int main() {
	vector<double> dataSet = get_dataset();  // our dataSet.
	int size = static_cast<int>(dataSet.size());

	bubbleSort(dataSet.data(), size);  // sorting for future comfort.

	double min = dataSet[0];
	double max = dataSet[size - 1];  // index of the last member.
	double R{max - min};

	int k;  // number of rows.
	cout << "\n Enter number of intervals (k): ";
	cin >> k;

	// if the number of intervals is bigger than the dataset,
	// the program still works but it doesn't make sense to have more intervals than data points. 
	bool eligibleK = (k > 0 && k <= size);
	if (!eligibleK) {
		cout << "\n\nInvalid number of intervals. want to continue?\n\n y/n: ";
		char input{' '};
		cin >> input;
		if (input != 'y' && input != 'Y') {
			cout << "\nprogram exited with code 2";
			return 1;
		} 
	}

	double c = ceil(R / k);  // rounding c.

	cout << "\n\n_________________________________________________________________"
		"\n";
	cout << "\n  Frequency Distribution\n\n";
	cout << "_________________________________________________________________\n";
	cout << left << setw(16) << "Interval" << right << setw(8) << "fi"
		<< setw(8) << "Fi" << setw(10) << "fci" << setw(10) << "Fci" << endl;
	cout << "_________________________________________________________________\n";

	int Fi = 0;  // frequency.

	cout << fixed
		<< setprecision(3);  // making this table was harder than the algorithm.

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

	short rowWithMode = fiCount[k - 1];

	cout << " \nTotal data count: " << size << endl;
	cout << endl << "\nfi row with Mode: " << rowWithMode << endl;
}

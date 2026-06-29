
// Bubble sort
void bubbleSort(double numberList[], int arrSize) {

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

//==============================================
// Name:           Mikhail Frolov
// Student Number: 164788184
// Email:          mfrolov@myseneca.ca
// Section:        NZB
// Workshop:       3 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>
#define NUMS 4
int main(void) {
	printf("---=== IPC Temperature Analyzer ===---"); //title

	int i, high, low; // stores as int
	int largest = -41, lowest = 41, hDay = 0, lDay = 0;
	double totalhigh = 0, totallow = 0, avrgtotal = 0, avrgH, avrgL; //stores as double
	
	for (i=0; NUMS>i ; i++) { //repeats i until i<NUMS
		printf("\nEnter the high value for day %d: ", i + 1); //asks user for input and adds one more value to i
		scanf("%d", &high); // scans and stores as high
		printf("\nEnter the low value for day %d: ", i + 1);
		scanf("%d", &low);

		while (high < low || high > 40 || low < -40) { // will execute if one or more conditions isn't met
			printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");

			printf("\nEnter the high value for day %d: ", i + 1); //asks user for input and adds one more value to i
			scanf("%d", &high); // scans and stores as high
			printf("\nEnter the low value for day %d: ", i + 1);
			scanf("%d", &low);
	    }

		totallow = totallow + low;
		totalhigh = totalhigh + high;

		if (high > largest) { // if condition to define the largest temp. and day
			largest = high;  
			hDay = i + 1;
		}
		if (low < lowest) {
			lowest = low;
			lDay = i + 1;
		}
	}
	avrgL = totallow / 4;
    printf("\nThe average (mean) LOW temperature was: %.2lf\n", avrgL);
	avrgH = totalhigh / 4;
	printf("The average (mean) HIGH temperature was: %.2lf\n", avrgH);
	
	avrgtotal = (totallow + totalhigh) / 8;
	printf("The average (mean) temperature was: %.2lf\n", avrgtotal);

	printf("The highest temperature was %d, on day %d\n", largest, hDay);
	printf("The lowest temperature was %d, on day %d\n", lowest, lDay);

	return 0;
}
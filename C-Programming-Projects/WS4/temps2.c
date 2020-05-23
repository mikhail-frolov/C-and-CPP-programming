//==============================================
// Name:           Mikhail Frolov
// Student Number: 164788184
// Email:          mfrolov@myseneca.ca
// Section:        NZB
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>

int main(void) {
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	int nums, high[10], low[10], days = 0, dn = -1, highest = -9999, lowest = 9999, hday = 0, lday = 0;

	double average = 0;

	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &nums);

	while (nums < 3 || nums>10) {

		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &nums);

	}

	int i = 0;

	printf("\n");

	for (i = 0; i < nums; i++) {

		printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);

		printf("Day %d - Low: ", i + 1);
		scanf("%d", &low[i]);

		if (i > dn) {

			dn = i + 1;

		}

		if (high[i] > highest) {

			highest = high[i];

			hday = i + 1;

		}

		if (low[i] < lowest) {

			lowest = low[i];

			lday = i + 1;

		}
	}

	printf("\nDay  Hi  Low\n");

	for (i = 0; i < nums; i++) {

		printf("%d    %d    %d\n", i + 1, high[i], low[i]);

	}

	printf("\n");

	printf("The highest temperature was %d, on day %d\n", highest, hday);

	printf("The lowest temperature was %d, on day %d\n", lowest, lday);

	printf("\n");


	int keepgoing = 1;
	printf("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", dn);
	while (keepgoing > 0) {
		scanf("%d", &days);
		if (days >= 1 && days <= dn) {
			int a = 0;

			for (a = 0; a < days; a++) {
				average += high[a] + low[a];
		    }
			average /= (days * 2);
			printf("\nThe average temperature up to day %d is: %.2f\n", days, average);
			printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", dn);
			average = 0;
		}
		else if (days < 0) {
			printf("\nGoodbye!\n");
			break;
		}
		else {
			printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", dn);
		}
	}

	return 0;
}
 
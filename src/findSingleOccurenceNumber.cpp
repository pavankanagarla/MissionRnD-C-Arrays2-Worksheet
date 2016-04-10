/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
#include<stdlib.h>
int findSingleOccurenceNumber(int *A, int len) {
	int *a = (int*)malloc((len / 3 + 1) * sizeof(int));
	int i;
	int j;
	int counter = -1;
	int totalsum = 0;
	int unique_sum = 0;
	if (A == nullptr || len <= 0)
		return -1;
	for (i = 0; i < len; i++){
		for (j = 0; j <= counter; j++){
			if (a[j] == A[i]){
				break;
			}
		}
		if (j > counter){
			counter++;
			a[counter] = A[i];
			unique_sum += A[i];
		}
		totalsum += A[i];
	}
	counter = (unique_sum * 3) - totalsum;
	return counter / 2;
}
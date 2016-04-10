/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int comparedates(transaction Y, transaction Z){
	int dt1;
	int month1;
	int year1;
	int dt2;
	int month2;
	int year2;
	dt1 = (Y.date[0] - '0') * 10 + (Y.date[1] - '0');
	month1 = (Y.date[3] - '0') * 10 + (Y.date[4] - '0');
	year1 = (Y.date[6] - '0') * 1000 + (Y.date[7] - '0') * 100 + (Y.date[8] - '0') * 10 + (Y.date[9] - '0');
	dt2 = (Z.date[0] - '0') * 10 + (Z.date[1] - '0');
	month2 = (Z.date[3] - '0') * 10 + (Z.date[4] - '0');
	year2 = (Z.date[6] - '0') * 1000 + (Z.date[7] - '0') * 100 + (Z.date[8] - '0') * 10 + (Z.date[9] - '0');
	if (year1 < year2){
		return 1;
	}
	else if (year1 > year2){
		return 2;
	}
	else if (year1 == year2){
		if (month1 < month2){
			return 1;
		}
		else if (month1 > month2){
			return 2;
		}
		else if (month1 == month2){
			if (dt1 < dt2){
				return 1;
			}
			else if(dt1 > dt2){
				return 2;
			}
		}
	}
	return 0;
}
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	struct transaction *result = (struct transaction*) malloc((ALen + BLen) * sizeof(struct transaction));
	int a_counter = 0;
	int b_counter = 0;
	int i = 0;
	int j;
	int temp;
	if (A == NULL || ALen <= 0 || B == NULL || BLen <= 0)
		return NULL;
	while (a_counter < ALen && b_counter < BLen){
		temp = comparedates(A[a_counter], B[b_counter]);
		if (temp == 2){
			result[i] = B[b_counter];
			b_counter++;
			i++;
		}
		else if (temp == 1){
			result[i] = A[a_counter];
			a_counter++;
			i++;
		}
		else{
			result[i] = A[a_counter];
			i++;
			result[i] = B[b_counter];
			a_counter++;
			b_counter++;
			i++;
		}
	}
	if (a_counter == ALen){
		while (b_counter < BLen){
			result[i] = B[b_counter];
			b_counter++;
			i++;
		}
	}
	else{
		while (a_counter < ALen){
			result[i] = A[a_counter];
			a_counter++;
			i++;
		}
	}
	return result;
}
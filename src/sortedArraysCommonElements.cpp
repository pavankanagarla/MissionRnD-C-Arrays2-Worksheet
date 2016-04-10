/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int compare(transaction Y, transaction Z){
	int i;
	for (i = 0; i < 10; i++){
		if (Y.date[i] != Z.date[i])
			return 0;
	}
	return 1;
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	struct transaction *result = (struct transaction *) malloc(ALen * sizeof(struct transaction));
	int counter = -1;
	int i;
	int j;
	if (A == NULL || ALen <= 0 || B == NULL || BLen <= 0)
		return NULL;
	for (i = 0; i < ALen; i++){
		for (j = 0; j < BLen; j++){
			if (compare(A[i], B[j])){
				result[++counter] = A[i];
				break;
			}
		}
	}
	if (counter == -1)
		return NULL;
	return result;
}
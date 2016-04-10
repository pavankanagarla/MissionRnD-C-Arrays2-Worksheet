/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (Arr == nullptr || date == nullptr || len <= 0)
		return -1;
	int dt;
	int month;
	int year;
	int dt1;
	int month1;
	int year1;
	int i = 0;
	int count = 0;
	dt = (date[0] - '0') * 10 + (date[1] - '0');
	month = (date[3] - '0') * 10 + (date[4] - '0');
	year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
	while (i < len)
	{
		dt1 = (Arr[i].date[0] - '0') * 10 + (Arr[i].date[1] - '0');
		month1 = (Arr[i].date[3] - '0') * 10 + (Arr[i].date[4] - '0');
		year1 = (Arr[i].date[6] - '0') * 1000 + (Arr[i].date[7] - '0') * 100 + (Arr[i].date[8] - '0') * 10 + (Arr[i].date[9] - '0');
		if (year1 > year){
			count++;
		}
		else if (year1 == year){
			if (month1 > month){
				count++;
			}
			else if (month1 == month){
				if (dt1 > dt){
					count++;
				}
			}
		}
		i++;
	}
	return count;
}

#include "Date.h"

int main() 
{
	Date d1(2025,12,4);
	Date d2(2004, 2, 11);

	cout << d1 << d2 << endl;
	cin >> d2 >> d1;
	cout << endl << d2 - d1;


	const Date d(2025, 2, 4);

	return 0;
}
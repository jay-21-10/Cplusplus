#pragma once
#include <iostream>
using namespace std;

class Date
{
	//友元函数声明
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	Date(int year = 2025, int month = 1, int day = 1);

	bool CheckDate() 
	{
		if (_month <= 12 && _month >= 1 && _day <= GetMonthDay(_year, _month) && _day >= 1)
		{
			return true;
		}
		return false;
	}

	static bool IsLeapYear(int year) {
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
	static int GetMonthDay(int year,int month)
	{
		static int monthDayArr[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && IsLeapYear(year))
		{
			return 29;
		}
		return monthDayArr[month];
	}

	int ToDays() const
	{
		int days = 0;
		for (int i = 1; i < _year; i++)
		{
			days += IsLeapYear(i) ? 366 : 365;
		}
		for (int j = 1; j < _month; j++)
		{
			days += GetMonthDay(_year, j);
		}
		days += _day;
		return days;
	}

	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator>(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;

	Date& operator+=(int day);
	Date& operator-=(int day);

	Date& operator++();		// 前置 返回加之后的值 
	Date operator++(int);	// 后置 返回加之前的值

	Date operator+(int day)const;
	Date operator-(int day)const;

	int operator-(const Date& d)const;
	
private:
	int _year;
	int _month;
	int _day;
};  

inline ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}


inline istream& operator>>(istream& in, Date& d)
{
	while(1)
	{
		cout << "请依次输入年月日：>";
		in >> d._year >> d._month >> d._day;
		if (!d.CheckDate())
		{
			cout << "输入的日期非法：" << d;
			cout << "请重新输入";
		}
		else {
			break;
		}
	}
	return in;
}
#include "Date.h"


Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;

	if (!CheckDate())
	{
		cout << "非法日期:" << *this;
	}
}

Date& Date::operator+=(int day)
{
	if (day < 0) return *this -= (-day);
	_day += day;
	while (_day > GetMonthDay(_year,_month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13) {
			_year++;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator+(int day)const
{
	Date tmp = *this;
	return tmp += day;
}

Date& Date::operator-=(int day)
{
	if (day < 0) return *this += (-day);
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0) {
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}


Date Date::operator-(int day)const
{
	Date tmp = *this;
	return tmp -= day;
}

int Date::operator-(const Date& d) const
{
	return ToDays() - d.ToDays();
}

bool Date::operator<(const Date& d)const
{
	if (_year < d._year)return true;
	else if (_year > d._year)return false;
	else {
		if (_month < d._month)return true;
		else if (_month > d._month)return false;
		else return _day < d._day;
	}
}

bool Date::operator<=(const Date& d)const
{
	return *this < d || *this == d;
}

bool Date::operator>(const Date& d)const
{
	return !(*this <= d);
}

bool Date::operator>=(const Date& d)const
{
	return *this > d || *this == d;
}

bool Date::operator==(const Date& d) const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

Date& Date::operator++() 
{
	return *this += 1;
}

Date Date::operator++(int) 
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}


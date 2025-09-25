#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string>
#include "date.hpp"

namespace util {

    Date::Invalid::Invalid(int day, int month, int year) {
        bad_day = day;
        bad_month = month;
        bad_year = year;
    }

    Date::Date () {
        _day = 1;
        _month = 1;
        _year = 1970;
    };

    Date::Date (int day, int month, int year) {
        if (!isValid(day, month, year)) {
            throw Invalid(day, month, year);
        }

        _day = day;
        _month = month;
        _year = year;
    }

    void Date::day(int day) {
        if (!isValid(day, _month, _year)) {
            throw Invalid(day, _month, _year);
        }

        _day = day;
    }
    int Date::day () const{
        return _day;
    }

    void Date::month(int month) {
        if (!isValid(_day, month, _year)) {
            throw Invalid(_day, month, _year);
        }

        _month = month;
    }

    int Date::month () const{
        return _month;
    }

    std::string Date::monthName () const{
        return whatMonth(_month);
    }

    std::string Date::dayName () const{
        return whatDay(_day, _month, _year);
    }

    void Date::year(int year) {
        if (!isValid(_day, _month, year)) {
            throw Invalid(_day, _month, year);
        }

        _year = year;
    }
    int Date::year () const{
        return _year;
    }

    Date Date::now() {
        time_t t = time(NULL);
        tm currentDay = *localtime(&t);

        return Date(currentDay.tm_mday, currentDay.tm_mon + 1, currentDay.tm_year + 1900);
    }

    void Date::advance(int days) {
        tm advanceANumberOfDays= {};
        advanceANumberOfDays.tm_mday = _day;
        advanceANumberOfDays.tm_mon = _month - 1;
        advanceANumberOfDays.tm_year = _year - 1900;
        time_t t = mktime(&advanceANumberOfDays);

        t += days*24*60*60;

        tm updated = *localtime(&t);

        _day = updated.tm_mday;
        _month = updated.tm_mon + 1;
        _year = updated.tm_year + 1900;
    }

    void Date::print (std::ostream& os) const{
        if (order == Order::MonthDayYear) {
            os << _month << separator << _day << separator << _year;
        }
        else if (order == Order::DayMonthYear) {
            os << _day << separator << _month << separator << _year;
        }
        else {
            os <<  _year << separator << _month << separator << _day;
        }
    }

    Date::Order Date::order = Date::Order::MonthDayYear;
    char Date::separator = '/';

    std::string Date::whatMonth(int month) {
        switch (month) {
            case 1: return "January";
            case 2: return "February";
            case 3: return "March";
            case 4: return "April";
            case 5: return "May";
            case 6: return "June";
            case 7: return "July";
            case 8: return "August";
            case 9: return "September";
            case 10: return "October";
            case 11: return "November";
            case 12: return "December";
            default: return "Invalid";
        }
    }

    std::string Date::whatDay(int day, int month, int year) {
        tm currentDay = {};
        currentDay.tm_mday = day;
        currentDay.tm_mon = month - 1;
        currentDay.tm_year = year - 1900;

        mktime(&currentDay);

        switch (currentDay.tm_wday) {
            case 0: return "Sunday";
            case 1: return "Monday";
            case 2: return "Tuesday";
            case 3: return "Wednesday";
            case 4: return "Thursday";
            case 5: return "Friday";
            case 6: return "Saturday";
            default: return "Invalid";
        }
    }

    bool Date::isValid(int day, int month, int year) {
        if (year < 1900 || month < 1 || month > 12 || day < 1) {
            return false;
        }

        tm validDate = {};
        validDate.tm_mday = day;
        validDate.tm_mon = month - 1;
        validDate.tm_year = year - 1900;

        mktime(&validDate);

        return (validDate.tm_mday == day &&
                validDate.tm_mon == month - 1 &&
                validDate.tm_year == year - 1900);
    }




}


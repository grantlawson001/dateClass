#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "date.hpp"

namespace util {

    Date::Invalid::Invalid(int day, int month, int year) {
        bad_day = day;
        bad_month = whatMonth(month);
        bad_year = year;
    }

    Date::Date () {
        _day = 1;
        _month = 1;
        _year = 1970;
    };

    Date::Date (int day, int month, int year) {
        _day = day;
        _month = month;
        _year = year;
    }
    void Date::setDay(int day) {
        _day = day;
    }
    int Date::getDay () {
        return _day;
    }

    void Date::setMonth(int month) {
        _month = month;
    }
    std::string Date::getMonth () const{
        return whatMonth(_month);
    }

    void Date::setYear(int year) {
        _year = year;
    }
    int Date::getYear () const{
        return _year;
    }

    void Date::now() {
        time_t t = time(NULL);
        tm currentDay = *localtime(&t);
        _day = currentDay.tm_mday;
        _month = currentDay.tm_mon + 1;
        _year = currentDay.tm_year + 1900;
    }

    void Date::advance() {
        time_t t = time(NULL);
        t += 1*24*60*60;
        tm currentDayAddOne = *localtime(&t);
        _day = currentDayAddOne.tm_mday;
    }
    void Date::advance(int days) {
        time_t t = time(NULL);
        t += days*24*60*60;
        tm advanceANumberOfDays = *localtime(&t);
        _day = advanceANumberOfDays.tm_mday;
        _month = advanceANumberOfDays.tm_mon + 1;
        _year = advanceANumberOfDays.tm_year + 1900;
    }
    void Date::print () const{
        std::cout << _month << "/" << _day << "/" << _year;
    }

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


}

int main () {
    util::Date d;
    d.print();
}
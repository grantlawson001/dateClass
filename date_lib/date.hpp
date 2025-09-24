#ifndef DATE_LIBRARY_H
#define DATE_LIBRARY_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

namespace util {

    class Date {
    public:
        struct Invalid {
            int bad_day;
            int bad_month;
            int bad_year;

            Invalid(int day, int month, int year);
        };

        Date ();

        Date (int day, int month, int year);

        void setDay(int day);
        int getDay () const;

        void setMonth(int month);
        std::string getMonth () const;

        void setYear(int year);
        int getYear () const;

        void now();

        void advance(int days = 1);

        enum class Order {
            MonthDayYear,
            DayMonthYear,
            YearMonthDay
        };

        void print () const;

        static Order order;
        static char separator;

    private:
        int _day, _month, _year;

        static std::string whatMonth (int month);

        static bool isValid(int day, int month, int year);

    };

}

#endif // DATE_LIBRARY_H
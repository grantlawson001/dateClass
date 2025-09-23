#ifndef DATE_LIBRARY_H
#define DATE_LIBRARY_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
namespace util {

    class Date {
    public:
        struct Invalid {
            int bad_day;
            std::string bad_month;
            int bad_year;

            Invalid(int day, int month, int year);
        };

        Date ();

        Date (int day, int month, int year);

        void setDay(int day);
        int getDay ();

        void setMonth(int month);
        std::string getMonth () const;

        void setYear(int year);
        int getYear () const;

        void now();

        void advance();
        void advance(int days);

        enum class Order {
            MonthDayYear,
            DayMonthYear,
            YearMonthDay
        };

        void print () const;

        //static Order order;
        //static char separator;
    private:
        int _day, _month, _year;

        static std::string whatMonth (int month);
    };

}
#endif // DATE_LIBRARY_H
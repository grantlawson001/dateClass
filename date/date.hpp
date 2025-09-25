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

        void day(int day);
        int day () const;

        void month(int month);
        int month () const;

        std::string monthName();

        std::string dayName ();

        void year(int year);
        int year () const;

        static Date now();

        void advance(int days = 1);

        enum class Order {
            MonthDayYear,
            DayMonthYear,
            YearMonthDay
        };

        void print (std::ostream& os) const;

        static Order order;
        static char separator;

    private:
        int _day, _month, _year;

        static std::string whatMonth (int month);

        static std::string whatDay (int day, int month, int year);

        static bool isValid(int day, int month, int year);

    };

}

#endif // DATE_LIBRARY_H
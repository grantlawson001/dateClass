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

            Invalid(int day, int month, int year) {
                bad_day = day;
                bad_month = whatMonth(month);
                bad_year = year;
            }
        };

        Date () {
            _day = 1;
            _month = 1;
            _year = 1970;
        };

        Date (int day, int month, int year) {
            _day = day;
            _month = month;
            _year = year;
        }
        void setDay(int day) {
            _day = day;
        }
        int getDay () {
            return _day;
        }

        void setMonth(int month) {
            _month = month;
        }
        std::string getMonth () {
            return whatMonth (_month);
        }

        void setYear(int year) {
            _year = year;
        }
        int getYear () {
            return _year;
        }

        std::string whatMonth (int month) {
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

        enum class Order {
            MonthDayYear,
            DayMonthYear,
            YearMonthDay
        };

        void print () {
            std::cout << _month << "/" << _day << "/" << _year << " " << std::endl;
        }
    private:
        time_t t = time(NULL);
        tm breakdown = *localtime(&t);
        int _day, _month, _year;
    };

}

int main () {
    util::Date d;
    d.print();
}
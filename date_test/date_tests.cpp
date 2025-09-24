//
// Created by Grant Lawson on 9/19/25.
//
#include "gtest/gtest.h"
#include "date.hpp"

namespace util {
    TEST(DateTest, DefaultConstructor) {
        Date d;
        EXPECT_EQ(1, d.getDay());
        EXPECT_EQ("January", d.getMonth());
        EXPECT_EQ(1970, d.getYear());
    }

    TEST(DateTest, ValidConstructor) {
        Date d(15, 6, 2023);
        EXPECT_EQ(15, d.getDay());
        EXPECT_EQ("June", d.getMonth());
        EXPECT_EQ(2023, d.getYear());
    }

    TEST(DateTest, InvalidConstructorThrows) {
        EXPECT_THROW(Date(31, 4, 2023), Date::Invalid);
    }

    TEST(DateTest, SetDayValid) {
        Date d(10, 5, 2023);
        d.setDay(20);
        EXPECT_EQ(20, d.getDay());
    }

    TEST(DateTest, SetDayInvalidThrows) {
        Date d(10, 2, 2023);
        EXPECT_THROW(d.setDay(30), Date::Invalid);
    }

    TEST(DateTest, SetMonthInvalidThrows) {
        Date d(10, 2, 2023);
        EXPECT_THROW(d.setMonth(13), Date::Invalid);
    }

    TEST(DateTest, SetMonthValid) {
        Date d(10, 1, 2023);
        d.setMonth(12);
        EXPECT_EQ("December", d.getMonth());
    }

    TEST(DateTest, SetYearValid) {
        Date d(10, 1, 2023);
        d.setYear(2025);
        EXPECT_EQ(2025, d.getYear());
    }

    TEST(DateTest, AdvanceOneDay) {
        Date d(1, 3, 2024);
        d.advance(1);
        EXPECT_EQ(2, d.getDay());
        EXPECT_EQ("March", d.getMonth());
        EXPECT_EQ(2024, d.getYear());
    }

    TEST(DateTest, AdvanceMultipleDays) {
        Date d(28, 2, 2023);
        d.advance(2);
        EXPECT_EQ(2, d.getDay());
        EXPECT_EQ("March", d.getMonth());
        EXPECT_EQ(2023, d.getYear());
    }
}
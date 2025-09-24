//
// Created by Grant Lawson on 9/19/25.
//
#include "gtest/gtest.h"
#include "date.hpp"

namespace util {
    TEST(DateTest, DefaultConstructor) {
        Date d;
        EXPECT_EQ(1, d.day());
        EXPECT_EQ(1, d.month());
        EXPECT_EQ(1970, d.year());
    }

    TEST(DateTest, ValidConstructor) {
        Date d(15, 6, 2023);
        EXPECT_EQ(15, d.day());
        EXPECT_EQ(6, d.month());
        EXPECT_EQ(2023, d.year());
    }

    TEST(DateTest, InvalidConstructorThrows) {
        EXPECT_THROW(Date(31, 4, 2023), Date::Invalid);
    }

    TEST(DateTest, SetDayValid) {
        Date d(10, 5, 2023);
        d.day(20);
        EXPECT_EQ(20, d.day());
    }

    TEST(DateTest, SetDayInvalidThrows) {
        Date d(10, 2, 2023);
        EXPECT_THROW(d.day(30), Date::Invalid);
    }

    TEST(DateTest, SetMonthInvalidThrows) {
        Date d(10, 2, 2023);
        EXPECT_THROW(d.month(13), Date::Invalid);
    }

    TEST(DateTest, SetMonthValid) {
        Date d(10, 1, 2023);
        d.month(12);
        EXPECT_EQ(12, d.month());
    }

    TEST(DateTest, SetYearValid) {
        Date d(10, 1, 2023);
        d.year(2025);
        EXPECT_EQ(2025, d.year());
    }

    TEST(DateTest, AdvanceOneDay) {
        Date d(1, 3, 2024);
        d.advance(1);
        EXPECT_EQ(2, d.day());
        EXPECT_EQ(3, d.month());
        EXPECT_EQ(2024, d.year());
    }

    TEST(DateTest, AdvanceMultipleDays) {
        Date d(28, 2, 2023);
        d.advance(2);
        EXPECT_EQ(2, d.day());
        EXPECT_EQ(3, d.month());
        EXPECT_EQ(2023, d.year());
    }
    TEST(DateTest, DoesreturnName) {
        Date d;
        EXPECT_EQ("January", d.monthName());
    }
}
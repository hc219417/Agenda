/*
 * Unit testing for the Appointment class for final CS 2400 project
 */
//#define CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_MAIN  // Catch supplies a main program
#include "catch.hpp"
#include "../appointment.h"

const int MAX_SCORE = 55;
static int score = 0;

TEST_CASE("Testing  Appointment Class") {
    SECTION("Default Constructors") {
        Appointment a;
        REQUIRE("N/A" == a.getTitle());
        score += 5;
    }
    SECTION("All Data Appointment Constructors") {
        Appointment a("   Meeting with Bob  |  2019 |4|29| 8:30 AM |15 ");
        REQUIRE("Meeting with Bob" == a.getTitle());
        REQUIRE("2019-04-29" == a.getDate());
        REQUIRE(830 == a.getTime());
        REQUIRE(15 == a.getDuration());

        Appointment b(" Meeting with Bob| 2019| 4| 29| 8:30 pM| 15");
        REQUIRE("Meeting with Bob" == b.getTitle());
        REQUIRE("2019-04-29" == b.getDate());
        REQUIRE(2030 == b.getTime());
        REQUIRE(15 == b.getDuration());
        score += 15;
    }

    SECTION("Getters and Setters"){
        Appointment a;
        a.setDate(2019, 6, 14);
        a.setDate(2019, 3, 34); //invalid day
        a.setDate(2019, 40, 30); //invalid month
        a.setDate(-2019, 3, 24); //invalid year
        a.setMonth(2);
        a.setMonth(-6);
        a.setYear(-2);
        a.setDay(13);
        a.setDay(-13);

        REQUIRE(2019 == a.getYear());
        REQUIRE(2 == a.getMonth());
        REQUIRE(13 == a.getDay());

        a.setTime(830);
        a.setTime(980); //invalid time
        a.setTime(2550); //ivalid time
        a.setTime(2360); //invalid time
        a.setDuration(30);
        a.setDuration(-5); //invalid duration
        a.setTitle("Appointment Today");
        REQUIRE("2019-02-13" == a.getDate());
        REQUIRE(830 == a.getTime());
        REQUIRE(30 == a.getDuration());
        REQUIRE("Appointment Today" == a.getTitle());
        REQUIRE("8:30AM" == a.getStandardTime());
        a.setTime(2030);
        REQUIRE("8:30PM" == a.getStandardTime());
        score += 10;

    }
    SECTION("Military to Standard Conversion") {
        Appointment a;
        REQUIRE("5:50PM" == a.militaryToStandard(1750));
        REQUIRE("5:40AM" == a.militaryToStandard(540));
        REQUIRE("12:00AM" == a.militaryToStandard(0));
        REQUIRE("12:00AM" == a.militaryToStandard(0));
        REQUIRE("12:40AM" == a.militaryToStandard(40));
        REQUIRE("12:00PM" == a.militaryToStandard(1200));
        score += 10;
    }

    SECTION("Standard to Military"){
        Appointment a;
        REQUIRE(1900 == a.standardToMilitary("7:00 pM"));
        REQUIRE(540 == a.standardToMilitary("5:40aM"));
        REQUIRE(0 == a.standardToMilitary("12:00aM"));
        REQUIRE(40 == a.standardToMilitary("12:40 AM"));
        REQUIRE(1200 == a.standardToMilitary("12:00pm"));
        score += 10;
    }

   SECTION("== Function") {
        Appointment a(" Meeting with Bob|2019|4|29|8:30 AM|15 ");
        Appointment b(" Meeting with Bob |2019 |4|29|8:30AM|15 ");
        Appointment c("    Meeting with Bob|2019| 4| 29|8:30 PM|15");

        REQUIRE(true == (a == b));
        REQUIRE(false == (b == c));
        score += 5;
    }


    SECTION("Score"){
        cout << "\033[1;35m" << "\n==========================================" << endl;
        cout << "\033[1;33m" <<  " Score: " << score << "/" << MAX_SCORE << "\033[1;35m" << endl;
        // << " (passed " << testsPassed <<  " out of " << NUM_TESTS << " tests)" << "\033[0m" << endl;
        cout << "==========================================\n" << "\033[0m" << endl;
    }
}


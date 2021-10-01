//
// Created by Sana Madhavan on 5/4/21.
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <habit-tracker.h>
#include "accomplishment_popups.h"

/**
 * Testing strategy:
 * 1. Testing operator overloading for individual accomplishments
 * 2. Testing operator overloading for full list of accomplishments
 * 3. Testing retrieving accomplishments based on date
 * 4. Test updating accomplishment state based on corresponding habit completion status for the day
 */

namespace finalproject {

    TEST_CASE("Operator overloading for single accomplishments") {
        AccomplishmentPopups single_accomplishment_popup = AccomplishmentPopups();
        single_accomplishment_popup.ReadInAccomplishments("/Users/sana.madhavan/Desktop/Cinder/my-projects/final-project-sm202073/data/singleaccomplishmentsubset.txt");

        SECTION("Testing accomplishment date") {
            std::string test_accomplishment_expected_date = "Tuesday";
            Accomplishment test_accomplishment = single_accomplishment_popup.GetAccomplishments().at(0);
            REQUIRE(test_accomplishment.GetAccomplishmentDay() == test_accomplishment_expected_date);
        }

        SECTION("Testing accomplishment summary") {
            std::string test_accomplishment_expected_summary = "Planned ahead and stuck to plans so far";
            Accomplishment test_accomplishment = single_accomplishment_popup.GetAccomplishments().at(0);
            REQUIRE(test_accomplishment.GetAccomplishmentSummary() == test_accomplishment_expected_summary);
        }
    }

    TEST_CASE("Operator overloading for multiple accomplishments") {
        AccomplishmentPopups multiple_accomplishment_popups = AccomplishmentPopups();
        multiple_accomplishment_popups.ReadInAccomplishments("/Users/sana.madhavan/Desktop/Cinder/my-projects/final-project-sm202073/data/largeraccomplishmentssubset.txt");

        SECTION("Testing first accomplishment date") {
            std::string test_accomplishment_expected_date = "Monday";
            Accomplishment test_accomplishment = multiple_accomplishment_popups.GetAccomplishments().at(0);
            REQUIRE(test_accomplishment.GetAccomplishmentDay() == test_accomplishment_expected_date);
        }

        SECTION("Testing first accomplishment summary") {
            std::string test_accomplishment_expected_summary = "Finished final exams!";
            Accomplishment test_accomplishment = multiple_accomplishment_popups.GetAccomplishments().at(0);
            REQUIRE(test_accomplishment.GetAccomplishmentSummary() == test_accomplishment_expected_summary);
        }

        SECTION("Testing second accomplishment date") {
            std::string test_accomplishment_expected_date = "Tuesday";
            Accomplishment test_accomplishment = multiple_accomplishment_popups.GetAccomplishments().at(1);
            REQUIRE(test_accomplishment.GetAccomplishmentDay() == test_accomplishment_expected_date);
        }

        SECTION("Testing second accomplishment summary") {
            std::string test_accomplishment_expected_summary = "Took some time off";
            Accomplishment test_accomplishment = multiple_accomplishment_popups.GetAccomplishments().at(1);
            REQUIRE(test_accomplishment.GetAccomplishmentSummary() == test_accomplishment_expected_summary);
        }

        SECTION("Testing third accomplishment date") {
            std::string test_accomplishment_expected_date = "Wednesday";
            Accomplishment test_accomplishment = multiple_accomplishment_popups.GetAccomplishments().at(2);
            REQUIRE(test_accomplishment.GetAccomplishmentDay() == test_accomplishment_expected_date);
        }

        SECTION("Testing third accomplishment summary") {
            std::string test_accomplishment_expected_summary = "Got time to update resume";
            Accomplishment test_accomplishment = multiple_accomplishment_popups.GetAccomplishments().at(2);
            REQUIRE(test_accomplishment.GetAccomplishmentSummary() == test_accomplishment_expected_summary);
        }
    }

    TEST_CASE("Testing retrieving accomplishments based on date index") {
        AccomplishmentPopups multiple_accomplishment_popups = AccomplishmentPopups();
        multiple_accomplishment_popups.ReadInAccomplishments("/Users/sana.madhavan/Desktop/Cinder/my-projects/final-project-sm202073/data/largeraccomplishmentssubset.txt");

        SECTION("Retrieving the first accomplishment to render") {
            Accomplishment test_accomplishment_to_display = multiple_accomplishment_popups.GetAccomplishmentAndRenderAtIndex(0); // displays Monday accomplishment
            REQUIRE(test_accomplishment_to_display.GetAccomplishmentDay() == "Monday");
        }

        SECTION("Retrieving the second accomplishment to render") {
            Accomplishment test_accomplishment_to_display = multiple_accomplishment_popups.GetAccomplishmentAndRenderAtIndex(1); // displays Monday accomplishment
            REQUIRE(test_accomplishment_to_display.GetAccomplishmentDay() == "Tuesday");
        }

        SECTION("Retrieving the third accomplishment to render") {
            Accomplishment test_accomplishment_to_display = multiple_accomplishment_popups.GetAccomplishmentAndRenderAtIndex(2); // displays Monday accomplishment
            REQUIRE(test_accomplishment_to_display.GetAccomplishmentDay() == "Wednesday");
        }
    }

    TEST_CASE("Updating accomplishment state based on corresponding habit for the day") {
        HabitTracker test_tracker = HabitTracker();
        test_tracker.ReadInHabitData("/Users/sana.madhavan/Desktop/Cinder/my-projects/final-project-sm202073/data/largerhabitssubset.txt");

        AccomplishmentPopups test_accomplishments = AccomplishmentPopups();
        test_accomplishments.ReadInAccomplishments("/Users/sana.madhavan/Desktop/Cinder/my-projects/final-project-sm202073/data/largeraccomplishmentssubset.txt");

        SECTION("Checking if first accomplishment can rendered based on habit state") {
            Habit test_habit = test_tracker.GetHabitList().at(0);
            test_habit.SetCompleted(true); // set completion to true

            Accomplishment test_accomplishment_one = test_accomplishments.GetAccomplishments().at(0);
            REQUIRE(test_accomplishment_one.CheckHabitStateAndRender(test_habit) == true);
        }

        SECTION("Checking if second accomplishment can rendered based on habit state") {
            Habit test_habit = test_tracker.GetHabitList().at(1);
            test_habit.SetCompleted(true); // set completion to true

            Accomplishment test_accomplishment_two = test_accomplishments.GetAccomplishments().at(1);
            REQUIRE(test_accomplishment_two.CheckHabitStateAndRender(test_habit) == true);
        }

        SECTION("Checking if third accomplishment can rendered based on habit state") {
            Habit test_habit = test_tracker.GetHabitList().at(2);
            test_habit.SetCompleted(true); // set completion to true

            Accomplishment test_accomplishment_three = test_accomplishments.GetAccomplishments().at(2);
            REQUIRE(test_accomplishment_three.CheckHabitStateAndRender(test_habit) == true);
        }

    }

} // namespace finalproject
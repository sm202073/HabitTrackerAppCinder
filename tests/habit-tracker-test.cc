//
// Created by Sana Madhavan on 4/27/21.
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <habit-tracker.h>

namespace finalproject {
/**
 * Testing strategy:
 * 1. Testing operator overloading for particular habits in files with different habits or one habit only
 * 2. Test that the habit is completed after checking the box
 */

    TEST_CASE("Reading in one habit and checking all fields") {
        HabitTracker habit_tracker_for_one_habit;
            habit_tracker_for_one_habit.ReadInHabitData(
                    "/Users/sana.madhavan/Desktop/Cinder/my-projects/final-project-sm202073/data/singlehabitsubset.txt");

            SECTION("Testing >> overloading on the size of a habit list with a single habit") {

                size_t habit_list_size = habit_tracker_for_one_habit.GetHabitList().size();
            REQUIRE(habit_list_size == 1);
        }

       SECTION("Testing >> overloading on a single habit's date") {

            std::string expected_day = "Thursday";
            REQUIRE(habit_tracker_for_one_habit.GetHabitList().at(0).GetDay() == expected_day);
        }

        SECTION("Testing >> on a single habit's summary") {

            std::string expected_summary = "Keep up the motivation";
            REQUIRE(habit_tracker_for_one_habit.GetHabitList().at(0).GetHabitSummary() == expected_summary);
        }

        SECTION("Testing >> overloading on a single habit's completion") {

            bool starting_completion = false;
            REQUIRE(habit_tracker_for_one_habit.GetHabitList().at(0).GetCompleted() == starting_completion);
        }
    }

    TEST_CASE("Reading in multiple habits at once and checking all fields") {
        HabitTracker habit_tracker_for_multiple_habits;
        habit_tracker_for_multiple_habits.ReadInHabitData(
                "/Users/sana.madhavan/Desktop/Cinder/my-projects/final-project-sm202073/data/largerhabitssubset.txt");

        SECTION("Testing >> overloading on the size of a habit list with a single habit") {
            size_t habit_list_size = habit_tracker_for_multiple_habits.GetHabitList().size();
            REQUIRE(habit_list_size == 3);
        }

        SECTION("Testing >> overloading on multiple dates") {

            std::string first_expected_day = "Monday";
            std::string second_expected_day = "Tuesday";
            std::string third_expected_day = "Wednesday";
            REQUIRE(habit_tracker_for_multiple_habits.GetHabitList().at(0).GetDay() == first_expected_day);
            REQUIRE(habit_tracker_for_multiple_habits.GetHabitList().at(1).GetDay() == second_expected_day);
            REQUIRE(habit_tracker_for_multiple_habits.GetHabitList().at(2).GetDay() == third_expected_day);
        }

        SECTION("Testing >> overloading on multiple habit summaries") {

            std::string first_expected_summary = "Take a walk around the quad";
            std::string second_expected_summary = "Talk with friends";
            std::string third_expected_summary = "Finish the week early";
            REQUIRE(habit_tracker_for_multiple_habits.GetHabitList().at(0).GetHabitSummary() == first_expected_summary);
            REQUIRE(habit_tracker_for_multiple_habits.GetHabitList().at(1).GetHabitSummary() == second_expected_summary);
            REQUIRE(habit_tracker_for_multiple_habits.GetHabitList().at(2).GetHabitSummary() == third_expected_summary);
        }

        SECTION("Testing >> overloading on multiple habit's completion") {

            bool starting_completion = false; // default completion for all habits is false
            REQUIRE(habit_tracker_for_multiple_habits.GetHabitList().at(0).GetCompleted() == starting_completion);
            REQUIRE(habit_tracker_for_multiple_habits.GetHabitList().at(1).GetCompleted() == starting_completion);
            REQUIRE(habit_tracker_for_multiple_habits.GetHabitList().at(2).GetCompleted() == starting_completion);
        }
    }

    TEST_CASE("Testing completing habits") {
        SECTION("Completing single habit") {
            HabitTracker habit_tracker_for_one_habit;
            habit_tracker_for_one_habit.ReadInHabitData(
                    "/Users/sana.madhavan/Desktop/Cinder/my-projects/final-project-sm202073/data/singlehabitsubset.txt");

            Habit test_habit = habit_tracker_for_one_habit.UpdateHabitProgressForDay(0, true); // setting habit to be completed
            REQUIRE(test_habit.GetCompleted() == true);
        }

        SECTION("Completing multiple habits") {
            HabitTracker habit_tracker_for_multiple_habits;
            habit_tracker_for_multiple_habits.ReadInHabitData(
                    "/Users/sana.madhavan/Desktop/Cinder/my-projects/final-project-sm202073/data/largerhabitssubset.txt");

            Habit test_habit_one = habit_tracker_for_multiple_habits.UpdateHabitProgressForDay(0, true); // setting habit to be completed
            Habit test_habit_two = habit_tracker_for_multiple_habits.UpdateHabitProgressForDay(1, true); // setting habit to be completed
            Habit test_habit_three = habit_tracker_for_multiple_habits.UpdateHabitProgressForDay(2, true); // setting habit to be completed
            REQUIRE(test_habit_one.GetCompleted() == true);
            REQUIRE(test_habit_two.GetCompleted() == true);
            REQUIRE(test_habit_three.GetCompleted() == true);
        }
    }

} // namespace finalproject



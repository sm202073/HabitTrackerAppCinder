//
// Created by Sana Madhavan on 4/21/21.
//
#include "cinder/gl/gl.h"

#include <vector>

#include "habit.h"

using glm::vec2;

#ifndef FINAL_PROJECT_SM202073_HABIT_TRACKER_H
#define FINAL_PROJECT_SM202073_HABIT_TRACKER_H


namespace finalproject {
    /**
     * Represents the full habit tracker/calendar which holds all habits corresponding to dates
     */
    class HabitTracker {
    public:
       HabitTracker();
       HabitTracker(const std::vector<Habit>& habits);

        /**
         * Displays the habit tracker as a calendar graph with sections for each day of the week and habit blocks within the corresponding days
         */
        void Display();

        /**
         * Helper method to read in data
         * @param filePath
         * @return HabitTracker object with the data read into it
         */
        HabitTracker ReadInHabitData(const std::string& filePath);

        /**
        * Navigates to the next habit in the list, corresponding to the next day
        * @param current_habit that you are on
       * @return habit in the next day
        */
        Habit GetNextHabit(const Habit& current_habit);

        /**
         * Sets the habit at the passed location to completed or clears progress, based on parameter
         * @param habit_index of the habit state to be updated
         * @param habit_progress indicates whether the habit is completed or not
         * TEST THIS
         */
         Habit UpdateHabitProgressForDay(size_t habit_index, bool habit_progress);


         /**
          * operator overloading to process multiple habits
          * @param is istream object to perform operator overloading
          * @param data HabitTracker object to store user file data into
          */
         friend std::istream& operator>>(std::istream& is, HabitTracker& data);

         void SetHabitList(const std::vector<Habit>& habit_list);

         std::vector<Habit> GetHabitList() const;

         /**
         * Sets the lower and upper bounds of the habit tracker display.
         * @param lower bound as a vec2.
         * @param upper bound as a vec2.
         */
         void SetHabitCalendarBounds(const vec2& lower, const vec2& upper);



    private:
        std::vector<Habit> habit_list_; // holds all the habits in the habit tracker/calendar
        vec2 lower_bound_ = vec2(100, 100);// inner dimensions of the habit tracker calendar
        vec2 upper_bound_ = vec2(800, 600);// outer dimensions of the habit tracker calendar

        //habit box starting dimensions, increment each time
        vec2 lower_habit_ = vec2(100, 100);
        vec2 upper_habit_ = vec2(240, 600);


        const cinder::Color kCalendarColor = ci::Color("white");
        const cinder::Color kHabitBlockColor = ci::Color("orange");

    };

}  // namespace finalproject

#endif //FINAL_PROJECT_SM202073_HABIT_TRACKER_H
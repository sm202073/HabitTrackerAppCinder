//
// Created by Sana Madhavan on 4/20/21.
//

#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "habit-tracker.h"
#include "accomplishment_popups.h"
#include "cinder/Timer.h"

namespace finalproject {

/**
 * An app for visualizing daily habits in a checklist format with built in-timers to hold the user accountable for completing habits
 * Also displays user accomplishments based on completion status of a habit to reinforce completion
 */
    class HabitTrackerApp : public ci::app::App {
    public:
        HabitTrackerApp();

        /**
         * Draws the habit on the app screen, checking current state of the habit and shading in the box accordingly
         */
        void DrawHabitCompletion() const;

        /**
         * Draws accomplishment text on the habit screen, when the habit was accomplished for the current day
         */
        void DrawAccomplishment();

        /**
         * Creates a Cinder timer to render on the screen for each habit
         * @return Timer object that is made
         */
        ci::Timer CreateTimer();

        /**
         * Renders the timers as a stopwatch display of seconds elapsed
         */
        void DisplayTimer();


        void draw() override;
        void update() override;

        void keyDown(ci::app::KeyEvent& event) override;

        const int kWindowSize = 875;
        const int kMargin = 100;

    private:
        HabitTracker tracker_;
        AccomplishmentPopups popups_; // represents the accomplishment popups object that will render on the app screen of each habit
        size_t current_date_index_; // representing the current date in the list of dates (position to update)

        /**
         * File paths to read in user habits and accomplishments
         */
         const std::string kUserHabitFile = "data/user1habits.txt";
         const std::string kUserAccomplishmentFile = "data/accomplishments.txt";

        bool key_down_; // boolean variable representing if the user is trying to go to and log the next day
        bool key_return_; // boolean variable representing if the user is trying to complete the day's habit and fill in the checkbox
        bool key_delete_; // boolean variable representing if the user is trying to clear all progress and start a new week of habits

        /**
         * Constant scale factors to position the habit checkboxes appropriately next to the days of the week on the display
         */
         const size_t kCheckboxPositionLowerFactorX = 25;
         const size_t kCheckboxPositionLowerFactorY = 5;
         const size_t kCheckboxPositionHigherFactor = 10;

        // Timer elements
        ci::Timer timer_; // represents timer for each habit, updates as you go to the next habit
        cinder::Color timer_text_color_ = ci::Color("white"); // color for the timer stopwatch
        const cinder::Color kTimerBackgroundColor = ci::Color("orange"); // unchanging background color for the timers

        /**
         * Adding constant numbers to the habit box positions to display the timer circle appropriately on the UI
         */
        const size_t kTimerPositionXFactor = 65;
        const size_t kTimerPositionYFactor = 400;
        const size_t kTimerCircleRadius = 50;
        const size_t kTimerStringPositionXFactor = 40;
        const size_t kTimerStringPositionYFactor = 400;

        const cinder::Color kAppBackgroundColor = ci::Color("gray"); // unchanging background color for the app screen
    };

}  // namespace finalproject



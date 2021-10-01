//
// Created by Sana Madhavan on 4/20/21.
//
#include "habit-tracker-app.h"

namespace finalproject {

    HabitTrackerApp::HabitTrackerApp() {
        ci::app::setWindowSize(kWindowSize, kWindowSize);
        current_date_index_ = 0; // start at Monday to log
        tracker_.ReadInHabitData(kUserHabitFile);
        popups_.ReadInAccomplishments(kUserAccomplishmentFile);
        CreateTimer(); // starts the timer for Monday when you launch the app
    }

    void HabitTrackerApp::DrawHabitCompletion() const {
        Habit curr_habit = tracker_.GetHabitList().at(current_date_index_); // current habit date
        curr_habit.CompleteHabit(vec2(curr_habit.GetDateLabelPosition().x - kCheckboxPositionLowerFactorX, curr_habit.GetDateLabelPosition().y - kCheckboxPositionLowerFactorY),
                                 vec2(curr_habit.GetDateLabelPosition().x - kCheckboxPositionHigherFactor,
                                      curr_habit.GetDateLabelPosition().y + kCheckboxPositionHigherFactor));
    }

    void HabitTrackerApp::DrawAccomplishment() {
        Habit curr_habit = tracker_.GetHabitList().at(current_date_index_); // current habit date
        if (curr_habit.GetCompleted()) {
            popups_.GetAccomplishmentAndRenderAtIndex(current_date_index_); // getting accomplishment to render at the date the user is on
        }
    }

    void HabitTrackerApp::draw() {
        ci::Color background_color(kAppBackgroundColor);
        ci::gl::clear(background_color);

        tracker_.Display();
        DrawHabitCompletion();

        DrawAccomplishment();

        DisplayTimer();

    }

    ci::Timer HabitTrackerApp::CreateTimer() {
        timer_ = cinder::Timer(); // creating a timer to start timing the user to complete the habit
        timer_.start();
        return timer_;
    }

    void HabitTrackerApp::DisplayTimer() {
        Habit curr_habit = tracker_.GetHabitList().at(current_date_index_);
        ci::gl::color(kTimerBackgroundColor);
        ci::gl::drawSolidCircle(vec2(curr_habit.GetHabitLowerBlockBounds().x + kTimerPositionXFactor, curr_habit.GetHabitLowerBlockBounds().y + kTimerPositionYFactor), kTimerCircleRadius);

        timer_text_color_ = ci::Color("white"); // reset the timer text to white on each new habit
        if (curr_habit.GetCompleted()) {
            timer_text_color_ = ci::Color("green"); // set to green when the timer stops and the habit is completed
        }
        cinder::gl::drawString(std::to_string(timer_.getSeconds()), vec2(curr_habit.GetHabitLowerBlockBounds().x + kTimerStringPositionXFactor, curr_habit.GetHabitLowerBlockBounds().y + kTimerStringPositionYFactor), timer_text_color_);
    }


    void HabitTrackerApp::keyDown(ci::app::KeyEvent& event) {
        switch (event.getCode()) {
            case ci::app::KeyEvent::KEY_RETURN:
                // update current habit's checkbox shade
                key_return_ = true; // registering the event
                // setting current
                tracker_.UpdateHabitProgressForDay(current_date_index_, true);
                timer_.stop();

                break;

            case ci::app::KeyEvent::KEY_DOWN:
                key_down_ = true;
                if (current_date_index_ >= 0 && current_date_index_ < tracker_.GetHabitList().size()) {
                    current_date_index_++;
                }
                // reset the current date back to the start (logging week by week)
                if (current_date_index_ == tracker_.GetHabitList().size()) {
                    current_date_index_ = 0;
                }

                CreateTimer(); // start timer for that day

                break;

            case ci::app::KeyEvent::KEY_UP:
                if (current_date_index_ > 0 && current_date_index_ <= tracker_.GetHabitList().size()) {
                    current_date_index_--;
                }

                CreateTimer(); // start timer for that day
                break;

            case ci::app::KeyEvent::KEY_DELETE:
                // resets the full week
                key_delete_ = true;
                if (current_date_index_ == 0) {
                    for (size_t i = 0; i < tracker_.GetHabitList().size(); i++) {
                        tracker_.UpdateHabitProgressForDay(i, false);
                    }
                }

                timer_.stop();
                CreateTimer();
                // reset all checkboxes after a week cycle if you're back on Monday
        }
    }

    void HabitTrackerApp::update() {
        // updating is handled with user key input
    }


} // namespace finalproject
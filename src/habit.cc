//
// Created by Sana Madhavan on 4/21/21.
//

#include "habit.h"

using glm::vec2;

namespace finalproject {
    Habit::Habit() {}

    Habit::Habit(const std::string &habit_message, bool completion, const std::string& day) {
        habit_summary_ = habit_message;
        completed_ = completion;
        day_ = day;
    }

    Habit::Habit(const std::string& habit_message, bool completion, const std::string& day, const vec2& lower, const vec2& upper) {
        habit_summary_ = habit_message;
        completed_ = completion;
        day_ = day;
        habit_lower_box_ = lower;
        habit_upper_box_ = upper;
    }


    void Habit::RenderHabitBlock(const vec2& summary_position, const vec2& date_label_position) {
        // makes a bar of the graph to represent the habit for the particular day in those dimensions
        ci::gl::drawStrokedRect(ci::Rectf(habit_lower_box_, habit_upper_box_));
        date_label_position_ = date_label_position;
        cinder::gl::drawString(day_,date_label_position, ci::Color(kDateTextColor));
        // draws habit string within dimensions of habit box
        cinder::gl::drawString(habit_summary_,summary_position, ci::Color(kHabitColor));
    }

    bool Habit::CompleteHabit(const vec2& checkbox_position_lower, const vec2& checkbox_position_higher) const {

        ci::gl::color(ci::Color("orange")); // default color
        if (completed_) {
            ci::gl::color(ci::Color("green"));
        }

        ci::gl::drawSolidRect(ci::Rectf(checkbox_position_lower, checkbox_position_higher));
        return true;
    }

    std::istream &operator>>(std::istream &is, Habit &habit) {
        std::string line; // represents current line of input
        size_t line_count = 0;

        while (std::getline(is, line) && line_count < 2) {
            if (line_count == 0) { // on the first line with
                habit.day_ = line; // getting the day of the habit
                line_count++;
            } else if (line.size() == 0) {
                line_count++; // skips lines with only spaces
            } else {
                habit.habit_summary_ = line; //std::stoi(line);
                habit.completed_ = false; // default completion to false when habit is loaded in
                line_count++;
            }
        }
        return is;
    }

    void Habit::SetHabitBlockBounds(vec2 lower, vec2 upper) {
        habit_lower_box_ = lower;
        habit_upper_box_ = upper;
    }

    vec2 Habit::GetHabitLowerBlockBounds() const {
        return habit_lower_box_;
    }
    vec2 Habit::GetHabitUpperBlockBounds() const {
        return habit_upper_box_;
    }

    void Habit::SetHabitSummary(const std::string& summary) {
        habit_summary_ = summary;
    }

    std::string Habit::GetHabitSummary() const {
        return habit_summary_;
    }

    void Habit::SetCompleted(bool complete) {
        completed_ = complete;
    }

    bool Habit::GetCompleted() const {
        return completed_;
    }

    void Habit::SetDay(const std::string& day) {
        day_ = day;
    }

    std::string Habit::GetDay() const {
        return day_;
    }

    vec2 Habit::GetDateLabelPosition() const {
        return date_label_position_;
    }

}

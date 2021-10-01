//
// Created by Sana Madhavan on 4/21/21.
//

#include "habit-tracker.h"

namespace finalproject {

    using glm::vec2;

    HabitTracker::HabitTracker() {
    }


    void HabitTracker::Display() {
        ci::gl::color(kCalendarColor); // color outer calendar box

        ci::gl::drawStrokedRect(ci::Rectf(lower_bound_, upper_bound_));

        ci::gl::color(kHabitBlockColor); // color each habit block
        for (Habit& habit: habit_list_) {
            habit.RenderHabitBlock(vec2(habit.GetHabitLowerBlockBounds().x + 10, habit.GetHabitLowerBlockBounds().y + 150), vec2(habit.GetHabitLowerBlockBounds().x + 50, habit.GetHabitLowerBlockBounds().y + 50));
        }
    }

    Habit HabitTracker::UpdateHabitProgressForDay(size_t habit_index, bool habit_progress) {
        Habit& habit_to_complete = habit_list_.at(habit_index);
        habit_to_complete.SetCompleted(habit_progress);
        return habit_to_complete;
    }

    std::istream& operator>>(std::istream& is, HabitTracker& habit_data) {
        std::string line;

        size_t habit_dimension_factor = 0;
        while (!(is.eof())) {
            Habit curr_habit = Habit();
            curr_habit.SetHabitBlockBounds(vec2(habit_data.lower_habit_.x + habit_dimension_factor*140, habit_data.lower_habit_.y), vec2(habit_data.upper_habit_.x + habit_dimension_factor*140, habit_data.upper_habit_.y));
            is >> curr_habit;
            habit_data.habit_list_.push_back(curr_habit);
            habit_dimension_factor++;
        }
        return is;
    }


    HabitTracker HabitTracker::ReadInHabitData(const std::string& filePath) {
        std::ifstream input_file(filePath);
        if (input_file.is_open()) {
            input_file >> *this;
            input_file.close();
        }
        return *this;
    }


    void HabitTracker::SetHabitList(const std::vector<Habit>& habit_list) {
        habit_list_ = habit_list;
    }

    std::vector<Habit> HabitTracker::GetHabitList() const {
        return habit_list_;
    }

    void HabitTracker::SetHabitCalendarBounds(const vec2& lower, const vec2& upper) {
        upper_bound_ = upper;
        lower_bound_ = lower;
    }

} // namespace finalproject
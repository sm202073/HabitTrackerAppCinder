//
// Created by Sana Madhavan on 4/21/21.
//

#include "accomplishment.h"
using glm::vec2;

namespace finalproject {

    Accomplishment::Accomplishment() {
    }

    Accomplishment::Accomplishment(const std::string& summary, const vec2& position) {
        accomplishment_summary_ = summary;
        accomplishment_pos_ = position;
    }

    void Accomplishment::RenderAccomplishment() const {
        cinder::gl::drawString(accomplishment_summary_,accomplishment_pos_, ci::Color(kAccomplishmentColor));
    }

    bool Accomplishment::CheckHabitStateAndRender(const Habit& habit) const {
        return habit.GetCompleted();
    }

    std::istream &operator>>(std::istream &is, Accomplishment &accomplishment) {
        std::string line; // represents current line of input
        size_t line_count = 0;

        const size_t kAccomplishmentLineNumber = 2; //represents the number of lines on the user text file
        // that the accomplishment, including its date, occupies (first line is date, second is accomplishment description)

        while (std::getline(is, line) && line_count < kAccomplishmentLineNumber) {
            if (line_count == 0) { // on the first line with only the date
                accomplishment.day_ = line; // getting the day of the habit
                line_count++;
            } else if (line.size() == 0) {
                line_count++; // skips lines with only spaces
            } else {
                accomplishment.accomplishment_summary_ = line; // finding and setting the summary of the accomplishment
                line_count++;
            }
        }
        return is;
    }

    std::string Accomplishment::GetAccomplishmentSummary() const {
        return accomplishment_summary_;
    }

    vec2 Accomplishment::GetAccomplishmentPosition() const {
        return accomplishment_pos_;
    }

    std::string Accomplishment::GetAccomplishmentDay() const {
        return day_;
    }

    void Accomplishment::SetAccomplishmentSummary(const std::string& summary) {
        accomplishment_summary_ = summary;
    }

    void Accomplishment::SetAccomplishmentPosition(const vec2& position) {
        accomplishment_pos_ = position;
    }

    void Accomplishment::SetAccomplishmentDay(const std::string &day) {
        day_ = day;
    }

} // namespace finalproject
//
// Created by Sana Madhavan on 4/21/21.
//

#ifndef FINAL_PROJECT_SM202073_HABIT_H
#define FINAL_PROJECT_SM202073_HABIT_H

#include "cinder/gl/gl.h"

using glm::vec2;

namespace finalproject {
/**
 * Class that represents an individual habit inputted by the user, including a date for it to be set for, a description,
 * and an indication of whether it is complete for the day or not.
 */
class Habit {
public:
    Habit();

    /**
     * Constructor that takes in a habit description, whether it is completed or not, and the day intended for it
     * @param habit_message represents a message describing the habit the user wants to keep
     * @param completion represents whether the habit is completed or not
     * @param day the day of the week representing each weekday
     */
    Habit(const std::string& habit_message, bool completion, const std::string& day);

    /**
    * Constructor that takes in a habit description, whether it is completed or not, and the day intended for it and its dimension bounds to render
    * @param habit_message represents a message describing the habit that the user wants to see
    * @param completion represents whether the habit is completed or not
    * @param day of the week from 1-5 representing each weekday, and more if the user adds to the text file
    * @param upper vec2 lower bounds of the habit block position
    * @param lower vec2 upper bounds of the habit block position
    */
    Habit(const std::string& habit_message, bool completion, const std::string& day, const vec2& lower, const vec2& upper);


    /**
     * Renders the habit message and checkbox in a separate section of the UI
     * @param summary_position of the habit text within the block
     * @param date_label_position position of the date label within the habit block
     */
    void RenderHabitBlock(const vec2& summary_position, const vec2& date_label_position);

    /**
    * Called when user presses enter on the current habit, sets the habit to be completed, fills in checkbox with bounds within the overall habit block
     * @param checkbox_position_lower represents the lower bounds of the position of the checkbox next to the habit date on the UI
     * @param checkbox_position_higher represents the upper bounds of the position of the checkbox next to the habit date  on the UI
    * @return boolean representing the updated state of completion
    */
    bool CompleteHabit(const vec2& checkbox_position_lower, const vec2& checkbox_position_higher) const;

    /**
     * Operator overloading for the individual habit
     * @param is stream object to perform operator overloading
     * @param Habit object to load the user input into
     * @return
     */
    friend std::istream& operator>>(std::istream& is, Habit& habit);

    /**
     * Sets the lower and upper bounds of the habit block in the graph.
     * @param lower bound as a vec2
     * @param upper bound as a vec2
     */
    void SetHabitBlockBounds(vec2 lower, vec2 upper);

    vec2 GetHabitLowerBlockBounds() const;
    vec2 GetHabitUpperBlockBounds() const;

    void SetHabitSummary(const std::string& summary);
    std::string GetHabitSummary() const;

    void SetCompleted(bool complete);
    bool GetCompleted() const;

    void SetDay(const std::string& day);
    std::string GetDay() const;

    vec2 GetDateLabelPosition() const;


private:
    std::string habit_summary_; // represents the habit the user wants to keep, in summary
    bool completed_; // indicator as to whether the habit is completed for that specific day
    std::string day_; // day of the week when the habit is set for (Monday to Friday = 1-5) and more if the user adds weekends to the text file

    // consistent and modifiable dimensions of the habit display box for each habit
    vec2 habit_lower_box_;
    vec2 habit_upper_box_;

    vec2 date_label_position_; // saving the date label position (day of the week) to determine where to place the checkbox

    // habit box colors
    cinder::ColorT<float> kDateTextColor = "orange";
    cinder::ColorT<float> kHabitColor = "white";
};

}  // namespace finalproject

#endif //FINAL_PROJECT_SM202073_HABIT_H
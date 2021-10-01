//
// Created by Sana Madhavan on 4/21/21.
//

#ifndef FINAL_PROJECT_SM202073_ACCOMPLISHMENT_H
#define FINAL_PROJECT_SM202073_ACCOMPLISHMENT_H

#include "cinder/gl/gl.h"
#include "habit.h"

using glm::vec2;

namespace finalproject {

/**
 * Class representing an individual accomplishment set by the user, holding the message and its position on the habit tracker UI
 */
class Accomplishment {
public:
    Accomplishment();

    Accomplishment(const std::string& summary, const vec2& position);

    /**
     * Renders the accomplishment within the habit block for a respective habit, accomplishment position instance variable is within the habit
     */
    void RenderAccomplishment() const;

    /**
    * Operator overloading for the individual accomplishment
    * @param is stream object to perform operator overloading
    * @param Accomplishment object to load the list of accomplishments
    */
    friend std::istream& operator>>(std::istream& is, Accomplishment& accomplishment);

    /**
     * Checks if the passed habit is completed in order to render the accomplishment in the same box of the habit
     * @param habit to check for completion
     * @return a boolean indicating whether the accomplishment can be and was rendered
     */
    bool CheckHabitStateAndRender(const Habit& habit) const;

    vec2 GetAccomplishmentPosition() const;
    void SetAccomplishmentPosition(const vec2& position);

    std::string GetAccomplishmentSummary() const;
    void SetAccomplishmentSummary(const std::string& summary);

    std::string GetAccomplishmentDay() const;
    void SetAccomplishmentDay(const std::string& day);

private:
    std::string accomplishment_summary_; // represents the accomplishment description
    vec2 accomplishment_pos_; // represents the position of the accomplishment text on the habit tracker planner
    std::string day_; // day that the accomplishment corresponds to

    const cinder::Color kAccomplishmentColor = ci::Color("white");
};

}
#endif //FINAL_PROJECT_SM202073_ACCOMPLISHMENT_H


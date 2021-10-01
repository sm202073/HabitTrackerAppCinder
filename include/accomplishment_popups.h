//
// Created by Sana Madhavan on 5/2/21.
//

#ifndef FINAL_PROJECT_SM202073_ACCOMPLISHMENT_POPUPS_H
#define FINAL_PROJECT_SM202073_ACCOMPLISHMENT_POPUPS_H

#include "cinder/gl/gl.h"
#include <vector>
#include "accomplishment.h"
using glm::vec2;

namespace finalproject {
    /**
     * Class to hold multiple accomplishments at once which will then render on the display when the corresponding habit is completed.
     */
    class AccomplishmentPopups {
    public:
        AccomplishmentPopups();

        AccomplishmentPopups(const std::vector<Accomplishment>& accomplishments);

        // operator overloading to process multiple accomplishments
        friend std::istream& operator>>(std::istream& is, AccomplishmentPopups& accomplishmentPopups);

        /**
         * Calls operator overloading on each individual accomplishment to load into the full list of accomplishments
         * @param file_path of the user input as a txt file that provides accomplishments for each day of the week that their habits are set for
         * @return AccomplishmentPopups object with accomplishments from the file loaded in
         */
        AccomplishmentPopups ReadInAccomplishments(const std::string& file_path);

        /**
         * Get the accomplishment at an index for use in the app to then render it
         * @param date_index of the accomplishment (0-4 corresponds through Monday-Friday but the user can also add more dates)
         * @return Accomplishment object that is being searched for
         */
        Accomplishment GetAccomplishmentAndRenderAtIndex(size_t date_index);

        std::vector<Accomplishment> GetAccomplishments() const;
        void SetAccomplishments(const std::vector<Accomplishment>& accomplishments);

    private:
        std::vector<Accomplishment> accomplishments_;
        vec2 starting_position_ = vec2(100, 350);
    };
} // namespace finalproject

#endif //FINAL_PROJECT_SM202073_ACCOMPLISHMENT_POPUPS_H

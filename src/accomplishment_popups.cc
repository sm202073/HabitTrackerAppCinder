//
// Created by Sana Madhavan on 5/2/21.
//

#include "accomplishment_popups.h"

namespace finalproject {

    AccomplishmentPopups::AccomplishmentPopups() { }

    std::istream& operator>>(std::istream& is, AccomplishmentPopups& accomplishmentPopups) {
         std::string line;
         size_t accomplishment_dimension_factor = 0;

         const size_t kPositionFactor = 140;

         while (!(is.eof())) {
             Accomplishment curr_accomplishment = Accomplishment();
             curr_accomplishment.SetAccomplishmentPosition(vec2(accomplishmentPopups.starting_position_.x + kPositionFactor*accomplishment_dimension_factor, accomplishmentPopups.starting_position_.y));
             is >> curr_accomplishment;
             accomplishmentPopups.accomplishments_.push_back(curr_accomplishment);
             accomplishment_dimension_factor++;
         }
         return is;
    }


    AccomplishmentPopups AccomplishmentPopups::ReadInAccomplishments(const std::string& file_path) {
        std::ifstream input_file(file_path);
        if (input_file.is_open()) {
            input_file >> *this;
            input_file.close();
        }
        return *this;
    }

    Accomplishment AccomplishmentPopups::GetAccomplishmentAndRenderAtIndex(size_t date_index) {
        Accomplishment& accomplishment = accomplishments_.at(date_index);
        accomplishment.RenderAccomplishment();
        return accomplishment;
    }

    std::vector<Accomplishment> AccomplishmentPopups::GetAccomplishments() const {
        return accomplishments_;
    }

} // namespace finalproject

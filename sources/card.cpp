#include "card.hpp"
#include <string>

using namespace std;

namespace ariel{
    card::card() {}

     card::card(int num, ariel::Type type) {
        this->num = num;
        this->type = type;
    }
    std::string card::get_type() const {
        switch (type) {
            case D:
                return "Diamonds";
            case C:
                return "Clubs";
            case H:
                return "Hearts";
            case S:
                return "Spades";
        }
    }
      std::string card::get_number() const {
        if (num == 1) {
            return "Ace";
        } else if (num == 11) {
            return "Jack";
        } else if (num == 12) {
            return "Queen";
        } else if (num == 13) {
            return "King";
        } else {
            return std::to_string(num);
        }
    }   
     std::string card::to_string() const {
        string str = ""; 
        str += get_num();
        str += " of ";
        str += get_type();
        return str;
    }

    int card::get_num() const {
        return num;
    }

};


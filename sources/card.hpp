#include <string>
#ifndef CARD_HPP
#define CARD_HPP

namespace ariel{
using string = std::string;

    enum Type {D, C, H, S};
    class card{
        private:
            int num;
            Type type;
            std::string get_type() const;
            std::string get_number() const;

        public:
            card();
            card(int num, Type type);
            std::string to_string() const;

            int get_num() const ;
     };
};

#endif

#include <string>
#include <iostream>
#include "card.hpp"
#include <stack>

#ifndef PLAYER_HPP
#define PLAYER_HPP
namespace ariel{
    using std::string;

class Player{
    private:
        bool _is_active;
        std::stack<card> pile;
        std::string name;
        int move_Won;
        int moves_that_played;
        int cards_Taken;

    public:
        Player();
        Player(std::string name);
        
        bool get_is_active();

    /*prints the amount of cards left*/
        int stacksize();

    /*prints the amount of cards this player has won*/
        int cardesTaken();

        card play_Card();

        std::string t_for_log(card card);
        std::string get_name();
        void addCard(card card);
        void print_stats();
        void add_round(int cards_won);
        
    };
};
#endif
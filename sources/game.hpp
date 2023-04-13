#include "player.hpp"
#include <stack>
#include <algorithm> // for shuffle
#include <random> // for default random engine and random device
#include <vector>
#include <stdexcept>
#include <iostream>
#ifndef GAME_HPP
#define GAME_HPP
namespace ariel{
    class Game{
        private:
            Player &p1;
            Player &p2;

            std::vector<std::string> l_stat;
            int draws;
            int num_of_moves;
            bool ended;


        public:
        Game(Player &player1, Player &player2);
        /*printing turns*/
            void playTurn();

        /*print the last turn stats*/
            void printLastTurn();

        /*playes the game untill the end*/
            void playAll();

        /*prints the name of the winning player*/
            void printWiner();

        /*prints all the turns played one line per turn*/
            void printLog();

        /*printing state of play*/
            void printStats();

        /*booean for when the game finally end*/
        bool ended_Now();
        
    };
    
};

#endif
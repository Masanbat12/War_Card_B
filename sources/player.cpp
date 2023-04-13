#include "card.hpp"
#include "player.hpp"
using namespace std;
namespace ariel{
    
    string name;
    Player::Player(string name)
    {
        this->name = name;
        this->cards_Taken = 0;
        this->moves_that_played = 0;
        this->move_Won = 0;
        this->_is_active = false;
    };

     bool Player::get_is_active(){
        return this->_is_active;
    }

    int Player::stacksize()
    {
        return pile.size();
    }

    int Player::cardesTaken()
    {
        return this->cards_Taken;
    }

    void Player::addCard(card c)
    {
        this->pile.push(c);
    }

    card Player::play_Card()
    {
        card played_card = pile.top();
        pile.pop();
        return played_card;
    }

    std::string Player::t_for_log(card pl_card)
    {
        return this->name + " played the card " + pl_card.to_string();
    }

    std::string Player::get_name()
    {
        return this->name;
    }

/*In this function we adding another turn to the 2 players,
  and add the player that won the card of his foe.*/
    void Player::add_round(int c_Won) 
    {
    this->moves_that_played++;
    this->cards_Taken += c_Won ? c_Won : 0;
    this->move_Won += c_Won ? 1 : 0;
    }

   void Player::print_stats() 
   {
    cout << " " << "\n" << endl;
    cout << "Player: " << this->name << ", ststs: " << "\n" << endl;
    double win_Rate = this->move_Won;
    win_Rate /= this->moves_that_played;
    cout<< "win rate: " << win_Rate << "\n" << endl;
    cout << "cards won: " << this->cards_Taken <<"\n";
    cout << "Moves played by the 2 players: " << this->moves_that_played << "\n" << endl;
    cout << "Moves won by player: " << this->move_Won << "\n" << endl;
    cout << "Cards taken by player: " << this->cards_Taken << "\n" << endl;
   }
};
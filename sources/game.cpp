#include "game.hpp"

namespace ariel{
using namespace std;

/*creating an deck of 52 cards*/
void c_deck(stack<card>& deck1)
{
    // Clear the existing deck
    while (!deck1.empty()) {
        deck1.pop();
    }

    // Add cards to the deck, creating 52 cards.
    for (int type = 1; type <= 4; type++) 
    {
        for (int num = 1; num <= 13; num++) 
        {
            // Create a new card object and add it to the deck
            card new_card(num, static_cast<Type>(type));
            deck1.push(new_card);
        }
    }
}

void shuffle_deck(std::stack<card>& deck2) 
{
/* Converting the deck to a vector to make shuffling easier */
    std::vector<card> vec;
    while (!deck2.empty()) 
    {
        vec.push_back(deck2.top());
        deck2.pop();
    }
/* Shuffle the vector using the default_random_engine */
    std::default_random_engine rng(std::random_device{}());
    std::shuffle(vec.begin(), vec.end(), rng);

/* Convert the shuffled vector back to a stack */
    for (auto& c : vec) {
        deck2.push(c);
    }
}
/*destribut the carde to the players*/
void destribut(std::stack<card>& deck3, Player &p1, Player &p2)
{
    for (unsigned long int i = 0; i < 26; i++) 
   {
        p1.addCard(deck3.top());
        deck3.pop();
        p2.addCard(deck3.top());
        deck3.pop();
   }
}

Game::Game(Player &p1_, Player &p2_)
//intilize players
:p1(p1_), p2(p2_)
{
    if(p1.get_is_active() || p2.get_is_active())
    {
        throw invalid_argument("one of them is already playing");
    }
    stack<card> deck;
    this->draws = 0;
    this->num_of_moves = 0;
    c_deck(deck);
    shuffle_deck(deck);
    destribut(deck, p1, p2);
}

/* this not function not well written, but from lake of time need to submitt it like this. */
void Game::playTurn()
{
    if(p1.stacksize() == 0)
    {
        
        throw "The Game had been ended\n";
    }
    if (&p1 == &p2)
    {
        throw "Error!, this is the same player thats play against himself, but this forbidden!\n";
    }
   // Initialize variables
    int cardsPlayed = 0;
    int cardsWon = 0;
    std::string roundLog = "";

    // Play the round until it ends
    while (1) {
        // Increment the round counter
        num_of_moves++;
        // Get the cards played by each player
        card player1Card, player2Card;
        if (p1.stacksize() == 0 || p2.stacksize() == 0) 
        {
            if (cardsPlayed == 0) 
            {
                throw "No more cards to play";
            }
            // Give the remaining cards to the players
            p1.add_round(cardsPlayed / 2);
            p2.add_round(cardsPlayed / 2);
            // End the round of game
            break;
        }
        player1Card = p1.play_Card();
        player2Card = p2.play_Card();
        cardsPlayed += 2;
        roundLog += p1.t_for_log(player1Card) + " " + p2.t_for_log(player2Card);
        // Determine the winner of the round
        if (player1Card.get_num() == player2Card.get_num()) 
        {
            // If the cards are the same, start a war
            roundLog += "Draw.";
            draws++;
    
            // Play two more cards
            if (p1.stacksize() < 2 && p2.stacksize() < 2) 
            {
                if (p1.stacksize() == 1  && p2.stacksize() == 1)
                {
                    p1.play_Card();
                    p2.play_Card();
                    cardsPlayed += 2;
                }
                p1.add_round(cardsPlayed/2);
                p2.add_round(cardsPlayed/2);
                break;
            } 
            // draw and we can play
            p1.play_Card();
            p2.play_Card();
            cardsPlayed += 2;
            continue;
        }
    else if ((player1Card.get_num() == 1 && player2Card.get_num() != 2) || 
     (player1Card.get_num() > player2Card.get_num()))
        {
            // If player p1 wins
            roundLog += p1.get_name() + " wins.";
            p1.add_round(cardsPlayed);
            p2.add_round(0);
            break;
        }
    else {
            // If player 2 wins
            roundLog += p2.get_name() + " wins.";
            p2.add_round(cardsPlayed);
            p1.add_round(0);
            break;
        }
    }
    l_stat.push_back(roundLog + "\n");
};

void Game::printLastTurn()
{
    cout << this->l_stat.back();
};

void Game::playAll()
{
    while (p1.stacksize() > 0 && p2.stacksize() > 0)
        {
            cout << p1.stacksize()<<endl;
            playTurn();
        }
};

void Game::printWiner()
{
    if (p1.cardesTaken() > p2.cardesTaken())
        {
            cout << "The winning player is " + p1.get_name() << endl;
        }
        else
        {
            cout << "The winning player is " + p2.get_name() << endl;
        }
};

void Game::printLog()
{
    for (size_t i = 0; i < l_stat.size(); i++)
    {
        cout << l_stat.at(i);
    }
    
};

void Game::printStats()
{
    cout << " " << "\n" << endl;
    p1.print_stats();
    p2.print_stats();
    double draw_R = static_cast<double>(draws);
    draw_R = static_cast<double>(draws) / num_of_moves;
    cout << "draw_Rate : " << draw_R << endl;
    cout << "total draws :" << this->draws << endl;

}
 
};
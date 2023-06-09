//file:Player.hpp
#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_
#include <list>
#include <vector>

#include "DeckBuilder.hpp"
#include "TypeConverter.hpp"

#define NO_HAND 6
#define NO_PROVINCES 4

using namespace std;

class Player{
private:
	DeckBuilder deck;
	list<GreenCard*>* fateDeck;
	list<BlackCard*>* dynastyDeck;
	vector<GreenCard*> hand;
	vector<Holding*> holdings;
	vector<Personality*> army;
	vector<unsigned int> arena; //vector arena keeps track of army's indexes that are set for battle
	unsigned int numberOfProvinces;
	vector<BlackCard*> provinces;
	unsigned int money;  //amount of money the player currently has
	unsigned int roundMoney; //amount of money the player has at beginning of round;


public:
	std::string name;
	Player(const std::string &name);
   ~Player();

   void printGameStatistics();
   unsigned int give_no_provinces();

	//Starting Phase functions
	void startingPhase();
	void untapEverything();
	void drawFateCard();
	void revealProvinces();
	void printHand() const;
	void printProvinces() const;

	//Equip Phase functions
	void equipPhase();
	void tapHoldings();
	void printArmy() const;

	//Battle Phase functions
	void battlePhase(Player *p);
	void decrease_arena(unsigned int pos);
	bool hasArmy();

	//Economy Phase functions
	void economyPhase();
	void printHoldings() const;
	void checkChains(Holding* holding);
	void equipProvince(BlackCard* card);

	//Ending Phase functions
	void endingPhase();
	void discardSurplusFateCards();
	void printArena() const;

};

#endif

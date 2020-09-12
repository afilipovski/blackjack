#pragma once
#include<iostream>
#include<vector>
#include<ctime>
int random();
class Blackjack {
public:
	Blackjack(int _nr_decks = 1): nr_decks(_nr_decks), max_sp_card(_nr_decks * 4) {}
	int cards_dealt(int card) {
		return nr_sp_card[card - 1];
	}
	int max_sp() {
		return max_sp_card;
	}
	void deal_card(int card) {
		nr_sp_card[card - 1]++;
	}
private:
	int nr_decks;
	int nr_sp_card[14] = {0};
	int max_sp_card;
};
class Player {
	friend std::ostream& print_cards(const Player &pl, std::ostream &os);
public:
	Player(Blackjack &game): _game(&game) {
		deal_card(random()); deal_card(random());
	}
	bool fold() {
		return _fold;
	}
	void set_fold(bool value) {
		_fold = value;
	}
	int sum_cards() {
		return _sum_cards;
	}
	void deal_card(int card) {
		if (card == 1 && (21 - _sum_cards) > 11) {
			cards.push_back(11);
			_sum_cards += 11;
		}
		else {
			cards.push_back(card);
			_sum_cards += ((card > 11) ? 10 : card);
		}
		_game->deal_card(card);
	}
private:
	Blackjack *_game;
	bool _fold = 0;
	int _sum_cards = 0;
	std::vector<int> cards;
};
std::ostream& print_cards(const Player &pl, std::ostream &os);
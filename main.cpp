#include "Blackjack.h"
#include<ctime>
int main() {
	srand(time(NULL));
	int decks;
	std::cout << "Enter number of decks: ";
	std::cin >> decks;
	Blackjack game(decks);
	Player player(game);
	Player dealer(game);
	while ((player.sum_cards() < 21 && !player.fold()) || (dealer.sum_cards() < 21 && !dealer.fold())) {
		if (dealer.sum_cards() < 21 && !dealer.fold()) {
			if (dealer.sum_cards() < 18)
				while (true) {
					int random = rand() % 14;
					random++;
					if (random == 11)
						random = 1;
					if (game.cards_dealt(random) < game.max_sp()) {
						dealer.deal_card(random);
						break;
					}
				}
			else
				dealer.set_fold(1);
		}
		if (player.sum_cards() < 21 && !player.fold()) {
			char izbor;
			std::cout << "\n\nYou currently have the following cards: ";
			print_cards(player, std::cout) << std::endl;
			std::cout << "The sum of your cards is " << player.sum_cards() << std::endl;
			std::cout << "To stand enter EOF, to hit enter anything else: ";
			if (std::cin >> izbor)
				while (true) {
					int karta = random();
					if (game.cards_dealt(karta) < game.max_sp()) {
						player.deal_card(karta);
						break;
					}
				}
			else {
				player.set_fold(1);
			}
		}
	}
	std::cout << "\n\nThe game is over." << std::endl;
	std::cout << "The dealer has a card sum of " << dealer.sum_cards() << " and his cards are: ";
	print_cards(dealer, std::cout) << std::endl;
	std::cout << "You have a card sum of " << player.sum_cards() << " and your cards are: ";
	print_cards(player, std::cout) << std::endl;
	if (player.sum_cards() > 21 || (player.sum_cards() < dealer.sum_cards() && dealer.sum_cards() < 22))
		std::cout << "You have lost.\n" << std::endl;
	else if (player.sum_cards() == dealer.sum_cards())
		std::cout << "It's a tie.\n" << std::endl;
	else
		std::cout<<"You have won.\n"<<std::endl;
	system("PAUSE");
	return 0;
}

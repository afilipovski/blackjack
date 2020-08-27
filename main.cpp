#include "Blackjack.h"
#include<ctime>
int random();
int main() {
	srand(time(NULL));
	int spilovi;
	std::cout << "Dobredojdovte vo kazino ako ste spremni da go prokockate svojot imot vnesete broj na spilovi: ";
	std::cin >> spilovi;
	Blackjack igra(spilovi);
	Igrac igrac(igra);
	Igrac diler(igra);
	while ((igrac.suma_karti() < 21 && !igrac.fold()) || (diler.suma_karti() < 21 && !diler.fold())) {
		if (diler.suma_karti() < 21 && !diler.fold()) {
			if (diler.suma_karti() < 18)
				while (true) {
					int random = rand() % 14;
					random++;
					if (random == 11)
						random = 1;
					if (igra.podeleni_karti(random) < igra.max_sp()) {
						diler.dodadi_karta(random);
						break;
					}
				}
			else
				diler.set_fold(1);
		}
		if (igrac.suma_karti() < 21 && !igrac.fold()) {
			char izbor;
			std::cout << "\n\nVo momentot raspolagate so slednite karti: ";
			pecati_karti(igrac, std::cout) << std::endl;
			std::cout << "Zbirot na vasite karti iznesuva " << igrac.suma_karti() << std::endl;
			std::cout << "Za da se otkazete vnesete EOF, za da prodolzite bilo sto drugo: ";
			if (std::cin >> izbor)
				while (true) {
					int karta = random();
					if (igra.podeleni_karti(karta) < igra.max_sp()) {
						igrac.dodadi_karta(karta);
						break;
					}
				}
			else {
				igrac.set_fold(1);
			}
		}
	}
	std::cout << "\n\nIgrata e zavrsena." << std::endl;
	std::cout << "Dilerot ima zbir od " << diler.suma_karti() << " i negovite karti se: ";
	pecati_karti(diler, std::cout) << std::endl;
	std::cout << "Vie imate zbir od " << igrac.suma_karti() << " i vasite karti se: ";
	pecati_karti(igrac, std::cout) << std::endl;
	if (igrac.suma_karti() > 21 || (igrac.suma_karti() < diler.suma_karti() && diler.suma_karti() < 22))
		std::cout << "Vie izgubivte.\n" << std::endl;
	else if (igrac.suma_karti() == diler.suma_karti())
		std::cout << "Izednaceno.\n" << std::endl;
	else
		std::cout<<"Vie pobedivte.\n"<<std::endl;
	system("PAUSE");
	return 0;
}
#include "Blackjack.h"
int random() {
	int rand_no = rand() % 14;
	rand_no++;
	if (rand_no == 11)
		rand_no = 1;
	return rand_no;
}
std::ostream& pecati_karti(const Igrac &ig, std::ostream &os) {
	for (int i : ig.karti) {
		switch (i) {
		case 1:
			os << "A ";
			break;
		case 11:
			os << "A ";
			break;
		case 12:
			os << "J ";
			break;
		case 13:
			os << "Q ";
			break;
		case 14:
			os << "K ";
			break;
		default:
			os << i << " ";
			break;
		}
	}
	os << std::flush;
	return os;
}
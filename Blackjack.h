#pragma once
#include<iostream>
#include<vector>
#include<ctime>
int random();
class Blackjack {
public:
	Blackjack(int _br_spilovi = 1): br_spilovi(_br_spilovi), max_sp_karta(_br_spilovi * 4) {}
	int podeleni_karti(int karta) {
		return br_sp_karta[karta - 1];
	}
	int max_sp() {
		return max_sp_karta;
	}
	void dodadi_karta(int karta) {
		br_sp_karta[karta - 1]++;
	}
private:
	int br_spilovi;
	int br_sp_karta[14] = {0};
	int max_sp_karta;
};
class Igrac {
	friend std::ostream& pecati_karti(const Igrac &ig, std::ostream &os);
public:
	Igrac(Blackjack &igra): _igra(&igra) {
		dodadi_karta(random()); dodadi_karta(random());
	}
	bool fold() {
		return _fold;
	}
	void set_fold(bool vrednost) {
		_fold = vrednost;
	}
	int suma_karti() {
		return _suma_karti;
	}
	void dodadi_karta(int karta) {
		if (karta == 1 && (21 - _suma_karti) > 11) {
			karti.push_back(11);
			_suma_karti += 11;
		}
		else {
			karti.push_back(karta);
			_suma_karti += ((karta > 11) ? 10 : karta);
		}
		_igra->dodadi_karta(karta);
	}
private:
	Blackjack *_igra;
	bool _fold = 0;
	int _suma_karti = 0;
	std::vector<int> karti;
};
std::ostream& pecati_karti(const Igrac &ig, std::ostream &os);
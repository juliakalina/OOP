#include "LINK.h"

namespace ArmyBase {

	Armament::Armament() {
		type= heavy;
		name="GUN";
		maxReserve = 10;
		nowReserve = 5;
		nameAmmo = "BB-210L";
		price = 10;
		active=false;
		loss=0;
		dist=4.1;
		rate=2.2;
		reloadSpeed = 0.2;
	}

	Armament::Armament(Type typeA, string nameA, double speedA, int priceA) {
		type = typeA;
		name = nameA;
		reloadSpeed = speedA;
		price = priceA;
	}

	Armament::Armament(string nm, Type tp) {
		type = tp;
		name = nm;
		active = false;
		loss = 0;
		dist = 4.1;
		rate = 2.2;
	}

	void Armament::shoot(Plane* target) {
		if(nowReserve > target->getSurvival())
		target->takeLoss(loss);

		nowReserve -= target->getSurvival();
		if (!nowReserve) {
			active = false;
		}
	}

	void Armament::shoot(Ship* target) {
		if (nowReserve > target->getSurvival())
			target->takeLoss(loss);

		nowReserve -= target->getSurvival();
		if (!nowReserve) {
			active = false;
		}
	}

	void Armament::reload(std::vector<Reserve> reserve) {
		int i = 0;
		while (nameAmmo != reserve.at(i).name) {
			i++;
		}
		if (!active && maxReserve - nowReserve <= reserve.at(i).cnt) { 
			active = true;
			reserve.at(i).cnt = reserve.at(i).cnt - (maxReserve - nowReserve);
		}
	}

}
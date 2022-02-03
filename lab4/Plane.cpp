#include "LINK.h"

namespace ArmyBase {

	Plane::Plane() {
		type = destroyer; 
		loss = 1;
		active = false;
		survival = 3;
		speed = 10;
		fuelAll = 6;
		fuelLoss = 1;
		speedEquipment = 1.45;
		price = 70;
	}

	Plane::Plane(PlaneType typeP, double speedP, int priceP, bool activeP,int survivalP) {
		type = typeP;
		loss = 1;
		survival = 3;
		speed = speedP;
		price = priceP;
		active = activeP;
		survival = survivalP;
		fuelAll = 6;
		fuelLoss = 1;
		speedEquipment = 1.45;
	}

	double Plane::getRad() {
		return fuelAll / 2* fuelLoss;
	}

	void Plane::attack(Ship* ship) {
		active = true;
		//fuelLoss -= 
		ship->setSurvival(ship->getSurvival() - loss);
	}

	void Plane::attack(Plane* plane) {
		active = true;
		plane->setSurvival(plane->getSurvival() - loss);
	}
}
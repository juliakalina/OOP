#include "LINK.h"

namespace ArmyBase {

	Ship::Ship() { 
		shipName = "MayFlower";  
		captain = new Captain();
		captain->rank = 1;
		captain->name = "Sparrow"; 
		speed = 10;
		price = 100;
	}

	Ship::Ship(Captain* newCaptain, int newType, string newShipName, int newPrice, double newSpeed, Point* newPoint, int newSurvival) {
		captain = new Captain();
		captain = newCaptain;
		type = newType;
		shipName = newShipName;
		price = newPrice;
		speed = newSpeed;
		point = newPoint;
		way = newPoint;
		survival = newSurvival;
	}

	Ship& Ship::setWay(int x, int y) {
		way->x = x;
		way->y = y;
		return*this;
	}

	Ship& Ship::setType(int tip) {
		type = tip;
		return*this;
	}

	Ship& Ship::setShipName(string name) {
		shipName = name;
		return*this;
	}

	Ship& Ship::setCap(Captain* cap) {
		captain = cap;
		return *this;
	}

	Ship& Ship::setCap(double sp) {
		speed = sp;
		return*this;
	}
}

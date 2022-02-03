#include "LINK.h"

namespace ArmyBase {

	AircraftCruiser::AircraftCruiser() {
		type = 3;
		maxCntPlane = 15;
		maxCntArma = 30;
	}

	AircraftCruiser::AircraftCruiser(Captain* captainAC, string shipNameAC, double speedAC, int priceAC, int maxCntAC, int maxSizeAC, Point* pointAC, int typeAC, int survivalAC):
		Cruiser(captainAC, shipNameAC, speedAC, priceAC, maxCntAC, maxSizeAC, pointAC, typeAC, survivalAC), Aerocarrier(captainAC, pointAC, priceAC, typeAC, shipNameAC, speedAC, maxCntAC, survivalAC) {
		captain = captainAC;
		type = 3;
		point = new Point();
		point->x = pointAC->x;
		point->y = pointAC->y;
		way = new Point();
		way->x = pointAC->x;
		way->y = pointAC->y;
		maxCntPlane = 15;
		maxCntArma = 30;
	} 

	void AircraftCruiser::setPlane(Plane* plane) 
	{
		planeInfo.push_back(plane);
	}

	AircraftCruiser& AircraftCruiser::setReserve(Reserve* res) {
		warehouse.push_back(res);
		return *this;
	}

	AircraftCruiser& AircraftCruiser::delReserve(Reserve* res) {
		warehouse.clear();
		return *this;
	}

	int AircraftCruiser::getSumPrice() {
		int pr = Ship::price;
		for (int i = 0; i < armInfo.size(); i++) {
			pr += armInfo.at(i)->getPrice();
		}
		for (int i = 0; i < warehouse.size(); i++) {
			pr += warehouse.at(i)->price;
		}
		for (auto it = planeInfo.begin(); it < planeInfo.end(); it++) {
			pr += (*it)->getPrice();
		}
		return pr;
	}

	AircraftCruiser& AircraftCruiser::setMaxCntPlane(int pl) {
		maxCntPlane = pl;
		return*this;
	}

	AircraftCruiser& AircraftCruiser::setMaxCntArma(int arm) {
		maxCntArma = arm;
		return *this;
	}
} 
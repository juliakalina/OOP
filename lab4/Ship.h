#ifndef SHIP_H_
#define SHIP_H_

namespace ArmyBase {

	typedef struct Captain {
		int rank;
		string name;
	} Captain;

	typedef struct Point {
		int x, y;
	} Point;

	typedef struct Reserve {
		string name;
		int cnt;
		int size;
		int price;
		Reserve() {
			name = "gun";
			cnt = 5;
			size = 1;
			price = 15;
		};
		Reserve(string nm) {
			name = nm;
			cnt = 5;
			size = 1;
			price = 15;
		}
	}Reserve;

	class Ship {
	protected:
		Point* way;
		int survival; 
		Point* point;
		int type; // 0 - cruiser, 1 - Aerocarrier, 2 - Aircraftcruiser
		string shipName;
		Captain* captain;
		double speed;
		int price;
	public:
		Ship();
		Ship(Captain* newCaptain, int newType, string newShipName, int newPrice, double newSpeed, Point* newPoint, int newSurvival);

		Ship(const Ship& ship) {
			way = ship.way;
			survival = ship.survival;
			point = ship.point;
			type = ship.type;
			shipName = ship.shipName;
			captain = ship.captain; 
			speed = ship.speed;
			price = ship.price; 
		}

		Ship(Ship& ship) {
			way = ship.way;
			survival = ship.survival;
			point = ship.point;
			type = ship.type;
			shipName = ship.shipName;
			captain = ship.captain;
			speed = ship.speed;
			price = ship.price;
		}
		~Ship() { delete point; delete captain; };

		Point* getCoord() { return point; };
		virtual Captain* getCaptain() { return captain; }
		int getSurvival() { return survival; };
		int getType() { return type; };
		Point* getWay() { return way; };
		string getShipName() { return shipName; };
		double getSpeedName() { return speed; };
		int getPrice() { return price; };

		Ship& setSurvival(int survS) { survival = survS; return *this; };
		Ship& setPoint(int x, int y) { point->x = x; point->y=y; return *this; };
		Ship& moveShip(Point* points) { way = points; return *this; }; 
		Ship& setWay(int x, int y); 
		Ship& setType(int tip);
		Ship& setShipName(string name);
		Ship& setCap(Captain* captain);
		Ship& setCap(double sp);

		Ship& takeLoss(int loss) { survival -= loss; return *this; };// урон живучесть стоимость?

		virtual int getSumPrice() { return price; };
};
}
#endif
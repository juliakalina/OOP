#ifndef PLANE_H_
#define PLANE_H_

namespace ArmyBase {

	class Plane {
	private:
		PlaneType type;
		int loss; 
		bool active;
		int survival;
		double speed;
		int fuelAll;
		int fuelLoss; 
		double speedEquipment;
		int price;

	public:
		Plane();
		Plane(PlaneType type, double speed, int price, bool activeP, int survivalP);

		int getLoss() { return loss; };
		PlaneType getType() { return type; };
		bool getActive() { return active; };
		int getSurvival() { return survival; };
		double getSpeed() { return speed; };
		int getFuelLoss() { return fuelLoss; }; 
		int getFuelAll() { return fuelAll; };
		double getSpeedEquipment() { return speedEquipment; };
		int getPrice() { return price; };

		Plane& setType(PlaneType typeS) { type = typeS; return *this; };
		Plane& setLoss(int lossS) { loss = lossS; return *this; };
		Plane& setActive(bool activeS) { active = activeS; return *this; };
		Plane& setSurvival(int survivalS) { survival = survivalS; if (survival < 0) active = false; return *this; };
		Plane& setSpeed(double speedS) { speed = speedS; return *this; };
		Plane& setFuelAll(int fuelAllS) { fuelAll = fuelAllS; return *this; };
		Plane& setFuelLoss(int fuelLossS) { fuelLoss = fuelLossS; return *this; };
		Plane& setSpeedEquipment(int speedEquipmentS) { speedEquipment = speedEquipmentS; return *this; };
		Plane& setPrice(int priceS) { price = priceS; return *this; };
		Plane& takeLoss(int los) { survival -= loss; return *this; }; 

		double getRad();
		void attack(Ship* ship);
		void attack(Plane* plane);

	};

}

#endif
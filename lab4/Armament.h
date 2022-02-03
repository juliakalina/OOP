#ifndef ARMAMENT_H_
#define ARMAMENT_H_

namespace ArmyBase {

	class Armament {
	private:
		string name;
		Type type; 
		int maxReserve;
		int nowReserve; 
		string nameAmmo;
		int price; 
		bool active;
		int loss; 
		int dist;
		int rate;
		double reloadSpeed;


	public:
		Armament();
		Armament(Type typeA, string nameA, double speedA, int price);
		Armament(string, Type);

		Type getType() { return type; };
		int getPrice() { return price; };
		string getName() { return name; };
		int getLoss() { return loss; };
		bool getActive() { return active; };
		int getDist() { return dist; };
		int getMaxReserve() { return maxReserve; };
		int getNowReserve() { return nowReserve; };
		string getNameAmmo() { return nameAmmo; };
		int getRate() { return rate; };
		double getReloadSpeed() { return reloadSpeed; };

		Armament& setName(string nameS) { name = nameS; return *this; };
		Armament& setType(Type typeS) { type = typeS; return *this; };
		Armament& setMaxReserve(int maxReserveS) { maxReserve = maxReserveS; return *this; };
		Armament& setNowReserve(int nowReserveS) { nowReserve = nowReserveS; return *this; };
		Armament& setNameAmmo(string nameAmmoS) { nameAmmo = nameAmmoS; return *this; };
		Armament& setPrice(int priceS) { price = priceS; return *this; };
		Armament& setActive(bool activeS) { active = activeS; return *this; };
		Armament& setLoss(int lossS) { loss = lossS; return *this; };
		Armament& setDist(int distS) { dist = dist; return *this; };
		Armament& setRate(int rateS) { rate = rateS; return *this; };
		Armament& setReloadSpeed(double reloadSpeedS) { reloadSpeed = reloadSpeedS; return *this; };

		void shoot(Plane* target);
		void shoot(Ship*);
		void reload(std::vector<Reserve> reserve);
	};

}

#endif
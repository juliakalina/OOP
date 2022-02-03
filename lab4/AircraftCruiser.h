#ifndef AIRCRAFTCRUISER_H_
#define AIRCRAFTCRUISER_H_


namespace ArmyBase{

	class AircraftCruiser : virtual public Cruiser, virtual public Aerocarrier {
	private:

		int maxCntPlane;
		int maxCntArma;
		
	public:
		virtual ~AircraftCruiser() { warehouse.clear(); planeInfo.clear(); }; 

		void setPlane(Plane*) override;

		AircraftCruiser();
		AircraftCruiser(Captain* captainAC, string shipNameAC, double speedAC, int priceAC, int maxCntAC, int maxSizeAC, Point* pointAC, int typeAC, int survivalAC);
	
		std::vector<Reserve*> getInfoReserve() { return warehouse; };
		AircraftCruiser& setArmament(Armament* arm) { armInfo.push_back(arm); return*this; };
		int getMaxCntPlane() { return maxCntPlane; };
		int getMaxCntArma() { return maxCntArma; };

		AircraftCruiser& setReserve(Reserve* res);
		AircraftCruiser& setMaxCntPlane(int pl);
		AircraftCruiser& setMaxCntArma(int arm);

		AircraftCruiser& delReserve(Reserve* res);

		int getSumPrice() override;
	};

}

#endif 
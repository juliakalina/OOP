#ifndef CRUISER_H_
#define CRUISER_H_

namespace ArmyBase {

    enum Type {
        light, heavy
    };

    class Cruiser : virtual public Ship {
    protected:
        std::vector<Armament*> armInfo;
        int maxCnt;
        int maxSize;
        std::vector<Reserve*> warehouse;

    public:
        Cruiser();
        Cruiser(Captain* captainC, string shipNameC, double speedC, int priceC, int maxCntC, int maxSizeC, Point* pointC, int typeC, int survivalC);

        ~Cruiser() { warehouse.clear(); };

        int getSumPrice() override;

        int getCnt() { return maxCnt; };
        int getSize() { return maxSize; };
        Captain* getCaptain() override { return captain; }
        std::vector<Reserve*> getInfoReserve() { return warehouse; };
        Cruiser& setArmament(Armament* arm) { armInfo.push_back(arm); return*this; };
        std::vector<Armament*> getInfoArmament() { return armInfo; };

        Cruiser& setCnt(int maxCntS) { maxCnt = maxCntS; return *this; };
        Cruiser& setSize(int maxSizeS) { maxSize = maxSizeS; return *this; };
        Cruiser& setArmament(std::vector<Armament*> armInfoS) { armInfo = armInfoS; return *this; };
        Cruiser& setInfoArmament(string nameC, Type typeC, int maxReserveC, int nowReserveC,
        string nameAmmoC, int priceC, bool activeC, int lossC, int distC, int rateC, double reloadSpeedC);
        Cruiser& setInfoReserve(int typeR, string nameR, int cntR, int sizeR, int priceR);
        Cruiser& setReserve(Reserve* res);

        Cruiser& delArmament(Armament* arm);

        bool freeSpace();
        void attackShip(std::vector<Ship*> ships, Point point, Armament arm, std::vector<Reserve> warehouse);
        void attackPlane(Plane* plane, Armament arm, std::vector<Reserve> warehouse);
        void reload(Armament arm, std::vector<Reserve> warehouse);
        void delReserve(Reserve* reserve);
    };

}

#endif
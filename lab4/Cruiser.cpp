#include "LINK.h"

namespace ArmyBase {

    Cruiser::Cruiser() : Ship() {
        type = 1;
        armInfo.push_back(new Armament());
        maxCnt = 2;
        maxSize = 20;
        warehouse.push_back(new Reserve());
    }

    Cruiser::Cruiser(Captain* captainC, string shipNameC, double speedC, int priceC, int maxCntC, int maxSizeC, Point* pointC, int typeC, int survivalC) :
        Ship(captainC, typeC, shipNameC, speedC, priceC, pointC, survivalC) {
        type = 1;
        maxCnt = maxCntC;
        maxSize = maxSizeC;
    }

    Cruiser& Cruiser::setInfoReserve(int typeR, string nameR, int cntR, int sizeR, int priceR) {
        for (int i = 0; i < warehouse.size(); i++) {
            if (warehouse.at(i)->name == nameR) {
                warehouse.at(i)->cnt = cntR;
                warehouse.at(i)->price = priceR;
                warehouse.at(i)->size = sizeR;
            }
        }
        return *this;
    }

    Cruiser& Cruiser::setReserve(Reserve* res) {
        warehouse.push_back(res);
        return *this;
    }

    Cruiser& Cruiser::setInfoArmament(string nameC, Type typeC, int maxReserveC, int nowReserveC,
        string nameAmmoC, int priceC, bool activeC, int lossC, int distC, int rateC, double reloadSpeedC) {
        for (int i = 0; i < armInfo.size(); i++) {
            if (armInfo.at(i)->getName() == nameC) {
                armInfo.at(i)->setType(typeC);
                armInfo.at(i)->setMaxReserve(maxReserveC);
                armInfo.at(i)->setNowReserve(nowReserveC);
                armInfo.at(i)->setNameAmmo(nameAmmoC);
                armInfo.at(i)->setPrice(priceC);
                armInfo.at(i)->setActive(activeC);
                armInfo.at(i)->setLoss(lossC);
                armInfo.at(i)->setDist(distC);
                armInfo.at(i)->setRate(rateC);
                armInfo.at(i)->setReloadSpeed(reloadSpeedC);
            }
        }
        return *this;
    }

    Cruiser& Cruiser::delArmament(Armament* arm) {
        for (auto it = armInfo.begin(); it < armInfo.end(); it++)
            if (arm == *it) {
                armInfo.erase(it);
                return *this;
            }
        return *this;
    }

    int Cruiser::getSumPrice() {
        int pr = price;
        for (int i = 0; i < armInfo.size(); i++) {
            pr += armInfo.at(i)->getPrice();
        }
        for (int i = 0; i < warehouse.size(); i++) {
            pr += warehouse.at(i)->price;
        }
        return pr;
    }

    bool Cruiser::freeSpace() {
        return maxSize == armInfo.size();
    }

    void Cruiser::attackShip(std::vector<Ship*> ships, Point point, Armament arm, std::vector<Reserve> warehouse) {
        if (arm.getType() == heavy) {
            for (int i = 0; i < ships.size(); i++)
                arm.shoot(ships.at(i));
            if (!arm.getActive())
                reload(arm, warehouse);
        }
    }

    void Cruiser::attackPlane(Plane* plane, Armament arm, std::vector<Reserve> warehouse) {
        if (arm.getType() == light) {
            arm.shoot(plane);
            if (!arm.getActive())
                reload(arm, warehouse);
        }
    }

    void Cruiser::reload(Armament arm, std::vector<Reserve> warehouse) {
        arm.reload(warehouse);
    }

    void Cruiser::delReserve(Reserve* reserve) {
        for (auto it = warehouse.begin(); it < warehouse.end(); it++) {
            if ((*it) == reserve) {
                warehouse.erase(it);
                return;
            }
        }
    }
}
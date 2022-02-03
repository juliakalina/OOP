#include "LINK.h"

namespace ArmyBase {

    Aerocarrier::Aerocarrier() : Ship() {
        type = 2;
        captain->name = "Dumin";
        Plane* plane = new Plane();
        planeInfo = { plane };
        maxPlane = 1;
    }

    Aerocarrier::Aerocarrier(string cpt) : Ship() {
        type = 2;
        captain->name = cpt;
        Plane* plane = new Plane();
        planeInfo = { plane };
        maxPlane = 1;
    }

    Aerocarrier::Aerocarrier(Captain* newCaptain, Point* newPoint, int newPrice, int newType, string newShipName, double newSpeed, int newMaxCnt, int survival) :
        Ship(newCaptain, newType, newShipName, newPrice, newSpeed, newPoint, survival) {
        type = 2;
        point = new Point();
        point->x = newPoint->x;
        point->y = newPoint->y;
        planeInfo.push_back(new Plane());
        maxPlane = newMaxCnt;
    }

    void Aerocarrier::setPlane(Plane* plane) {
        planeInfo.push_back(plane);
    }

    Aerocarrier& Aerocarrier::setMaxPlane(int max) {
        maxPlane=max;
        return *this;
    }


    int Aerocarrier::getSumPrice() {
        int sumPrice = price;
        for (auto it = planeInfo.begin(); it < planeInfo.end(); it++) {
            sumPrice += (*it)->getPrice();
        }

        return sumPrice;
    }

    string Aerocarrier::getInfoPlane() {
        std::string str = "Num.\tTYPE\t\tLOSS\tACTIVE\t\tSURVIVAL\tSPEED\tFUELall\tFUELloss\tSPEEDEQUIPMENT\tPRICE\n";
        int k = 0;
        for (auto i = planeInfo.begin(); i < planeInfo.end(); i++, k++) {
            str = str + char(k + 48) + ".\t";
            if ((*i)->getType() == destroyer) {
                str += "destroyer\t";
            } 
            else
                str += "stormtrooper\t";
            str = str + std::to_string((*i)->getLoss()) + "\t";
            if ((*i)->getActive())
                str += "active\t\t";
            else
                str += "not active\t";
            str = str + std::to_string((*i)->getSurvival()) + "\t\t";
            str = str + std::to_string((*i)->getSpeed()) + "\t";
            str = str + std::to_string((*i)->getFuelAll()) + "\t";
            str = str + std::to_string((*i)->getFuelAll()) + "\t";
            str = str + std::to_string((*i)->getSpeedEquipment()) + "\t";
            str = str + std::to_string((*i)->getPrice()) + "\n";
        }
        return str;
    }

    void Aerocarrier::setInfoPlane(PlaneType kind, bool act, double sped, int survival, int fLoss, int cnt) {
        for (size_t i = 0; (i < planeInfo.size()) && (i < cnt); i++) {
            if (planeInfo.at(i)->getType() == kind) {
                planeInfo.at(i)->setActive(act);
                planeInfo.at(i)->setSpeed(sped);
                planeInfo.at(i)->setSurvival(survival);
                planeInfo.at(i)->setFuelLoss(fLoss);
            }
        }
    }

    bool Aerocarrier::damageShip(std::vector<Ship*> ship, Point* cor) {
        std::vector<Ship*> nov;
        for (int i = 0; i < ship.size(); i++) {
            if (ship.at(i)->getCoord()->x == cor->x && ship.at(i)->getCoord()->y == cor->y) {
                nov.push_back(ship.at(i));
            }
        }
        if (nov.size()) {
            for (int i = 0; i < nov.size(); i++) {
                nov.at(i)->setSurvival(0);
            }
            return true;
        }
        else return false;
    }

    bool Aerocarrier::damagePlane(std::vector<Plane*> enemy, Point* pointTo) {
        int num = 0;
        std::vector<Plane*> group;
        
        for (size_t i = 0; (i < planeInfo.size()) && (num < 3); i++) {
            if (planeInfo.at(i)->getType() == destroyer && planeInfo.at(i)->getActive() && (culc(getCoord(), pointTo)) <= (planeInfo.at(i)->getFuelAll() / planeInfo.at(i)->getFuelLoss())) {
                group.push_back(planeInfo.at(i));
                num++;
            }
        }
        if (num == 3) {
            for (size_t i = 0; i < (enemy).size(); i++) {
                enemy.at(i)->setActive(0);
            }
            return true;
        }
        else return false;
    }

    void Aerocarrier::delPlane(Plane* plane) {
        for (auto it = planeInfo.begin(); it < planeInfo.end(); it++) {
            if ((*it) == plane) {
                planeInfo.erase(it);
                return;
            }
        }

    }

}
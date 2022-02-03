#include "LINK.h"

Mission::Mission() {
    A = new Table();
    B = new Table();
    comand = "Putin";
    maxA = 5;
    maxB = 5;
    moneyA = 1000;
    moneyB = 1000;
    wastedMoney = 0;
    lossA = 0;
    lossB = 0; 
    maxLoss = 3;
    safePrice = moneyB - lossB;
    baseA = { 0, 0 };
    baseB = { 4, 4 }; 
}


Mission::Mission(int mA, int mB) : Mission() {
    moneyA = mA;
    moneyB = mB;
}

Mission& Mission::setTable(Table* table, int money, int loss) {
    if (table == A) {
        moneyA = money;
        lossA = loss;
    }
    else {
        moneyB = money;
        lossB = loss;
    }
    return *this;
}

void Mission::buyShip(Table* table, Ship* ship) {
    //if (type == 1) { // type - 1 - Cruiser - cost: 100
        moneyA -= ship->getSumPrice();
        table->add(ship);

}

void Mission::sellShip(Table* table, string capt) {
    if (table == A && A->findTypeArm(capt)) { //    Cruiser - cost: 100 
        table->del(capt);
    }
    else if (table == B && A->findTypeArm(capt)) { // Cruiser - cost: 100
        table->del(capt);
    }
}

void Mission::buyPlane(Table* table, string name, Plane* plane) {
    Ship* ship = new Ship();
    ship = (*table).findTypeArm(name);

    if (ship->getType() == 2) {
        Aerocarrier* aerocar = dynamic_cast<Aerocarrier*>(ship);
        aerocar->setPlane(plane);
        if (table == A)
            moneyA -= plane->getPrice();
        else
            moneyB -= plane->getPrice();
    }
    else if(ship->getType() == 3) {
        AircraftCruiser* aircraft = dynamic_cast<AircraftCruiser*>(ship);
        aircraft->setPlane(plane);
        if (table == A)
            moneyA -= plane->getPrice();
        else
            moneyB -= plane->getPrice();
    }
}

void Mission::sellPlane(Table* table, string name, Plane* plane) {
    Ship* ship = (*table).findTypeArm(name);
    if (ship->getType() == 2) {
                Aerocarrier* aerocar = dynamic_cast<Aerocarrier*>(ship);
                    aerocar->delPlane(plane);
                    moneyA += 100;
            }
            else if (ship->getType() == 3) {

                AircraftCruiser* aircraft = dynamic_cast<AircraftCruiser*>(ship);
                aircraft->delPlane(plane);
                    moneyB += 100;
            }
}

void Mission::transferPlane(Table* table, Ship* old, Ship* nov, Plane* plane) {
    sellPlane(table, old->getCaptain()->name, plane);
    buyPlane(table, nov->getCaptain()->name, plane);
}


void Mission::buyArmament(Table * table, string cpt, Armament * arm) {
        Ship* ship = findShip(table, cpt);
        if (ship->getType() == 3) {
            AircraftCruiser* aircraft = dynamic_cast<AircraftCruiser*>(ship);
            aircraft->setArmament(arm);
            if (table == A)
                moneyA -= arm->getPrice();
            else
                moneyB -= arm->getPrice();
        }
        else if (ship->getType() == 1) {
            Cruiser* cruiser = dynamic_cast<Cruiser*>(ship);
            cruiser->setArmament(arm);
            if (table == A)
                moneyA -= arm->getPrice();
            else
                moneyB -= arm->getPrice();
        }
}

void Mission::sellArmament(Table* table, string cpt, Armament* arm) {
    Ship* ship = findShip(table, cpt);
    if (ship->getType() == 3) {
        AircraftCruiser* aircraft = dynamic_cast<AircraftCruiser*>(ship);
        aircraft->delArmament(arm);
        if (table == A)
            moneyA += arm->getPrice();
        else
            moneyB += arm->getPrice();
    }
    else if (ship->getType() == 1) {
        Cruiser* cruiser = dynamic_cast<Cruiser*>(ship);
        cruiser->delArmament(arm);
        if (table == A)
            moneyA += arm->getPrice();
        else
            moneyB += arm->getPrice();
    }
}

void Mission::buyAmmo(Table* table, string cpt, Reserve* reserve) {
    Ship* ship = findShip(table, cpt);

    if (ship->getType() == 3) {
        AircraftCruiser* aircraft = dynamic_cast<AircraftCruiser*>(ship);
        aircraft->setReserve(reserve);
        if (table == A)
            moneyA -= reserve->price;
        else
            moneyB -= reserve->price;
    }
    else if (ship->getType() == 1) {
        Cruiser* cruiser = dynamic_cast<Cruiser*>(ship);
        cruiser->setReserve(reserve);
        if (table == A)
            moneyA -= reserve->price;
        else
            moneyB -= reserve->price;
        for (int i = 0; i < cruiser->getInfoReserve().size(); i++)
            cout << cruiser->getInfoReserve().at(i)->name << endl;
    }
}

void Mission::sellAmmo(Table* table, string cpt, Reserve* reserve) {
    Ship* ship = findShip(table, cpt);

    if (ship->getType() == 3) {
            AircraftCruiser* aircraft = dynamic_cast<AircraftCruiser*>(ship);
            aircraft->delReserve(reserve);
            if (table == A)
                moneyA += reserve->price;
            else
                moneyB += reserve->price;
            for (int i = 0; i < aircraft->getInfoReserve().size(); i++)
                cout << aircraft->getInfoReserve().at(i)->name << endl;
        }
        else if (ship->getType() == 1) {
            Cruiser* cruiser = dynamic_cast<Cruiser*>(ship);
            cruiser->delReserve(reserve);
            if (table == A)
                moneyA += reserve->price;
            else
                moneyB += reserve->price;
            for (int i = 0; i < cruiser->getInfoReserve().size(); i++)
                cout << cruiser->getInfoReserve().at(i)->name << endl;
        }
}


bool attackTry(Ship* center, Armament* radius, Ship* point) {
    return sqrt(pow(abs(center->getCoord()->x - point->getCoord()->x), 2) + pow(abs(center->getCoord()->y - point->getCoord()->y), 2)) < radius->getDist() ? true : false;
}

bool attackTry(Ship* center, Plane* radius, Ship* point) {
    return sqrt(pow(abs(center->getCoord()->x - point->getCoord()->x), 2) + pow(abs(center->getCoord()->y - point->getCoord()->y), 2)) < radius->getRad() ? true : false;
}

bool Mission::killShip(Table* ours, Table* enemy, Ship* ship, int atackType) {  // 0 - ships, 1 - planes
   // bool f = false;
    if (atackType == 0) {
        vector<Armament*> arm;
        for (int i = 0; i < ours->getMembers().size(); i++)
            if (ours->getMembers()[i]->getType() == 1 ||
                ours->getMembers()[i]->getType() == 2) {
                Cruiser* cruis = dynamic_cast<Cruiser*>(ours->getMembers()[i]);
                for (int j = 0; j < cruis->getInfoArmament().size(); j++)
                    if(attackTry(cruis, cruis->getInfoArmament()[j], ship))
                    if (attackTry(cruis, cruis->getInfoArmament()[j], ship))
                        arm.push_back(cruis->getInfoArmament()[j]);
            }
        for (int i = 0; i < arm.size(); i++) {
            arm.at(i)->shoot(ship);
        }
    }
    else if (atackType == 1) {
        vector<Plane*> planes;
        for (int i = 0; i < ours->getMembers().size(); i++)
            if ((ours->getMembers()[i]->getType() == 1 ||
                ours->getMembers()[i]->getType() == 2)) {
                Aerocarrier* cruis = dynamic_cast<Aerocarrier*>(ours->getMembers()[i]);
                for (int j = 0; j < cruis->getVecPlane().size(); j++)
                    if (attackTry(cruis, cruis->getVecPlane()[j], ship))
                        planes.push_back(cruis->getVecPlane()[j]);
            }
        for (int i = 0; i < planes.size(); i++) {
            if (planes.at(i)->getType() == stormtrooper)
                planes.at(i)->attack(ship);
        }

    }
    if (ship->getSurvival() < 0)
        return true;
    else return false;
}

void Mission::enemyReach(Table* table, Ship* ship) {
    if (ship->getCoord()->x == coordB->x && ship->getCoord()->y == coordB->y) {
        for (auto it = table->getMembers().begin(); it < table->getMembers().end(); it++)
            if (*it == ship)
                table->getMembers().erase(it);
    }
    else if (ship->getCoord()->x <= coordB->x && ship->getCoord()->y <= coordB->y) {
        if (ship->getCoord()->x == coordB->x)
            if (coordB->y - ship->getCoord()->y < ship->getSpeedName())
                ship->setPoint(ship->getCoord()->x, coordB->y);
            else ship->setPoint(ship->getCoord()->x, ship->getCoord()->y + ship->getSpeedName());
        else if ((ship->getCoord()->y == coordB->y) || (ship->getCoord()->x < coordB->x && ship->getCoord()->y < coordB->y))
            ship->setPoint(ship->getCoord()->x + ship->getSpeedName(), ship->getCoord()->y);
    }
    else if (ship->getCoord()->x <= coordB->x && ship->getCoord()->y >= coordB->y) {
        if (ship->getCoord()->x == coordB->x)
            if (ship->getCoord()->y - coordB->y < ship->getSpeedName())
                ship->setPoint(ship->getCoord()->x, coordB->y);
            else ship->setPoint(ship->getCoord()->x, ship->getCoord()->y - ship->getSpeedName());
        else if ((ship->getCoord()->y == coordB->y) || (ship->getCoord()->x < coordB->x && ship->getCoord()->y > coordB->y))
            ship->setPoint(ship->getCoord()->x + ship->getSpeedName(), ship->getCoord()->y);
    }
    else if (ship->getCoord()->x >= coordB->x && ship->getCoord()->y <= coordB->y) {
        if (ship->getCoord()->x == coordB->x)
            if (ship->getCoord()->x == coordB->x)
                if (coordB->y - ship->getCoord()->y < ship->getSpeedName())
                    ship->setPoint(ship->getCoord()->x, coordB->y);
                else ship->setPoint(ship->getCoord()->x, ship->getCoord()->y + ship->getSpeedName());
            else if ((ship->getCoord()->y == coordB->y) || (ship->getCoord()->x > coordB->x && ship->getCoord()->y < coordB->y))
                ship->setPoint(ship->getCoord()->x - ship->getSpeedName(), ship->getCoord()->y);
    }
    else if (ship->getCoord()->x >= coordB->x && ship->getCoord()->y >= coordB->y) {
        if (ship->getCoord()->x == coordB->x)
            if (ship->getCoord()->y - coordB->y < ship->getSpeedName())
                ship->setPoint(ship->getCoord()->x, coordB->y);
            else  ship->setPoint(ship->getCoord()->x, ship->getCoord()->y - ship->getSpeedName());
        else if ((ship->getCoord()->y == coordB->y) || (ship->getCoord()->x > coordB->x && ship->getCoord()->y > coordB->y))
            ship->setPoint(ship->getCoord()->x - ship->getSpeedName(), ship->getCoord()->y);
    }
    if (ship->getCoord()->x == coordB->x && ship->getCoord()->y == coordB->y) {
        for (auto it = table->getMembers().begin(); it < table->getMembers().end(); it++)
            if (*it == ship)
                table->getMembers().erase(it);
    }
}

string Mission::show(Table* table) {
     return (*table).show();
}

Ship* Mission::findShip(Table* table, string cpt) {
    return  (*table).findTypeArm(cpt);
}

Mission Mission::loadGame() {
    Mission* resOfLoad = new Mission();

    Cruiser* c = new Cruiser();
    Aerocarrier* aero = new Aerocarrier();
    AircraftCruiser* air = new AircraftCruiser();

    string way;
    way = way + "C:\\Users\\yul20\\Desktop\\labs\\3sem\\lab4\\src\\log.txt";
    ifstream src;

    src.exceptions(ifstream::failbit);
    src.open(way, ios_base::in);

    try {
        src.is_open();
    }
    catch (ofstream::failure& ex) {
        cout << ex.code() << endl;
        cout << "File error open" << endl;
    }

    string s;

    src >> moneyA;
    src >> moneyB;
    src >> fieldX;
    src >> fieldY;
    src >> coordA->x;
    src >> coordA->y;
    src >> radOfBaseA;
    src >> coordB->x;
    src >> coordB->y;
    src >> radOfBaseB;

    src >> s;
    src >> s;

    Ship* ship = new Ship();
    while (s != "B") {
    }


    return *resOfLoad;
}

void Mission::saveGame(int fieldX, int fieldY, Point* coordA, Point* coordB, int radOfBaseA, int radOfBaseB) {

    Cruiser* c = new Cruiser();
    Aerocarrier* aero = new Aerocarrier();
    AircraftCruiser* air = new AircraftCruiser();

    string way;
    way = way + "C:\\Users\\yul20\\Desktop\\labs\\3sem\\lab4\\src\\log.txt";
    ofstream src;

    src.exceptions(ifstream::failbit);
    src.open(way, ios_base::out);

    try {
        src.is_open();
    }
    catch (ofstream::failure& ex) {
        cout << ex.code() << endl;
        cout << "File error open" << endl;
    }

    stringstream s;

    src << moneyA << endl;
    src << moneyB << endl;
    src << fieldX << endl << fieldY << endl;
    src << coordA->x << endl << coordA->y << endl;
    src << radOfBaseA << endl;
    src << coordB->x << endl << coordB->y << endl;
    src << radOfBaseB << endl;

    src << "A" << endl;
    for (int i = 0; i < A->getMembers().size(); i++) {
        src << A->getMembers().at(i)->getWay()->x << endl;
        src << A->getMembers().at(i)->getWay()->y << endl;
        src << A->getMembers().at(i)->getSurvival() << endl;
        src << A->getMembers().at(i)->getCoord()->x << endl;
        src << A->getMembers().at(i)->getCoord()->y << endl;
        src << A->getMembers().at(i)->getType() << endl;
        src << A->getMembers().at(i)->getShipName() << endl;
        src << A->getMembers().at(i)->getCaptain() << endl;
        src << A->getMembers().at(i)->getSpeedName()<< endl;
        src << A->getMembers().at(i)->getPrice() << endl;

        if (A->getMembers().at(i)->getType() == 1) {
            c = dynamic_cast<Cruiser*>(A->getMembers().at(i));
            for (auto it : c->getInfoArmament()) {
                src << (*it).getName() << endl;
                src << (*it).getType() << endl;
                src << (*it).getMaxReserve() << endl;
                src << (*it).getNowReserve() << endl;
                src << (*it).getNameAmmo() << endl;
                src << (*it).getPrice() << endl;
                src << (*it).getActive() << endl;
                src << (*it).getLoss() << endl;
                src << (*it).getDist() << endl;
                src << (*it).getRate() << endl;
                src << (*it).getReloadSpeed() << endl;
            }

            src << c->getCnt() << endl;
            src << c->getSize() << endl;

            for (auto it : c->getInfoReserve()) {
                src << (*it).cnt << endl;
                src << (*it).name << endl;
                src << (*it).price << endl;
                src << (*it).size << endl;
            }

        }
        else if (A->getMembers().at(i)->getType() == 2) {
            aero = dynamic_cast<Aerocarrier*>(A->getMembers().at(i));
            for (auto it : aero->getVecPlane()) {
                src << (*it).getType() << endl;
                src << (*it).getLoss() << endl;
                src << (*it).getActive() << endl;
                src << (*it).getSurvival() << endl;
                src << (*it).getSpeed() << endl;
                src << (*it).getFuelAll() << endl;
                src << (*it).getFuelLoss() << endl;
                src << (*it).getSpeedEquipment() << endl;
                src << (*it).getPrice() << endl;
            }
            src << aero->getMaxPlane() << endl;
        }
        else if (A->getMembers().at(i)->getType() == 3) {
            air = dynamic_cast<AircraftCruiser*>(A->getMembers().at(i));

            src << air->getMaxCntArma() << endl; //вооружение
            for (auto it : c->getInfoArmament()) {
                src << (*it).getName() << endl;
                src << (*it).getType() << endl;
                src << (*it).getMaxReserve() << endl;
                src << (*it).getNowReserve() << endl;
                src << (*it).getNameAmmo() << endl;
                src << (*it).getPrice() << endl;
                src << (*it).getActive() << endl;
                src << (*it).getLoss() << endl;
                src << (*it).getDist() << endl;
                src << (*it).getRate() << endl;
                src << (*it).getReloadSpeed() << endl;
            }

            src << air->getSize() << endl; //склад
            for (auto it : c->getInfoReserve()) {
                src << (*it).cnt << endl;
                src << (*it).name << endl;
                src << (*it).price << endl;
                src << (*it).size << endl;
            }

            src << air->getMaxCntPlane() << endl;
            for (auto it : aero->getVecPlane()) {
                src << (*it).getType() << endl;
                src << (*it).getLoss() << endl;
                src << (*it).getActive() << endl;
                src << (*it).getSurvival() << endl;
                src << (*it).getSpeed() << endl;
                src << (*it).getFuelAll() << endl;
                src << (*it).getFuelLoss() << endl;
                src << (*it).getSpeedEquipment() << endl;
                src << (*it).getPrice() << endl;
            }
        }
    }

        src << "B" << endl;
        for (int i = 0; i < B->getMembers().size(); i++) {
            src << B->getMembers().at(i)->getWay()->x << endl;
            src << B->getMembers().at(i)->getWay()->y << endl;
            src << B->getMembers().at(i)->getSurvival() << endl;
            src << B->getMembers().at(i)->getCoord()->x << endl;
            src << B->getMembers().at(i)->getCoord()->y << endl;
            src << B->getMembers().at(i)->getType() << endl;
            src << B->getMembers().at(i)->getShipName() << endl;
            src << B->getMembers().at(i)->getCaptain()->name << endl;
            src << B->getMembers().at(i)->getSpeedName() << endl;
            src << B->getMembers().at(i)->getPrice() << endl;

            if (B->getMembers().at(i)->getType() == 1) {
                c = dynamic_cast<Cruiser*>(B->getMembers().at(i));
                for (auto it : c->getInfoArmament()) {
                    src << (*it).getName() << endl;
                    src << (*it).getType() << endl;
                    src << (*it).getMaxReserve() << endl;
                    src << (*it).getNowReserve() << endl;
                    src << (*it).getNameAmmo() << endl;
                    src << (*it).getPrice() << endl;
                    src << (*it).getActive() << endl;
                    src << (*it).getLoss() << endl;
                    src << (*it).getDist() << endl;
                    src << (*it).getRate() << endl;
                    src << (*it).getReloadSpeed() << endl;
                }

                src << c->getCnt() << endl;
                src << c->getSize() << endl;

                for (auto it : c->getInfoReserve()) {
                    src << (*it).cnt << endl;
                    src << (*it).name << endl;
                    src << (*it).price << endl;
                    src << (*it).size << endl;
                }

            }
            else if (B->getMembers().at(i)->getType() == 2) {
                aero = dynamic_cast<Aerocarrier*>(A->getMembers().at(i));
                for (auto it : aero->getVecPlane()) {
                    src << (*it).getType() << endl;
                    src << (*it).getLoss() << endl;
                    src << (*it).getActive() << endl;
                    src << (*it).getSurvival() << endl;
                    src << (*it).getSpeed() << endl;
                    src << (*it).getFuelAll() << endl;
                    src << (*it).getFuelLoss() << endl;
                    src << (*it).getSpeedEquipment() << endl;
                    src << (*it).getPrice() << endl;
                }
                src << aero->getMaxPlane() << endl;
            }
            else if (B->getMembers().at(i)->getType() == 3) {
                air = dynamic_cast<AircraftCruiser*>(A->getMembers().at(i));

                src << air->getMaxCntArma() << endl; //вооружение
                for (auto it : c->getInfoArmament()) {
                    src << (*it).getName() << endl;
                    src << (*it).getType() << endl;
                    //src << (*it).getMaxReserve() << endl;
                    //src << (*it).getNowReserve() << endl;
                    src << (*it).getNameAmmo() << endl;
                    src << (*it).getPrice() << endl;
                    src << (*it).getActive() << endl;
                    src << (*it).getLoss() << endl;
                    src << (*it).getDist() << endl;
                    src << (*it).getRate() << endl;
                    src << (*it).getReloadSpeed() << endl;
                }

                src << air->getSize() << endl; //склад
                for (auto it : c->getInfoReserve()) {
                    src << (*it).cnt << endl;
                    src << (*it).name << endl;
                    src << (*it).price << endl;
                    src << (*it).size << endl;
                }

                src << air->getMaxCntPlane() << endl;
                for (auto it : aero->getVecPlane()) {
                    src << (*it).getType() << endl;
                    src << (*it).getLoss() << endl;
                    src << (*it).getActive() << endl;
                    src << (*it).getSurvival() << endl;
                    src << (*it).getSpeed() << endl;
                    src << (*it).getFuelAll() << endl;
                    src << (*it).getFuelLoss() << endl;
                    src << (*it).getSpeedEquipment() << endl;
                    src << (*it).getPrice() << endl;
                }
            }

        }

        src.close();
}
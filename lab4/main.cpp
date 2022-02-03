#include "Mission.h"



int main() {
    /*bools*/
    bool flag = true;
    bool f = false;

    /*ints*/
    int fl1 = 1;
    int fl2 = 1;
    int c;
    int help;
    int help2;
    int help3;
    int money1;
    int money2;
    int speed;
    int m;
    int n;

    /*strings*/
    string name;
    string name1;
    string name2;
    string name3;
    string field_help;
    

    /*Others*/
    Point* point;
    Point* coordA = new Point();
    Point* coordB = new Point();

    Armament* armament = new Armament();
    Reserve* reserve;
    Cruiser* cruiser;
    AircraftCruiser* aircraft;
    Aerocarrier* aerocar;
    Ship* ship;
    Ship* ship1;
    Ship* ship2;
    Captain* captain = new Captain();
    Ship* shipFrom;
    Table table;
    Mission mission = Mission();
    mvector<string>listOfHeavyArmament;
    listOfHeavyArmament.push_back("AK-130");
    listOfHeavyArmament.push_back("A-190");
    listOfHeavyArmament.push_back("AK-176");

    vector<string>listOfLightArmament = { "BB-150L", "OS-210L", "OF-270L" };

    vector<string>listOfAmmo = { "BB-200", "OS-260", "OF-310" };

    cout << "Hello to the BattleWarShip Game!" << endl;
    cout << "Would u like to continue previous game or start new?" << endl;
    cout << "1. New game" << endl;
    cout << "2. Previous game" << endl;
    cin >> help;

    if (help == 2) {
        mission.loadGame();
        goto L;
    }
    else {
        goto M;
    }

M: {
    cout << "Enter the sum of ally money: ";
    cin >> money1;
    cout << "Enter the sum of enemy money: ";
    cin >> money2;

    mission.setMoney(money1, money2);

    cout << "Enter the coord of battle field:\nx: ";
    cin >> mission.fieldX;
    cout << "y: ";
    cin >> mission.fieldY;

    cout << "Enter the coords of base A:\nx: ";
    cin >> mission.coordA->x;
    cout << "y: ";
    cin >> mission.coordA->y;

    cout << "Enter the radius of base A: " << endl;
    cin >> mission.radOfBaseA;

    cout << "Enter the coords of base B:\nx: ";
    cin >> mission.coordB->x;
    cout << "y: ";
    cin >> mission.coordB->y;

    cout << "Enter the radius of base B: " << endl;
    cin >> mission.radOfBaseB;

    L: {
        while (fl1) {
            cout << "\n**************************" << endl;
            cout << "* 0. Exit                *" << endl;
            cout << "* 1. BuyShip             *" << endl;
            cout << "* 2. SellShip            *" << endl;
            cout << "* 3. BuyPlane            *" << endl;
            cout << "* 4. SellPlane           *" << endl;
            cout << "* 5. TransferPlane       *" << endl;
            cout << "* 6. BuyArmament         *" << endl; //оружие
            cout << "* 7. SellArmament        *" << endl;
            cout << "* 8. BuyAmmo             *" << endl; //армамент
            cout << "* 9. SellAmmo            *" << endl;
            cout << "* 10. KillShip           *" << endl;
            cout << "* 11. EnemyReach         *" << endl;
            cout << "* 12. Show field         *" << endl;
            cout << "* 13. ShowTable          *" << endl;
            cout << "* 14. Save Game          *" << endl;
            cout << "**************************\n" << endl;

            cin >> c;
            if (!cin.good() || c < 0 || c > 14) {

                cin.clear();

                cin.ignore(INT_MAX, '\n');

                cout << "Incorrect input!" << std::endl;
            }

            if (c == 0)
                fl1 = 0;
            else
                switch (c)
                {
                case 1:
                    cout << "What table do u want buy ship from?" << endl;
                    cout << "1. A" << endl;
                    cout << "2. B" << endl;
                    cin >> help2;

                    cout << "What type of ship u want to buy?" << endl;
                    cout << "1. Cruiser" << endl;
                    cout << "2. AeroCarrier" << endl;
                    cout << "3. AircraftCruiser" << endl;

                    cin >> help;
                    if (help == 1) {
                        point = new Point();
                        captain = new Captain();
                        cout << "Name of captain: ";
                        cin >> captain->name;
                        cout << "Coordinats:\nx:";
                        cin >> point->x;
                        cout << "y:";
                        cin >> point->y;
                        cout << "Name of ship: ";
                        cin >> name2;
                        cout << "What speed : ";
                        cin >> speed;
                        cruiser = new Cruiser(captain, name2, speed, 100, 3, 10, point, 0, 1000);
                        mission.buyShip(help2 == 1 ? mission.A : mission.B, cruiser);
                    }
                    else if (help == 2) {
                        point = new Point();
                        captain = new Captain();
                        cout << "Name of captain: ";
                        cin >> captain->name;
                        cout << "Coordinats:\nx:";
                        cin >> point->x;
                        cout << "y:";
                        cin >> point->y;
                        cout << "Name of ship: ";
                        cin >> name2;
                        cout << "What speed : ";
                        cin >> speed;
                        aerocar = new Aerocarrier(captain, point, 100, 2, name2, 1, 7, 3000);
                        mission.buyShip(help2 == 1 ? mission.A : mission.B, aerocar);
                    }
                    else if (help == 3) {
                        point = new Point();
                        captain = new Captain();
                        cout << "Name of captain: ";
                        cin >> captain->name;
                        cout << "Coordinats:\nx:";
                        cin >> point->x;
                        cout << "y:";
                        cin >> point->y;
                        cout << "Name of ship: ";
                        cin >> name2;
                        cout << "What speed : ";
                        cin >> speed;
                        aircraft = new AircraftCruiser(captain, name2, speed, 200, 7, 20, point, 3, 3000);
                        mission.buyShip(help2 == 1 ? mission.A : mission.B, aircraft);
                    }
                    break;
                case 2:
                    cout << "What table do u want sell ship from?" << endl;
                    cout << "1. A" << endl;
                    cout << "2. B" << endl;
                    cin >> help;

                    cout << "What name of ship`s captain name is?" << endl;
                    cin >> name;

                    mission.sellShip(help == 1 ? mission.A : mission.B, name);

                    break;
                case 3:
                    cout << "What table` ship do u want to buy ship to?" << endl;
                    cout << "1. A" << endl;
                    cout << "2. B" << endl;
                    cin >> help2;

                    if (help2)
                        cout << mission.show(mission.A) << endl;
                    else
                        cout << mission.show(mission.B) << endl;

                    cin >> name;

                    cout << "What is the type of plane u want to buy?" << endl;
                    cout << "1. destroyer" << endl;     //истрибитель
                    cout << "2. stormtrooper" << endl;  //бомбордировщик
                    cin >> help;

                    Plane* plane;
                    if (help)
                        plane = new Plane(destroyer, 0.5, 50, 1, 70); 
                    else
                        plane = new Plane(stormtrooper, 0.3, 60, 1, 100);

                    mission.buyPlane(help2 == 1 ? mission.A : mission.B, name, plane);

                    break;
                case 4:
                    cout << "Which base of the ship?" << endl;
                    cout << "1. A" << endl;
                    cout << "2. B" << endl;
                    cin >> help2;

                    if (help2 == 1) {
                        cout << mission.show(mission.A) << endl;
                        cout << "Enter the captain`s name" << endl;
                        cin >> name;
                        shipFrom = mission.findShip(mission.A, name);
                    }
                    else {
                        cout << mission.show(mission.B) << endl;
                        cout << "Enter the captain`s name" << endl;
                        cin >> name;
                        shipFrom = mission.findShip(mission.B, name);
                    }

                    aircraft = dynamic_cast<AircraftCruiser*>(shipFrom);
                    if (!aircraft) {
                        aerocar = dynamic_cast<Aerocarrier*>(shipFrom);
                        cout << aerocar->getInfoPlane() << endl;

                        cout << "What plane? (pls, choose number)" << endl;
                        cin >> help;
                        if (help2)
                            mission.sellPlane(mission.A, name, aerocar->getPlane(help)); 
                        else
                            mission.sellPlane(mission.B, name, aerocar->getPlane(help)); 
                    }
                    else {
                        cout << aircraft->getInfoPlane() << endl;

                        cout << "What plane? (pls, choose number)" << endl;
                        cin >> help;
                        if (help2)
                            mission.sellPlane(mission.A, name, aircraft->getPlane(help)); 
                        else
                            mission.sellPlane(mission.B, name, aircraft->getPlane(help)); 

                    }

                    
                    aerocar = dynamic_cast<Aerocarrier*>(shipFrom);
                    if (aerocar) {
                        cout << aerocar->getInfoPlane() << endl;
                    } 
                    break;
                case 5:
                {
                    cout << "What table` plane do u want to transfer plane?" << endl;
                    cout << "1. A" << endl;
                    cout << "2. B" << endl;
                    cin >> help2;

                    cout << mission.show(help2 == 1 ? mission.A : mission.B) << endl;

                    cout << "\nWhat ship from?" << endl;
                    cin >> name;

                    Ship* shipFrom = mission.findShip(help2 == 1 ? mission.A : mission.B, name);


                    cout << "\nWhat ship to?" << endl;
                    cin >> name;

                    Ship* shipTo = mission.findShip(help2 == 1 ? mission.A : mission.B, name);


                    cout << "What plane do u want to transfer?" << endl;

                    AircraftCruiser* aircraft = dynamic_cast<AircraftCruiser*>(shipFrom);
                    Aerocarrier* aerocar;
                    if (!aircraft) {
                        aerocar = dynamic_cast<Aerocarrier*>(shipFrom);
                        cout << aerocar->getInfoPlane() << endl;

                        cout << "What plane? (pls, choose number)" << endl;
                        cin >> help;
                        mission.transferPlane(help2 == 1 ? mission.A : mission.B, shipFrom, shipTo, aerocar->getPlane(help)); 

                    }
                    else {
                        cout << aircraft->getInfoPlane() << endl;

                        cin >> help;

                        cout << "What plane? (pls, choose number)" << endl;
                        cin >> help;
                        mission.transferPlane(help2 == 1 ? mission.A : mission.B, shipFrom, shipTo, aircraft->getPlane(help)); 
                    }

                    break;
                }
                case 6:
                    cout << "In what table do u want to buy armament?" << endl;
                    cout << "1. A" << endl;
                    cout << "2. B" << endl;
                    cin >> help;

                    cout << "What name of ship`s captain name is?" << endl;
                    if (help) {
                        cout << mission.show(mission.A);
                    }
                    else {
                        cout << mission.show(mission.B);
                    }
                    cin >> name;

                    cout << "What type of armament do u want to buy?" << endl;
                    cout << "1. light" << endl;
                    cout << "2. heavy" << endl;
                    cin >> help2;

                    if (help2 == 1) {
                        for (int i = 0; i < listOfLightArmament.size(); i++)
                            cout << i << ". " << listOfLightArmament.at(i) << endl;
                        cin >> help3;
                        if (help == 1)
                            mission.buyArmament(mission.A, name, new Armament(listOfLightArmament[help3], light));
                        else
                            mission.buyArmament(mission.B, name, new Armament(listOfLightArmament[help3], light));

                    }
                    else {
                        for (int i = 0; i < listOfHeavyArmament.size(); i++)
                            cout << i << ". " << listOfHeavyArmament[i] << endl;
                        cin >> help3;
                        if (help == 1)
                            mission.buyArmament(mission.A, name, new Armament(listOfHeavyArmament[help3], heavy));
                        else
                            mission.buyArmament(mission.B, name, new Armament(listOfHeavyArmament[help3], heavy));

                    }
                    break;
                case 7:
                    cout << "In what table do u want to sell Armament of ship?" << endl;
                    cout << "1. A" << endl;
                    cout << "2. B" << endl;
                    cin >> help;

                    cout << "What name of ship`s captain name is?" << endl;
                    if (help) {
                        cout << mission.show(mission.A);
                    }
                    else {
                        cout << mission.show(mission.B);
                    }
                    cin >> name;

                    cout << "What armament to sell?" << endl;

                    ship = mission.findShip(help == 1 ? mission.A : mission.B, name);
                    if (ship->getType() == 3) {
                        AircraftCruiser* aircraft = dynamic_cast<AircraftCruiser*>(ship);
                        cout << "Num.\tName\tActive\tLoss" << endl;
                        for (int i = 0; i < aircraft->getInfoArmament().size(); i++) {
                            cout << i << ". " << aircraft->getInfoArmament().at(i)->getName()
                                << "\t" << aircraft->getInfoArmament().at(i)->getActive()
                                << "\t" << aircraft->getInfoArmament().at(i)->getLoss() << endl;
                        }
                        cin >> help3;
                        armament = aircraft->getInfoArmament().at(help3);
                    }
                    else if (ship->getType() == 1) {
                        cruiser = dynamic_cast<Cruiser*>(ship);
                        cout << "Num.\tName\tActive\tLoss" << endl;
                        for (int i = 0; i < cruiser->getInfoArmament().size(); i++) {
                            cout << i << ". " << cruiser->getInfoArmament().at(i)->getName()
                                << "\t" << cruiser->getInfoArmament().at(i)->getActive()
                                << "\t" << cruiser->getInfoArmament().at(i)->getLoss() << endl;
                        }
                        cin >> help3;
                        armament = cruiser->getInfoArmament().at(help3);
                    }

                    mission.sellArmament(help == 1 ? mission.A : mission.B, name, armament);

                    break;
                case 8:
                    cout << "What table?" << endl;
                    cout << "1. A" << endl;
                    cout << "2. B" << endl;
                    cin >> help2;

                    if (help2)
                        cout << mission.show(mission.A) << endl;
                    else
                        cout << mission.show(mission.B) << endl;

                    cout << "\nWhat ship?" << endl;
                    cin >> name;

                    cout << "Which one of ammo u want to buy?\nEnter the number" << endl;
                    for (int i = 0; i < listOfAmmo.size(); i++)
                        cout << i << ". " << listOfAmmo.at(i) << endl;
                    cin >> help;

                    reserve = new Reserve(listOfAmmo.at(help));

                    if (help2)
                        mission.buyAmmo(mission.A, name, reserve);
                    else
                        mission.buyAmmo(mission.B, name, reserve);
                    break;
                case 9:
                    cout << "What table?" << endl;
                    cout << "1. A" << endl;
                    cout << "2. B" << endl;
                    cin >> help2;

                    if (help2)
                        cout << mission.show(mission.A) << endl;
                    else
                        cout << mission.show(mission.B) << endl;

                    cout << "\nWhat ship?" << endl;
                    cin >> name;

                    cout << "Which one of ammo u want to sell?\nEnter the number" << endl;

                    if (help2 == 1) {
                        ship = mission.findShip(mission.A, name);
                        Cruiser* cruiser = dynamic_cast<Cruiser*>(ship);
                        if (!cruiser) {
                            AircraftCruiser* aircraft = dynamic_cast<AircraftCruiser*>(ship);
                            for (int i = 0; i < aircraft->getInfoReserve().size(); i++)
                                cout << aircraft->getInfoReserve().at(i)->name << endl;
                            cin >> help;
                            mission.sellAmmo(mission.A, name, cruiser->getInfoReserve().at(help));
                        }
                        else {
                            for (int i = 0; i < cruiser->getInfoReserve().size(); i++)
                                cout << i << ". " << cruiser->getInfoReserve().at(i)->name << endl;
                            cin >> help;
                            mission.sellAmmo(mission.A, name, cruiser->getInfoReserve().at(help));
                        }
                    }
                    else {
                        ship = mission.findShip(mission.B, name);
                        Cruiser* cruiser = dynamic_cast<Cruiser*>(ship);
                        if (!cruiser) {
                            AircraftCruiser* aircraft = dynamic_cast<AircraftCruiser*>(ship);
                            for (int i = 0; i < aircraft->getInfoReserve().size(); i++)
                                cout << aircraft->getInfoReserve().at(i) << endl;
                            cin >> help;
                            mission.sellAmmo(mission.B, name, cruiser->getInfoReserve().at(help));
                        }
                        else {
                            for (int i = 0; i < cruiser->getInfoReserve().size(); i++)
                                cout << cruiser->getInfoReserve().at(i) << endl;
                            cin >> help;
                            mission.sellAmmo(mission.B, name, cruiser->getInfoReserve().at(help));
                        }

                    }
                    break;
                case 10:
                    goto P;
                    break;
                case 12:
                    field_help = "";
                    for (int i = 0; i < mission.fieldY; i++) {
                        for (int j = 0; j < mission.fieldX; j++) {
                            ship1 = new Ship();
                            ship2 = new Ship();
                            m = 0;
                            n = 0;
                            f = false;//false - такого нет на этой координате, true - такое есть и зафиксировали 
                            if (mission.coordA->x == j && mission.coordA->y == i)
                                field_help += "<";
                            else if (mission.coordB->x == j && mission.coordB->y == i)
                                field_help += ">";
                            else do {
                                ship1 = mission.A->getMembers().at(m);
                                ship2 = mission.B->getMembers().at(n);
                                if (ship1->getCoord()->x == j && ship1->getCoord()->y == i) {
                                    if (ship1->getType() == 1) //Cruiser
                                        field_help += "A";

                                    if (ship1->getType() == 2) //AeroCarrier
                                        field_help += "B";
                                    
                                    if (ship1->getType() == 3) //AirCraft
                                        field_help += "C";
                                    f = !f;
                                    break;
                                }
                                else if (ship2->getCoord()->x == j && ship2->getCoord()->y == i) {
                                    if (ship2->getType() == 1) //Cruiser
                                        field_help += "a";

                                    if (ship2->getType() == 2) //AeroCarrier
                                        field_help += "b";

                                    if (ship2->getType() == 3) //AirCraft
                                        field_help += "c";
                                    f = !f; 
                                    break;
                                }
                                if (m < mission.A->getMembers().size())
                                    m++;
                                if (n < mission.B->getMembers().size())
                                    n++;
                            } while (f || ( m < mission.A->getMembers().size()  && n < mission.B->getMembers().size() ));
                            if (!f);
                            field_help += ".";
                        }
                        field_help += "\n";
                    }
                    cout << field_help << endl;
                    break;
                case 13:
                    cout << "\nWhat table to show?" << endl;
                    cout << "1. A" << endl;
                    cout << "2. B" << endl;
                    cin >> help;
                    if (help == 1)
                        cout << mission.show(mission.A) << endl;
                    else
                        cout << mission.show(mission.B) << endl;
                    break;
                case 14:
                    mission.saveGame(mission.fieldX, mission.fieldY, coordA, coordB, mission.radOfBaseA, mission.radOfBaseB);
                    break;
                default:
                    break;
                }


        }
    }
        P: {
        cout << "\n\n\n\n" << endl;
        while (fl2) {
            cout << "\n*******************" << endl;
            cout << "* 0. End game     *" << endl;
            cout << "* 1. Attack ship  *" << endl;
            cout << "* 2. Show Table   *" << endl;
            cout << "*******************" << endl;

            cin >> c;
            if (!cin.good() || c < 0 || c > 3) {

                cin.clear();

                cin.ignore(INT_MAX, '\n');

                cout << "Incorrect input!" << std::endl;
            }

            if (c == 0) {
                fl2 = 0;
                cout << "Save Game?" << endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                cin >> c;
                if (c == 1)
                    mission.saveGame(mission.fieldX, mission.fieldY, coordA, coordB, mission.radOfBaseA, mission.radOfBaseB);
                cout << "See u soon, Bye!" << endl;
            }
            else
                switch (c)
                {
                case 1:
                    cout << "What table of attackers?" << endl;
                    cout << "1. A" << endl;
                    cout << "2. B" << endl;
                    cin >> help2;

                    cout << mission.show(help2 == 1 ? mission.B : mission.A) << endl;

                    cout << "What wiil ship be attacked?" << endl;
                    cin >> name;

                    cout << "What type of attack will be?" << endl;
                    cout << "0. By armament" << endl;
                    cout << "1. By planes" << endl;

                    cin >> help;

                    if (help2 == 1)
                        ship = mission.B->findTypeArm(name);
                    else
                        ship = mission.A->findTypeArm(name);

                    mission.killShip(help2 == 1 ? mission.A : mission.B, help2 == 1 ? mission.B : mission.A, ship, help);
                    for (auto it = mission.B->getMembers().begin(); it < mission.B->getMembers().end(); it++) {
                        mission.enemyReach(mission.B, *it);
                    }
                    break;
                case 2:
                    cout << "\nWhat table to show?" << endl;
                    cout << "1. A" << endl;
                    cout << "2. B" << endl;
                    cin >> help;
                    if (help == 1)
                        cout << mission.show(mission.A) << endl;
                    else
                        cout << mission.show(mission.B) << endl;
                    break;
                default:
                    break;

                }
        }


        }
    }
    return 0;
}
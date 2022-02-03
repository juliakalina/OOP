#ifndef MISSION_H_
#define MISSION_H_

#include "LINK.h"

using namespace ArmyBase;

class Mission{
private:
    string comand;
    int maxA;
    int maxB;
    int moneyA;
    int moneyB;
    int wastedMoney;
    int lossA;
    int lossB;
    int maxLoss;
    int safePrice = moneyB - lossB;
    Point baseA;
    Point baseB;
public:
    Table* A;
    Table* B;
    Point* coordA = new Point();
    Point* coordB = new Point();
    int fieldX;
    int fieldY;
    int radOfBaseA;
    int radOfBaseB;

    /*Constructures*/
    Mission();
    Mission(int, int);

    ~Mission() { delete A; delete B; };

    /*Setters*/
    Mission& setTable(Table* table, int money, int loss);
    Mission& setMoney(int mA, int mB) {
        moneyA = mA;
        moneyB = mB;
        return *this;
    }

    /*Getters*/
    int getMoneyA() { return moneyA; };
    int getMoneyB() { return moneyB; };

    /*Othes*/
    void buyShip(Table* table, Ship* ship);
    void sellShip(Table* table, string capt);

    void buyPlane(Table* table, string name, Plane* plane);
    void sellPlane(Table* table, string name, Plane* plane);

    void transferPlane(Table* table, Ship* old, Ship* nov, Plane* plane);

    void buyArmament(Table* table, string cpt, Armament* arm);
    void sellArmament(Table* table, string cpt, Armament* arm);

    void buyAmmo(Table* table, string cpt, Reserve* reserve);
    void sellAmmo(Table* table, string cpt, Reserve* reserve);

    bool killShip(Table* ours, Table* enemy, Ship* ship, int atackType);    
    void enemyReach(Table* table, Ship* ship);    
    
    string show(Table*);

    Ship* findShip(Table*, string cpt);
    
    Mission loadGame();
    void saveGame(int fieldX, int fieldY, Point* coordA,
        Point* coordB, int radOfBaseA, int radOfBaseB);
};
#endif
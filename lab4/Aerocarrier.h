#ifndef AEROCARRIER_H_
#define AEROCARRIER_H_

namespace ArmyBase {

    class Aerocarrier :  virtual public Ship {
    protected:
        std::vector<Plane*> planeInfo;
        int maxPlane;
    public:
        Aerocarrier();
        Aerocarrier(string);
        Aerocarrier(Captain* newCaptain, Point* newPoint, int newPrice, int newType, string newShipName, double newSpeed, int maxCnt, int survival);

        ~Aerocarrier() { planeInfo.clear(); };

        int getSumPrice() override;
        Plane* getPlane(int index) { return planeInfo.at(index); };
        std::vector<Plane*>& getVecPlane() { return planeInfo; };
        string getInfoPlane();
        int getMaxPlane() { return maxPlane; };
        

        virtual void setPlane(Plane* plane);
        void setInfoPlane(PlaneType kind, bool act, double sped, int survival, int fLoss, int cnt);
        Aerocarrier& setMaxPlane(int max);
        
        
        bool damageShip(std::vector<Ship*>, Point*);//сколько самолетов пало 
        bool damagePlane(std::vector<Plane*>, Point*); //сколько кораблей пало 
        double culc(Point* a, Point* b) { return sqrt(pow(b->x - a->x,2) + pow(b->y - a->y,2)); }
        void delPlane(Plane*);

    };

}

#endif
#ifndef TABLE_H_
#define TABLE_H_

namespace ArmyBase {

    class Table {
    private:
        vector<Ship*> table; //string shipName
    public:
        ~Table() { table.clear(); };

        Ship* findTypeArm(string);
        Table& add(Ship*);
        vector<Ship*>& getMembers() { return table; };

        Table& del(string capt);
        string show();
    };
}
#endif
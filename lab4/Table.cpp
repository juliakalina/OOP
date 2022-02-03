#include "LINK.h"

namespace ArmyBase {

    Ship* Table::findTypeArm(string cpt) {
        for (int i = 0; i != table.size(); i++) {
            if (cpt == table[i]->getCaptain()->name)
                return table[i];
        }
        return nullptr;
    }

    Table& Table::add(Ship* ship) {
        table.push_back(ship);
        return *this;
    }

    Table& Table::del(string cpt) {
        for (auto it = table.begin(); it != table.end(); it++) 
            if (cpt == (*it)->getCaptain()->name) {
                table.erase(it);
                return *this;
            }
        return *this;
    }

    string Table::show() {
        string str;

        for (int i = 0; i < table.size(); i++) {
            str = str + char(i + 48) + ".  Ship`s Cap: " + table.at(i)->getCaptain()->name + " Type: " + char(table.at(i)->getType() + 48) + "\n";
        }

        return str;
    }
} 
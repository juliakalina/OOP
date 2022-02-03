#ifndef LINK_H_
#define LINK_H_

#include <iostream>
#include <vector>
//#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
//#include <map>
#include "Vector.h"

using namespace std;
using std::string;

namespace ArmyBase {
	enum PlaneType {
		destroyer, stormtrooper
	};

	class Ship;
	class Cruiser;
	class Armament; 
	class Aerocarrier;
	class AircraftCruiser;
	class Plane;
}
#include "Ship.h"

#include "Cruiser.h" 
#include "Aerocarrier.h"
#include "AircraftCruiser.h"

#include "Armament.h"
#include "Plane.h"

#include "Table.h"
#include "Mission.h"

#endif
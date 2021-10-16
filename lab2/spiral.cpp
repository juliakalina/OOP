#include<iostream>
#include "spiral.h"

namespace Prog2 {

	Spiral::Spiral() {
		k = 0;
		f = 0;
	}

	Spiral& Spiral::setK(double k0)
	{
		if (k0 < 0) {
			throw std::exception("invalid value");
		}
		k = k0;
		return *this;
	}

	Spiral& Spiral::setF(double f0)
	{
		if (f0 < 0) {
			throw std::exception("invalid value");
		}
		f = f0;
		return *this;
	}

}
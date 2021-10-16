#ifndef _SPIRAL_H_
#define _SPIRAL_H_

#include <math.h>

#define M_PI 3.14159

namespace Prog2 {

	class Spiral
	{
	private:
		double k; // смещение точки по лучу r при повороте на угол, равный одному радиану.
		double f; //угол
	public:

		Spiral();
		
		Spiral& setK(double k0);
		Spiral& setF(double f0);

		double getK() const { return k; }
		double getF() const { return f; }

		double distance(int n) const { return (k*f)/n; } // расстояние до центра в полярной системе координат в зависимости от угла для точки, принадлежащей спирали
		double area_fig(int n) const { return  ((pow(n, 3) - pow((n - 1), 3)) * n * pow(k * 2 * M_PI, 2)) / 3; } //  площадь фигуры ограниченная n-ым витком спирали
		double area_circle(int n) const { return 2 * n * M_PI * pow(k * 2 * M_PI, 2); } // площадь n-ого кольца спирали
		double len() const { return (k / 2) * (f * sqrt(pow(f, 2) + 1) + log(f + sqrt(pow(f, 2) + 1))); } // длина дуги спирали до заданного угла полярного радиуса 
		double rad() const { return k * pow((pow(f, 2) + 1), 1.5) / (pow(f, 2) + 1); } // радиус кривизны спирали 
	};
}
#endif
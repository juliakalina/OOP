#include "spiral.h"
#include <iostream>

#include <math.h> 
#include "vld.h"

using namespace Prog2;

	int main() {

		Spiral s;

		double k_step;
		double f_ungle;
		int n;

		int fl1 = 1;
		while (fl1) {
			std::cout << "Archimedean spirale is:" << std::endl;
			std::cout << "r = k * f" << std::endl;

			std::cout << "Enter the k:" << std::endl;
			std::cin >> k_step;
			s.setK(k_step);


			std::cout << "Enter the ungle:" << std::endl;
			std::cin >> f_ungle;
			std::cout << "Enter the num of spiral turn:" << std::endl;
			std::cin >> n;
			if (((f_ungle * M_PI / 180 <= 2 * M_PI) && f_ungle > 0) &&(n<=f_ungle)) {
				s.setF(f_ungle);
				try {


					std::cout << "Distance to the center:" << s.distance(n) << std::endl;
					std::cout << "Area of figure:" << s.area_fig(n) << std::endl;
					std::cout << "Area of circle:" << s.area_circle(n) << std::endl;
					std::cout << "Arc length:" << s.len() << std::endl;
					std::cout << "Spiral radius of curvature:" << s.rad() << std::endl;

				}
				catch (std::exception& ex) {
					std::cout << ex.what() << std::endl;
				}
			}
			else
			{
				fl1 = 0;
				std::cout << "[ERROR]" << std::endl;
			}
		}
		return 0;
	}
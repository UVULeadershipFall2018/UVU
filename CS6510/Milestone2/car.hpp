//
//  car.hpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/13/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#ifndef car_hpp
#define car_hpp

#include <string>
#include <stdio.h>
#include <memory>

class Car {
private:
	std::string make;
	std::string model;
	std::string color;
	int horsepower;

public:
	void setMake(std::string m) {make = m;}
	void setModel(std::string mo) {model = mo;}
	void printCar();
	Car(std::string m, std::string mo, int hp);
	void setHorses(int h) { horsepower = h;}
	Car();
	~Car();
};

#endif /* car_hpp */

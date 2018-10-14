//
//  car.cpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/13/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#include "car.hpp"
#include <string>
#include <iostream>

using namespace std;

Car::Car(std::string m, std::string mo, int hp) : make(m), model(mo), horsepower(hp){
	cout << "constructiong " << make << " " << std::endl;
}

Car::~Car() {
	cout << endl << "deconstructiong " << make << " " << std::endl;
}

Car::Car() {
	cout << "constructiong " << make << " " << std::endl;
}

void Car::printCar(){
	cout << "Make: " << make << endl << "Model: " << model << endl <<"Horsepower: " << horsepower << endl;
}





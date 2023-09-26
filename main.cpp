#pragma once
#include <iostream>
#include <fstream>
#include "vehicle.hpp"
#include "car.hpp"
#include "bus.hpp"
#include "bike.hpp"
#include "client.hpp"

int main()
{
    Car ex;
    std::string x;
    std::cout << "enter brand name: ";
    std::cin >> x;
    ex.SetBrand(x);
    std::cout << "the brand is "<< ex.GetBrand() << '\n';
    return 0;
}

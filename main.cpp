#include <iostream>
#include <fstream>
#include "vehicle.hpp"
#include "car.hpp"
#include "bus.hpp"
#include "bike.hpp"
#include "client.hpp"

int main()
{
    Vehicle ex;
    std::string x;
    std::cout << "enter brand name: ";
    std::cin >> x;
    ex.SetBrand(x);
    std::cout << "enter model: ";
    std::cin >> x;
    ex.SetModel(x);
    Bus another(ex.GetBrand(), ex.GetModel(), 1, 1, "uo");
    std::cout << "the brand is "<< another.GetBrand() << '\n';

    return 0;
}

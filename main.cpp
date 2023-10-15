#include <iostream>
#include <fstream>
#include "vehicle.hpp"
#include "car.hpp"
#include "bus.hpp"
#include "bike.hpp"
#include "client.hpp"



int main()
{
    Client cli;
    Bike bike;
    Bus bus;
    Car car;
    bike.SetBrand("eb");
    bike.SetModel("em");
    bus.SetBrand("sb");
    bus.SetModel("sm");
    car.SetBrand("rb");
    car.SetModel("rm");
    cli.AddElement(bike);
    cli.AddElement(bus);
    cli.AddElement(car);
    cli.ShowElements();
    return 0;
}

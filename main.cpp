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
    Car car1, car2;
    bike.SetBrand("eb");
    bike.SetModel("em");
    bus.SetBrand("sb");
    bus.SetModel("sm");
    car1.SetBrand("rb1");
    car1.SetModel("rm1");
    car2.SetBrand("rb2");
    car2.SetModel("rm2");
    cli.AddElement(bike);
    cli.AddElement(bus);
    cli.AddElement(car1);
    cli.AddElement(car2);
    cli.Menu();
    return 0;
}

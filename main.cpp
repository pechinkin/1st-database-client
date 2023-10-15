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
    Car r;
    Bus s;
    cli.AddElement(r);
    cli.AddElement(s);
    cli.AddElement(r);
    cli.AddElement(s);
    cli.ShowElements();
    cli.DeleteElement(2, 0);
    cli.ShowElements();
    cli.DeleteElement(1, 0);
    cli.ShowElements();
    return 0;
}

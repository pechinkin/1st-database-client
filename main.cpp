#include <iostream>
#include <fstream>
#include <sstream>
#include "vehicle.hpp"
#include "car.hpp"
#include "bus.hpp"
#include "bike.hpp"
#include "client.hpp"
// try add #include "client.hpp" again
// it happens often in big projects,
// where one modulo reference another one two three...


int main()
{
    Client cli;
    cli.Menu();
    return 0;
}

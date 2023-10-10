#include <iostream>
#include <fstream>
#include "vehicle.hpp"
#include "car.hpp"
#include "bus.hpp"
#include "bike.hpp"
#include "client.hpp"

int main()
{
    Vehicle first("b_1", "m_1");
    Vehicle second("b_2", "m_2");
    Vehicle third("b_3", "m_3");
    Vehicle fourth("b_4", "m_4");
    Client cli;
    std::cout << cli.GetSize() << std::endl;
    cli.AddElement(first);
    cli.AddElement(second);
    cli.AddElement(third);
    cli.AddElement(fourth);
    std::cout << cli.GetSize() << std::endl;
    cli.ShowElements();
    cli.DeleteElement(0);
    std::cout << cli.GetSize() << std::endl;
    cli.ShowElements();
    return 0;
}

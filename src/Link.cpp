/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot
** File description:
** Link
*/

#include "Link.hpp"

void nts::Link::set_component_1()
{
    std::string component_1;
    std::string line = _line;
    std::string delimiter = ":";
    size_t pos = 0;
    std::string token;

    pos = _line.find(delimiter);
    if (pos == std::string::npos)
        throw std::invalid_argument("setComponent: delimiter found");
    token = _line.substr(0, pos);
    component_1 = token;
    _line.erase(0, pos + delimiter.length());
    _component_1 = component_1;
}

void nts::Link::set_component_2()
{
    std::string component_2;
    std::string line = _line;
    std::string delimiter = ":";
    size_t pos = 0;
    std::string token;

    pos = _line.find(delimiter);
    if (pos == std::string::npos)
        throw std::invalid_argument("setComponent: no delimiter found");
    token = _line.substr(0, pos);
    component_2 = token;
    _line.erase(0, pos + delimiter.length());
    _component_2 = component_2;
}

void nts::Link::set_pin_1()
{
    std::string pin_1;
    std::string line = _line;
    std::string delimiter = " ";
    size_t pos = 0;
    std::string token;

    pos = _line.find(delimiter);
    if (pos == std::string::npos)
        throw std::invalid_argument("setComponent: invalid parsing in links");
    token = _line.substr(0, pos);
    pin_1 = token;
    _line.erase(0, pos + delimiter.length());
    _pin_1 = std::stoi(pin_1);
}

void nts::Link::set_pin_2()
{
    _pin_2 = std::stoi(_line);
}

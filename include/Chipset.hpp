

/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot [WSL : Ubuntu]
** File description:
** Chipset
*/

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


class Chipset {
    public:
        Chipset(std::string name, std::string type):_name(name), _type(type){};
        ~Chipset(){};
        std::string get_name(){return _name;};
        std::string get_type(){return _type;};
    private:
        std::string _name;
        std::string _type;
};
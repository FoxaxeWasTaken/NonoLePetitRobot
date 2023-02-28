/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot
** File description:
** Link
*/

#pragma once
#include <iostream>
#include <string>

class Link {
    public:
        Link(std::string line)
            :_line(line){};
        ~Link(){};
        void set_component_1();
        void set_component_2();
        void set_pin_1();
        void set_pin_2();
        std::string get_component_1(){return _component_1;};
        std::string get_component_2(){return _component_2;};
        int get_pin_1(){return _pin_1;};
        int get_pin_2(){return _pin_2;};
    private:
        std::string _line;
        std::string _component_1;
        std::string _component_2;
        int _pin_1;
        int _pin_2;
};

/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot
** File description:
** Global_loop
*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>
#include "Link.hpp"
#include <strings.h>
#include "Circuit.hpp"
#include "Global_loop.hpp"
#include <signal.h>
#include "SpecialComponent.hpp"

volatile int ctrInt = 0;

void sigint_handler(int sig)
{
    (void)sig;
    ctrInt = 1;
}

Global_loop::Global_loop(std::shared_ptr<nts::Circuit> circuit)
{
    this->_circuit = circuit;
};


void Global_loop::check_if_name_valid(std::string input)
{
    std::string name;
    std::string delimiter = "=";
    size_t pos = 0;

    pos = input.find(delimiter);
    name = input.substr(0, pos);
    try {
        _circuit->getComponent(name);
    } catch (std::runtime_error &e) {
        std::cout << e.what();
    }
    _name = name;
}

void Global_loop::check_value(std::string input)
{
    std::string value;
    nts::Tristate state;
    std::string delimiter = "=";
    size_t pos = 0;

    pos = input.find(delimiter);
    value = input.substr(pos + 1);

    if (value == "U")
        state = nts::Tristate::UNDEFINED;
    else if (value == "0")
        state = nts::Tristate::FALSE;
    else if (value == "1")
        state = nts::Tristate::TRUE;
    else
        throw ("there is error");

    if (dynamic_cast<nts::InputComponent *>(_circuit->getComponent(_name).get())) {
        static_cast<nts::InputComponent *>(_circuit->getComponent(_name).get())->setBuf(true);
        static_cast<nts::InputComponent *>(_circuit->getComponent(_name).get())->setBufVal((state));
    } else if (dynamic_cast<nts::ClockComponent *>(_circuit->getComponent(_name).get())) {
        static_cast<nts::ClockComponent *>(_circuit->getComponent(_name).get())->setBuf(true);
        static_cast<nts::ClockComponent *>(_circuit->getComponent(_name).get())->setBufVal((state));
    }
}

void Global_loop::modif_value_component(std::string input)
{
    check_if_name_valid(input);
    check_value(input);
}


void Global_loop::global_loop()
{
    std::string input;
    std::cout << "> ";

    while (std::getline(std::cin, input)) {
        ctrInt = 0;
        if (input == "exit")
            exit(0);
        if (input == "simulate")
            _circuit->simulate(1);
        if (input == "display")
            _circuit->display();
        if (input == "loop") {
            signal(SIGINT, &sigint_handler);
            while (ctrInt == 0) {
                _circuit->simulate(1);
                _circuit->display();
            }
        }
        if (input.find("=") != std::string::npos)
            modif_value_component(input);
        std::cout << "> ";
    }
}
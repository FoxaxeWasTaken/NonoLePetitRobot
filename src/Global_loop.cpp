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


std::string Global_loop::rm_space_before_and_after(std::string input)
{
    for (size_t i = 0; i < input.size(); i++) {
        if ((input.data()[i] == ' ' || input.data()[i] == '\t')) {
            input.erase(i, 1);
            i--;
        } else
            break;
    }
    for (size_t i = input.size() - 1; i > 0; i--) {
        if ((input.data()[i] == ' ' || input.data()[i] == '\t')) {
            input.erase(i, 1);
        } else
            break;
    }
    return input;
}

bool Global_loop::check_command(std::string input)
{
    std::string delimiter = "=";
    size_t pos = 0;

    pos = input.find(delimiter);
    if ((input.data()[pos + 1] != '0' && input.data()[pos + 1] != '1' && input.data()[pos + 1] != 'U') || input.data()[pos + 2] != '\0')
        return false;
    if (input.data()[pos - 1] == ' ' || input.data()[pos - 1] == '\t')
        return false;
    return true;
}

void Global_loop::global_loop()
{
    std::string input;
    std::cout << "> ";

    while (std::getline(std::cin, input)) {
        input = rm_space_before_and_after(input);
        ctrInt = 0;
        if (input == "exit") {
            exit(0);
            continue;
        }
        if (input == "simulate") {
            _circuit->simulate(1);
            continue;
        }
        if (input == "display") {
            _circuit->display();
            continue;
        }
        if (input == "loop") {
            signal(SIGINT, &sigint_handler);
            while (ctrInt == 0) {
                _circuit->simulate(1);
                _circuit->display();
            }
            continue;
        }
        if (input.find("=") != std::string::npos) {
            if (check_command(input)) {
                try {
                    modif_value_component(input);
                } catch(std::runtime_error &e) {
                    std::cerr << "Bad command" << std::endl;
                }
            } else
                std::cerr << "Bad command" << std::endl;
        } else {
            std::cerr << "Bad command" << std::endl;
        }
        std::cout << "> ";
    }
}
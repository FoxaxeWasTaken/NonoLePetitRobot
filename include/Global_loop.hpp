/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot
** File description:
** Global_loop
*/

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Link.hpp"
#include "Circuit.hpp"

namespace nts {
    class Global_loop {
        public:
            Global_loop(std::shared_ptr<nts::Circuit> circuit);
            ~Global_loop(){};
            void global_loop();
            void modif_value_component(std::string input);
            std::string rm_space_before_and_after(std::string input);
            std::shared_ptr<nts::Circuit> get_circuit(){return _circuit;};
            bool check_command(std::string input);

            void check_if_name_valid(std::string input);
            void check_value(std::string input);

        private:
            std::shared_ptr<nts::Circuit> _circuit;
            std::string _name;
            std::string _value;
    };
}
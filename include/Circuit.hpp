/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot [WSL: Ubuntu]
** File description:
** Circuit
*/

#pragma once

#include "AComponent.hpp"

namespace nts {
    class Circuit {
        public:
            Circuit();
            ~Circuit() = default;

            void addComponent(std::unique_ptr<nts::IComponent> component);
            void setLink(std::string const &name1, std::size_t pin1, std::string const &name2, std::size_t pin2);
            void simulate(std::size_t tick);
            void display();
            std::unique_ptr<nts::IComponent> &getComponent(std::string const &name);
            void addTick(std::size_t tick);

        private:
            std::vector<std::unique_ptr<nts::IComponent>> _components;
            std::size_t _tick;
    };
}

/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot [WSL: Ubuntu]
** File description:
** Component4069
*/

#pragma once

#include "ElementaryComponent.hpp"

namespace nts {
    class Component4069 : public AComponent {
        public:
            Component4069(std::string name);
            ~Component4069() override = default;

            nts::Tristate compute(std::size_t pin = 1) override;
            NotComponent &getNot(std::size_t index);

        private:
            NotComponent _nots[6];
    };
}

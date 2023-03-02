/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot [WSL : Ubuntu]
** File description:
** Component4081
*/

#pragma once

#include "ElementaryComponent.hpp"

namespace nts {
    class Component4081 : public AComponent {
        public:
            Component4081(std::string name);
            ~Component4081() override = default;

            nts::Tristate compute(std::size_t pin = 1) override;
            AndComponent &getAnd(std::size_t index);

        private:
            AndComponent _ands[4];
    };
}

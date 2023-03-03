/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot [WSL : Ubuntu]
** File description:
** Component4011
*/

#pragma once

#include "ElementaryComponent.hpp"

namespace nts
{
    class Component4011 : public AComponent {
        public:
            Component4011(std::string name);
            ~Component4011() override = default;

            nts::Tristate compute(std::size_t pin = 1) override;
            AndComponent &getAnd(std::size_t index);
            NotComponent &getNot(std::size_t index);

        private:
            AndComponent _ands[4];
            NotComponent _nots[4];
    };
}

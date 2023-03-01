/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot [WSL: Ubuntu]
** File description:
** Component4030
*/

#pragma once

#include "ElementaryComponent.hpp"

namespace nts {
    class Component4030 : public AComponent {
        public:
            Component4030(std::string name);
            ~Component4030() override = default;
            nts::Tristate compute(std::size_t pin = 1) override;
            XorComponent &getXor(std::size_t index);

        private:
            XorComponent _xors[4];
    };
}

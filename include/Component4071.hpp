/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot [WSL: Ubuntu]
** File description:
** Component4071
*/

#pragma once

#include "ElementaryComponent.hpp"

namespace nts {
    class Component4071 : public AComponent {
        public:
            Component4071(std::string name);
            ~Component4071() override = default;

            nts::Tristate compute(std::size_t pin = 1) override;
            OrComponent &getOr(std::size_t index);

        private:
            OrComponent _ors[4];
    };
}

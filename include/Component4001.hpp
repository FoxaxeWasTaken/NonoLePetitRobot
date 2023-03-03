/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot [WSL : Ubuntu]
** File description:
** Component4001
*/

#pragma once

#include "ElementaryComponent.hpp"

namespace nts {
    class Component4001 : public AComponent {
        public:
            Component4001(std::string name);
            ~Component4001() override = default;

            nts::Tristate compute(std::size_t pin = 1) override;
            OrComponent &getOr(std::size_t index);
            NotComponent &getNot(std::size_t index);

        private:
            OrComponent _ors[4];
            NotComponent _nots[4];
    };
}

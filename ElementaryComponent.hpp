/*
** EPITECH PROJECT, 2023
** BSNanoTekSpice [WSL: Ubuntu]
** File description:
** ElementaryComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts {
    class AndComponent : public AComponent {
        public:
            AndComponent(std::string name = "And");
            ~AndComponent() override = default;

            nts::Tristate compute(std::size_t pin) override;
    };
    class OrComponent : public AComponent {
        public:
            OrComponent(std::string name = "Or");
            ~OrComponent() override = default;

            nts::Tristate compute(std::size_t pin) override;
    };
    class XorComponent : public AComponent{
        public:
            XorComponent(std::string name = "Xor");
            ~XorComponent() override = default;

            nts::Tristate compute(std::size_t pin) override;
    };
    class NotComponent : public AComponent {
        public:
            NotComponent(std::string name = "Not");
            ~NotComponent() override = default;

            nts::Tristate compute(std::size_t pin) override;
    };
}

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
            AndComponent(std::string name);
            AndComponent(const AndComponent &);
            ~AndComponent() override = default;

            nts::Tristate compute(std::size_t pin) override;
    };
    class OrComponent : public AComponent {
        public:
            OrComponent(std::string);
            OrComponent(const OrComponent &);
            ~OrComponent() override = default;

            nts::Tristate compute(std::size_t pin) override;
    };
    class XorComponent : public AComponent{
        public:
            XorComponent(std::string);
            XorComponent(const XorComponent &);
            ~XorComponent() override = default;

            nts::Tristate compute(std::size_t pin) override;
    };
    class NotComponent : public AComponent {
        public:
            NotComponent(std::string);
            NotComponent(const NotComponent &);
            ~NotComponent() override = default;

            nts::Tristate compute(std::size_t pin) override;
    };
}

/*
** EPITECH PROJECT, 2023
** BSNanoTekSpice [WSL: Ubuntu]
** File description:
** SpecialComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts {
    class TrueComponent : public nts::AComponent {
        public:
            TrueComponent(std::string name = "True");
            ~TrueComponent() override = default;

            nts::Tristate compute(std::size_t pin) override;
    };

    class FalseComponent : public nts::AComponent {
        public:
            FalseComponent(std::string name = "False");
            ~FalseComponent() override = default;

            nts::Tristate compute(std::size_t pin) override;
    };

    class InputComponent : public nts::AComponent {
        public:
            InputComponent(std::string name = "Input");
            ~InputComponent() override = default;

            nts::Tristate compute(std::size_t pin) override;
    };

    class OutputComponent : public nts::AComponent {
        public:
            OutputComponent(std::string name = "Output");
            ~OutputComponent() override = default;

            nts::Tristate compute(std::size_t pin) override;
    };
}

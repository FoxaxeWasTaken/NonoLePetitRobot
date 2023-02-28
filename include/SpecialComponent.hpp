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
            TrueComponent(std::string name);
            TrueComponent(const TrueComponent &);
            ~TrueComponent() override = default;

            nts::Tristate compute(std::size_t pin) override;
    };

    class FalseComponent : public nts::AComponent {
        public:
            FalseComponent(std::string name);
            FalseComponent(const FalseComponent &);
            ~FalseComponent() override = default;

            nts::Tristate compute(std::size_t pin) override;
    };

    class InputComponent : public nts::AComponent {
        public:
            InputComponent(std::string name);
            InputComponent(const InputComponent &);
            ~InputComponent() override = default;

            nts::Tristate compute(std::size_t pin) override;
            void simulate(std::size_t tick) override;
            nts::Tristate getBufVal() const;
            void setBufVal(nts::Tristate value);
            bool getBuf() const;
            void setBuf(bool value);

        private:
            bool _buf;
            nts::Tristate _bufVal;
    };

    class OutputComponent : public nts::AComponent {
        public:
            OutputComponent(std::string name);
            OutputComponent(const OutputComponent &);
            ~OutputComponent() override = default;

            nts::Tristate compute(std::size_t pin) override;
    };

    class ClockComponent : public nts::AComponent {
        public:
            ClockComponent(std::string name);
            ClockComponent(const ClockComponent &);
            ~ClockComponent() override = default;

            nts::Tristate compute(std::size_t pin) override;
            void simulate(std::size_t tick) override;
            nts::Tristate getBufVal() const;
            void setBufVal(nts::Tristate value);
            bool getBuf() const;
            void setBuf(bool value);

        private:
            bool _buf;
            nts::Tristate _bufVal;
    };
}

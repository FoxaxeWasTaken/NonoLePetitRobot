/*
** EPITECH PROJECT, 2023
** BSNanoTekSpice [WSL : Ubuntu]
** File description:
** AComponent
*/

#pragma once

#include "IComponent.hpp"

namespace nts {
    class AComponent : public IComponent {
        public:
            AComponent(std::string name, size_t nbPins, std::vector<nts::Pin> pins);
            AComponent(const AComponent &);
            virtual ~AComponent() override = default;

            void simulate(std::size_t tick) override {}
            virtual nts::Tristate compute(std::size_t pin) = 0;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            std::string getName() const override;
            size_t getNbPins() const override;
            std::vector<nts::Pin> getPins() const;
            nts::Pin &getPin(size_t index) override;

        private:
            std::string _name;
            size_t _nbPins;
            std::vector<nts::Pin> _pins;
    };
}

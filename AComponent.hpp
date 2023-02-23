/*
** EPITECH PROJECT, 2023
** BSNanoTekSpice [WSL : Ubuntu]
** File description:
** AComponent
*/

#pragma once

#include <vector>
#include <string>
#include <memory>
#include "IComponent.hpp"
#include "Pin.hpp"

namespace nts {

    class AComponent : public IComponent {
        public:
            AComponent(std::string name, size_t nbPins, std::vector<nts::APin> pins);
            virtual ~AComponent() override = default;

            void simulate(std::size_t tick) override {}
            virtual nts::Tristate compute(std::size_t pin) = 0;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            std::string getName() const;
            size_t getNbPins() const;
            std::vector<nts::APin> getPins() const;
            nts::APin *getPin(std::size_t pin) const;

        private:
            std::string _name;
            size_t _nbPins;
            std::vector<nts::APin> _pins;
    };
}

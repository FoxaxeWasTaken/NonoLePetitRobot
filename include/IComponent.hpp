/*
** EPITECH PROJECT, 2023
** BSNanoTekSpice [WSL : Ubuntu]
** File description:
** IComponent
*/

#pragma once

#include <cstddef>
#include <vector>
#include <string>
#include <memory>
#include "Pin.hpp"
#include "Common.hpp"

namespace nts {
    class Pin;

    class IComponent {
        public:
            IComponent() = default;
            virtual ~IComponent() = default;

            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin = 1) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual nts::Pin &getPin(size_t index) = 0;
            virtual std::size_t getNbPins() const = 0;
            virtual std::string getName() const = 0;
    };
}

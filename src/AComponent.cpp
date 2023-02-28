/*
** EPITECH PROJECT, 2023
** BSNanoTekSpice [WSL : Ubuntu]
** File description:
** Acomponent
*/

#include <stdexcept>
#include <iostream>
#include "AComponent.hpp"

nts::AComponent::AComponent(std::string name, size_t nbPins, std::vector<nts::Pin> pins)
    : _name(name), _nbPins(nbPins), _pins(pins)
{
    if (pins.size() != nbPins)
        throw std::invalid_argument("Number of pins is not equal to the number of pins in the vector");
}

nts::AComponent::AComponent(const AComponent &other)
    : _name(other._name), _nbPins(other._nbPins), _pins(other._pins)
{

}

std::string nts::AComponent::getName() const
{
    return _name;
}

std::size_t nts::AComponent::getNbPins() const
{
    return _nbPins;
}

std::vector<nts::Pin> nts::AComponent::getPins() const
{
    return _pins;
}

nts::Pin &nts::AComponent::getPin(size_t index)
{
    if (index > getNbPins() || index == 0)
        throw std::out_of_range("getPin: Index out of range");
    for (auto &pin : _pins) {
        if (pin.getIdxPin() == index)
            return pin;
    }
    return _pins[0];
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin > getNbPins() || pin == 0)
        throw std::out_of_range("setLink: This index out of range");
    if (otherPin > other.getNbPins() || otherPin == 0)
        throw std::out_of_range("setLink: other index out of range");
    if (getPin(pin).getType() == nts::PinType::OUTPUT && other.getPin(otherPin).getType() == nts::PinType::INPUT) {
        getPin(pin).addNextPin(std::make_shared<nts::Pin>(other.getPin(otherPin)));
        other.getPin(otherPin).addPrevPin(std::make_shared<nts::Pin>(getPin(pin)));
    } else if (getPin(pin).getType() == nts::PinType::INPUT && other.getPin(otherPin).getType() == nts::PinType::OUTPUT) {
        other.getPin(otherPin).addNextPin(std::make_shared<nts::Pin>(getPin(pin)));
        getPin(pin).addPrevPin(std::make_shared<nts::Pin>(other.getPin(otherPin)));
    } else {
        throw std::invalid_argument("Pin type is not compatible");
    }
}

std::ostream &operator <<(std::ostream &s, nts::Tristate v)
{
    switch (v) {
        case nts::Tristate::UNDEFINED:
            s << "U";
            break;
        case nts::Tristate::TRUE:
            s << "1";
            break;
        case nts::Tristate::FALSE:
            s << "0";
            break;
    }
    return s;
}

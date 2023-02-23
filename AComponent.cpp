/*
** EPITECH PROJECT, 2023
** BSNanoTekSpice [WSL : Ubuntu]
** File description:
** Acomponent
*/

#include <stdexcept>
#include "AComponent.hpp"

nts::AComponent::AComponent(std::string name, size_t nbPins, std::vector<nts::APin> pins)
    : _name(name), _nbPins(nbPins), _pins(pins)
{

}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::AComponent &otherComponent = static_cast<nts::AComponent &>(other);

    if (pin > _nbPins || otherPin > otherComponent.getNbPins()) {
        throw std::out_of_range("Pin out of range");
    }
    if (dynamic_cast<nts::OutputPin *>(getPin(pin)) && dynamic_cast<nts::InputPin *>(otherComponent.getPin(otherPin))) {
        static_cast<nts::OutputPin *>(getPin(pin))->setNextPin(std::make_shared<nts::InputPin>(otherComponent.getPin(otherPin)));
        static_cast<nts::InputPin *>(otherComponent.getPin(otherPin))->setPrevPin(std::make_shared<nts::OutputPin>(getPin(pin)));
    } else if (dynamic_cast<nts::InputPin *>(getPin(pin)) && dynamic_cast<nts::OutputPin *>(otherComponent.getPin(otherPin))) {
        static_cast<nts::InputPin *>(getPin(pin))->setPrevPin(std::make_shared<nts::OutputPin>(otherComponent.getPin(otherPin)));
        static_cast<nts::OutputPin *>(otherComponent.getPin(otherPin))->setNextPin(std::make_shared<nts::InputPin>(getPin(pin)));
    } else {
        throw std::invalid_argument("Pin is not an output or the other pin is not an input");
    }
}

std::string nts::AComponent::getName() const
{
    return _name;
}

std::size_t nts::AComponent::getNbPins() const
{
    return _nbPins;
}

std::vector<nts::APin> nts::AComponent::getPins() const
{
    return _pins;
}

nts::APin *nts::AComponent::getPin(std::size_t pin) const
{
    const APin *pinPtr = nullptr;
    if (pin > getNbPins()) {
        throw std::out_of_range("Pin out of range");
    }

    for (auto &pinIt : _pins) {
        if (pinIt.getIdxPin() == pin) {
            pinPtr = &pinIt;
        }
    }
    return const_cast<APin *>(pinPtr);
}

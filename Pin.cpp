/*
** EPITECH PROJECT, 2023
** BSNanoTekSpice [WSL: Ubuntu]
** File description:
** Pin
*/

#include "Pin.hpp"

#include "Pin.hpp"
#include <stdexcept>

nts::InputPin::InputPin(std::size_t nbPin, IComponent *component)
    : APin(nbPin, component), _prevPin(nullptr), _nextPin(nullptr)
{

}

std::shared_ptr<nts::APin> nts::InputPin::getPrevPin() const
{
    return _prevPin;
}

void nts::InputPin::setPrevPin(std::shared_ptr<nts::APin> prevPin)
{
    _prevPin = prevPin;
}

std::shared_ptr<nts::APin> nts::InputPin::getNextPin() const
{
    return _nextPin;
}

void nts::InputPin::setNextPin(std::shared_ptr<nts::APin> nextPin)
{
    _nextPin = nextPin;
}

nts::OutputPin::OutputPin(std::size_t nbPin, nts::IComponent *component)
    : APin(nbPin, component), _nextPins(), _prevPins()
{

}

std::vector<std::shared_ptr<nts::APin>> nts::OutputPin::getNextPins() const
{
    return _nextPins;
}

std::shared_ptr<nts::APin> nts::OutputPin::getNextPin(size_t index) const
{
    if (index > this->getIdxPin())
        throw std::out_of_range("_nextPins out of range");
    for (auto &it : _nextPins) {
        if (it->getIdxPin() == index)
            return it;
    }
    return nullptr;
}

void nts::OutputPin::setNextPin(std::shared_ptr<nts::APin> nextPins)
{
    _nextPins.push_back(nextPins);
}

std::vector<std::shared_ptr<nts::APin>> nts::OutputPin::getPrevPins() const
{
    return _prevPins;
}

std::shared_ptr<nts::APin> nts::OutputPin::getPrevPin(size_t index) const {
    if (index > this->getIdxPin())
        throw std::out_of_range("_prevpin out of range");
    for (auto &it : _prevPins) {
        if (it->getIdxPin() == index)
            return it;
    }
    return nullptr;
}

void nts::OutputPin::setPrevPin(std::shared_ptr<nts::APin> prevPins)
{
    _prevPins.push_back(prevPins);
}

nts::OtherPin::OtherPin(std::size_t nbPin, IComponent *component)
    : APin(nbPin, component)
{

}

nts::Tristate nts::InputPin::computePrev() const {
    return getPrevPin()->getComponent()->compute(getPrevPin()->getIdxPin());
}

nts::InputPin::InputPin(nts::InputPin const &other)
    : APin(other), _prevPin(other._prevPin), _nextPin(other._nextPin)
{

}

nts::OutputPin::OutputPin(nts::OutputPin const &other)
    : APin(other), _nextPins(other._nextPins), _prevPins(other._prevPins)
{

}

nts::OtherPin::OtherPin(nts::OtherPin const &other)
    : APin(other)
{

}

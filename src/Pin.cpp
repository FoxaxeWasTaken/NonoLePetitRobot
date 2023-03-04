/*
** EPITECH PROJECT, 2023
** BSNanoTekSpice [WSL: Ubuntu]
** File description:
** Pin
*/

#include <stdexcept>
#include <iostream>
#include <memory>
#include "Pin.hpp"

nts::Pin::Pin(std::size_t idxPin, PinType type, IComponent &component)
    : _idxPin(idxPin), _value(nts::UNDEFINED), _type(type), _component(component)
{

}

nts::Pin::Pin(Pin const &other)
    : _idxPin(other._idxPin), _value(other._value), _type(other._type), _component(other._component)
{

}

std::size_t nts::Pin::getIdxPin() const
{
    return _idxPin;
}

void nts::Pin::setValue(nts::Tristate value)
{
    _value = value;
}

nts::Tristate nts::Pin::getValue() const
{
    return _value;
}

nts::PinType nts::Pin::getType() const
{
    return _type;
}

nts::IComponent &nts::Pin::getComponent()
{
    return _component;
}

std::vector<std::shared_ptr<nts::Pin>> nts::Pin::getNextPins() const
{
    return _nextPins;
}

std::shared_ptr<nts::Pin> nts::Pin::getNextPin(size_t index) const
{
    return _nextPins[index];
}

void nts::Pin::addNextPin(std::shared_ptr<nts::Pin> nextPin)
{
    if (getType() == nts::PinType::INPUT && _nextPins.size() == 1)
        throw std::runtime_error("addNextPin: Input pin already has a next pin");
    _nextPins.push_back(nextPin);
}

void nts::Pin::addPrevPin(std::shared_ptr<nts::Pin> prevPin)
{
    if (getType() == nts::PinType::INPUT && getNbPrevPins() == 1)
        throw std::runtime_error("addPrevPin: Input pin already has a prev pin");
    _prevPins.push_back(prevPin);
}

std::vector<std::shared_ptr<nts::Pin>> nts::Pin::getPrevPins() const
{
    return _prevPins;
}

std::shared_ptr<nts::Pin> nts::Pin::getPrevPin(size_t index) const
{
    return _prevPins[index];
}

nts::Tristate nts::Pin::computePrev() const
{
    if (getNbPrevPins() == 0) {
        return nts::UNDEFINED;
    }
    return getPrevPin(0)->getComponent().compute(getPrevPin(0)->getIdxPin());
}

std::size_t nts::Pin::getNbPrevPins() const
{
    return _prevPins.size();
}

std::size_t nts::Pin::getNbNextPins() const
{
    return _nextPins.size();
}

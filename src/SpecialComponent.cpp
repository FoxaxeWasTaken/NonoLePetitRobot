/*
** EPITECH PROJECT, 2023
** BSNanoTekSpice [WSL: Ubuntu]
** File description:
** SpecialComponent
*/

#include "SpecialComponent.hpp"
#include <stdexcept>

nts::TrueComponent::TrueComponent(std::string name)
    : nts::AComponent(name, 1, std::vector<Pin>{Pin(1, PinType::OUTPUT, *this)})
{
    getPin(1).setValue(nts::TRUE);
}

nts::TrueComponent::TrueComponent(nts::TrueComponent const &other)
    : nts::AComponent(other)
{

}

nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    (void) pin;
    return nts::TRUE;
}

nts::FalseComponent::FalseComponent(std::string name)
    : nts::AComponent(name, 1, std::vector<Pin>{Pin(1, PinType::OUTPUT, *this)})
{
    getPin(1).setValue(nts::FALSE);
}

nts::FalseComponent::FalseComponent(nts::FalseComponent const &other)
    : nts::AComponent(other)
{

}

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
    (void) pin;
    return nts::FALSE;
}

nts::InputComponent::InputComponent(std::string name)
    : nts::AComponent(name, 1, std::vector<Pin>{Pin(1, PinType::OUTPUT, *this)}),  _buf(false), _bufVal(nts::UNDEFINED)
{

}

nts::InputComponent::InputComponent(nts::InputComponent const &other)
    : nts::AComponent(other)
{

}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    (void) pin;
    return getPin(1).getValue();
}

nts::OutputComponent::OutputComponent(std::string name)
    : nts::AComponent(name, 1, std::vector<Pin>{Pin(1, PinType::INPUT, *this)})
{

}

nts::OutputComponent::OutputComponent(nts::OutputComponent const &other)
    : nts::AComponent(other)
{

}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    (void) pin;
    return getPin(1).computePrev();
}

nts::ClockComponent::ClockComponent(std::string name)
    : nts::AComponent(name, 1, std::vector<Pin>{Pin(1, PinType::OUTPUT, *this)}), _buf(false), _bufVal(nts::UNDEFINED)
{

}

nts::ClockComponent::ClockComponent(nts::ClockComponent const &other)
    : nts::AComponent(other)
{

}

nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    (void) pin;
    return getPin(1).getValue();
}

void nts::InputComponent::simulate(std::size_t tick)
{
    (void) tick;
    if (getBuf()) {
        getPin(1).setValue(_bufVal);
        setBuf(false);
        return;
    }
}

nts::Tristate nts::InputComponent::getBufVal() const
{
    return _bufVal;
}

void nts::InputComponent::setBufVal(nts::Tristate value)
{
    _bufVal = value;
}

nts::Tristate nts::ClockComponent::getBufVal() const
{
    return _bufVal;
}

void nts::ClockComponent::setBufVal(nts::Tristate value)
{
    _bufVal = value;
}

bool nts::InputComponent::getBuf() const
{
    return _buf;
}

void nts::InputComponent::setBuf(bool value)
{
    _buf = value;
}

bool nts::ClockComponent::getBuf() const
{
    return _buf;
}

void nts::ClockComponent::setBuf(bool value)
{
    _buf = value;
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    (void) tick;
    if (getBuf()) {
        getPin(1).setValue(_bufVal);
        setBuf(false);
        return;
    }
    if (getPin(1).getValue() == nts::TRUE) {
        getPin(1).setValue(nts::FALSE);
    } else if (getPin(1).getValue() == nts::FALSE) {
        getPin(1).setValue(nts::TRUE);
    }
}

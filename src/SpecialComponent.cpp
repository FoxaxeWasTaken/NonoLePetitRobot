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
    if (pin != 1) {
        throw std::out_of_range("Pin out of range");
    }
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
    if (pin != 1) {
        throw std::out_of_range("Pin out of range");
    }
    return nts::FALSE;
}

nts::InputComponent::InputComponent(std::string name)
    : nts::AComponent(name, 1, std::vector<Pin>{Pin(1, PinType::OUTPUT, *this)})
{

}

nts::InputComponent::InputComponent(nts::InputComponent const &other)
    : nts::AComponent(other)
{

}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    if (pin != 1) {
        throw std::out_of_range("Pin out of range");
    }
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
    if (pin != 1) {
        throw std::out_of_range("Pin out of range");
    }
    return getPin(1).getValue();
}

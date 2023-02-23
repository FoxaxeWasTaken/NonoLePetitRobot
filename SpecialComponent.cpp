/*
** EPITECH PROJECT, 2023
** BSNanoTekSpice [WSL: Ubuntu]
** File description:
** SpecialComponent
*/

#include "SpecialComponent.hpp"
#include <stdexcept>

nts::TrueComponent::TrueComponent(std::string name)
    : nts::AComponent(name, 1, std::vector<nts::APin>(1, nts::OutputPin(1, this)))
{
    getPin(1)->setValue(nts::TRUE);
}

nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    if (pin != 1) {
        throw std::out_of_range("Pin out of range");
    }
    return nts::TRUE;
}

nts::FalseComponent::FalseComponent(std::string name)
    : nts::AComponent(name, 1, std::vector<nts::APin>(1, nts::OutputPin(1, this)))
{
    getPin(1)->setValue(nts::FALSE);
}

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
    if (pin != 1) {
        throw std::out_of_range("Pin out of range");
    }
    return nts::FALSE;
}

nts::InputComponent::InputComponent(std::string name)
    : nts::AComponent(name, 1, std::vector<nts::APin>(1, nts::OutputPin(1, this)))
{

}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    if (pin != 1) {
        throw std::out_of_range("Pin out of range");
    }
    return getPin(1)->getValue();
}

nts::OutputComponent::OutputComponent(std::string name)
    : nts::AComponent(name, 1, std::vector<nts::APin>(1, nts::InputPin(1, this)))
{

}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    if (pin != 1) {
        throw std::out_of_range("Pin out of range");
    }
    return getPin(1)->getValue();
}

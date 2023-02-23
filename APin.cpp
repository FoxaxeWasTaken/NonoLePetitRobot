/*
** EPITECH PROJECT, 2023
** BSNanoTekSpice [WSL: Ubuntu]
** File description:
** APin
*/

#include "APin.hpp"

nts::APin::APin(std::size_t nbPin, IComponent *component)
    : _idxPin(nbPin), _value(nts::UNDEFINED), _component(component)
{

}

std::size_t nts::APin::getIdxPin() const {
    return _idxPin;
}

void nts::APin::setValue(nts::Tristate value) {
    _value = value;
}

nts::Tristate nts::APin::getValue() const {
    return _value;
}

nts::IComponent *nts::APin::getComponent() const {
    return _component;
}

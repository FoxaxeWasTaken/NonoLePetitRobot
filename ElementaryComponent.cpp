/*
** EPITECH PROJECT, 2023
** BSNanoTekSpice [WSL: Ubuntu]
** File description:
** ElementaryComponent
*/

#include "ElementaryComponent.hpp"
#include <stdexcept>

nts::AndComponent::AndComponent(std::string name)
    : nts::AComponent(name, 3, std::vector<nts::APin>{nts::InputPin(1, this), nts::InputPin(2, this), nts::OutputPin(3, this)})
{
    setLink(1, *this, 3);
    setLink(2, *this, 3);
}

nts::Tristate nts::AndComponent::compute(std::size_t pin)
{
    if (pin >= 3 || pin == 0) {
        throw std::out_of_range("AndComponent::compute: pin out of range");
    }
    if (pin == 1) {
        return static_cast<InputPin *>(getPin(1))->computePrev();
    } else if (pin == 2) {
        return static_cast<InputPin *>(getPin(2))->computePrev();
    } else {
        nts::Tristate pin1 = static_cast<InputPin *>(getPin(1))->computePrev();
        nts::Tristate pin2 = static_cast<InputPin *>(getPin(2))->computePrev();
        if (pin1 == nts::Tristate::UNDEFINED || pin2 == nts::Tristate::UNDEFINED) {
            return nts::Tristate::UNDEFINED;
        }
        if (pin1 == nts::Tristate::TRUE && pin2 == nts::Tristate::TRUE) {
            return nts::Tristate::TRUE;
        }
        return nts::Tristate::FALSE;
    }
}

nts::OrComponent::OrComponent(std::string name)
    : AComponent(name, 3, std::vector<APin>{InputPin(1, this), InputPin(2, this), OutputPin(3, this)})
{
    setLink(1, *this, 3);
    setLink(2, *this, 3);
}

nts::Tristate nts::OrComponent::compute(std::size_t pin)
{
    if (pin >= 3 || pin == 0) {
        throw std::out_of_range("OrComponent::compute: pin out of range");
    }
    if (pin == 1) {
        return static_cast<InputPin *>(getPin(1))->computePrev();
    } else if (pin == 2) {
        return static_cast<InputPin *>(getPin(2))->computePrev();
    } else {
        nts::Tristate pin1 = static_cast<InputPin *>(getPin(1))->computePrev();
        nts::Tristate pin2 = static_cast<InputPin *>(getPin(2))->computePrev();
        if (pin1 == nts::Tristate::UNDEFINED || pin2 == nts::Tristate::UNDEFINED) {
            return nts::Tristate::UNDEFINED;
        }
        if (pin1 == nts::Tristate::TRUE || pin2 == nts::Tristate::TRUE) {
            return nts::Tristate::TRUE;
        }
        return nts::Tristate::FALSE;
    }
}

nts::XorComponent::XorComponent(std::string name)
    : AComponent(name, 3, std::vector<APin>{InputPin(1, this), InputPin(2, this), OutputPin(3, this)})
{
    setLink(1, *this, 3);
    setLink(2, *this, 3);
}

nts::Tristate nts::XorComponent::compute(std::size_t pin)
{
    if (pin >= 3 || pin == 0) {
        throw std::out_of_range("XorComponent::compute: pin out of range");
    }
    if (pin == 1) {
        return static_cast<InputPin *>(getPin(1))->computePrev();
    } else if (pin == 2) {
        return static_cast<InputPin *>(getPin(2))->computePrev();
    } else {
        nts::Tristate pin1 = static_cast<InputPin *>(getPin(1))->computePrev();
        nts::Tristate pin2 = static_cast<InputPin *>(getPin(2))->computePrev();
        if (pin1 == nts::Tristate::UNDEFINED || pin2 == nts::Tristate::UNDEFINED) {
            return nts::Tristate::UNDEFINED;
        }
        if (pin1 == nts::Tristate::TRUE && pin2 == nts::Tristate::FALSE) {
            return nts::Tristate::TRUE;
        }
        if (pin1 == nts::Tristate::FALSE && pin2 == nts::Tristate::TRUE) {
            return nts::Tristate::TRUE;
        }
        return nts::Tristate::FALSE;
    }
}

nts::NotComponent::NotComponent(std::string name)
    : AComponent(name, 2, std::vector<APin>{InputPin(1, this), OutputPin(2, this)})
{
    setLink(1, *this, 2);
}

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    if (pin >= 2 || pin == 0) {
        throw std::out_of_range("NotComponent::compute: pin out of range");
    }
    if (pin == 1) {
        return static_cast<InputPin *>(getPin(1))->computePrev();
    } else {
        nts::Tristate pin1 = static_cast<InputPin *>(getPin(1))->computePrev();
        if (pin1 == nts::Tristate::UNDEFINED) {
            return nts::Tristate::UNDEFINED;
        }
        if (pin1 == nts::Tristate::TRUE) {
            return nts::Tristate::FALSE;
        }
        return nts::Tristate::TRUE;
    }
}

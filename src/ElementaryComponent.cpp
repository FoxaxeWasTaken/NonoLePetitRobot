/*
** EPITECH PROJECT, 2023
** BSNanoTekSpice [WSL: Ubuntu]
** File description:
** ElementaryComponent
*/

#include "ElementaryComponent.hpp"
#include <stdexcept>

nts::AndComponent::AndComponent(std::string name)
    : AComponent(name, 3, std::vector<Pin>{Pin(1, PinType::INPUT, *this), Pin(2, PinType::INPUT, *this), Pin(3, PinType::OUTPUT, *this)})
{
    getPin(1).addNextPin(std::make_shared<nts::Pin>(getPin(3)));
    getPin(3).addPrevPin(std::make_shared<nts::Pin>(getPin(1)));
    getPin(2).addNextPin(std::make_shared<nts::Pin>(getPin(3)));
    getPin(3).addPrevPin(std::make_shared<nts::Pin>(getPin(2)));
}

nts::AndComponent::AndComponent(const AndComponent &other)
    : AComponent(other)
{

}

nts::Tristate nts::AndComponent::compute(std::size_t pin)
{
    if (pin == 1) {
        return getPin(1).computePrev();
    }
    if (pin == 2) {
        return getPin(2).computePrev();
    }
    nts::Tristate pin1 = getPin(1).computePrev();
    nts::Tristate pin2 = getPin(2).computePrev();
    if (pin1 == nts::Tristate::FALSE || pin2 == nts::Tristate::FALSE) {
        return nts::Tristate::FALSE;
    }
    if (pin1 == nts::Tristate::TRUE && pin2 == nts::Tristate::TRUE) {
        return nts::Tristate::TRUE;
    }
    return nts::Tristate::UNDEFINED;
}

nts::OrComponent::OrComponent(std::string name)
    : AComponent(name, 3, std::vector<Pin>{Pin(1, PinType::INPUT, *this), Pin(2, PinType::INPUT, *this), Pin(3, PinType::OUTPUT, *this)})
{
    getPin(1).addNextPin(std::make_shared<nts::Pin>(getPin(3)));
    getPin(3).addPrevPin(std::make_shared<nts::Pin>(getPin(1)));
    getPin(2).addNextPin(std::make_shared<nts::Pin>(getPin(3)));
    getPin(3).addPrevPin(std::make_shared<nts::Pin>(getPin(2)));
}

nts::OrComponent::OrComponent(nts::OrComponent const &other)
    : AComponent(other)
{

}

nts::Tristate nts::OrComponent::compute(std::size_t pin)
{
    if (pin == 1) {
        return getPin(1).computePrev();
    }
    if (pin == 2) {
        return getPin(2).computePrev();
    }
    nts::Tristate pin1 = getPin(1).computePrev();
    nts::Tristate pin2 = getPin(2).computePrev();
    if (pin1 == nts::Tristate::TRUE || pin2 == nts::Tristate::TRUE) {
        return nts::Tristate::TRUE;
    }
    if (pin1 == nts::Tristate::FALSE && pin2 == nts::Tristate::FALSE) {
        return nts::Tristate::FALSE;
    }
    return nts::Tristate::UNDEFINED;
}

nts::XorComponent::XorComponent(std::string name)
    : AComponent(name, 3, std::vector<Pin>{Pin(1, PinType::INPUT, *this), Pin(2, PinType::INPUT, *this), Pin(3, PinType::OUTPUT, *this)})
{
    getPin(1).addNextPin(std::make_shared<nts::Pin>(getPin(3)));
    getPin(3).addPrevPin(std::make_shared<nts::Pin>(getPin(1)));
    getPin(2).addNextPin(std::make_shared<nts::Pin>(getPin(3)));
    getPin(3).addPrevPin(std::make_shared<nts::Pin>(getPin(2)));
}

nts::XorComponent::XorComponent(nts::XorComponent const &other)
    : AComponent(other)
{

}

nts::Tristate nts::XorComponent::compute(std::size_t pin)
{
    if (pin == 1) {
        return getPin(1).computePrev();
    }
    if (pin == 2) {
        return getPin(2).computePrev();
    }
    nts::Tristate pin1 = getPin(1).computePrev();
    nts::Tristate pin2 = getPin(2).computePrev();
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

nts::NotComponent::NotComponent(std::string name)
    : AComponent(name, 2, std::vector<Pin>{Pin(1, PinType::INPUT, *this), Pin(2, PinType::OUTPUT, *this)})
{
    getPin(1).addNextPin(std::make_shared<nts::Pin>(getPin(2)));
    getPin(2).addPrevPin(std::make_shared<nts::Pin>(getPin(1)));
}

nts::NotComponent::NotComponent(nts::NotComponent const &other)
    : AComponent(other)
{

}

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    if (pin == 1) {
        return getPin(1).computePrev();
    }
    nts::Tristate pin1 = getPin(1).computePrev();
    if (pin1 == nts::Tristate::UNDEFINED) {
        return nts::Tristate::UNDEFINED;
    }
    if (pin1 == nts::Tristate::TRUE) {
        return nts::Tristate::FALSE;
    }
    return nts::Tristate::TRUE;
}

/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot [WSL: Ubuntu]
** File description:
** Component4069
*/

#include "Component4069.hpp"

nts::Component4069::Component4069(std::string name)
    : AComponent(name, 14, std::vector<Pin>{
        Pin(1, PinType::INPUT, *this),
        Pin(2, PinType::OUTPUT, *this),
        Pin(3, PinType::INPUT, *this),
        Pin(4, PinType::OUTPUT, *this),
        Pin(5, PinType::INPUT, *this),
        Pin(6, PinType::OUTPUT, *this),
        Pin(7, PinType::OTHER, *this),
        Pin(8, PinType::OUTPUT, *this),
        Pin(9, PinType::INPUT, *this),
        Pin(10, PinType::OUTPUT, *this),
        Pin(11, PinType::INPUT, *this),
        Pin(12, PinType::OUTPUT, *this),
        Pin(13, PinType::INPUT, *this),
        Pin(14, PinType::OTHER, *this)
    }), _nots{NotComponent("not1"), NotComponent("not2"), NotComponent("not3"), NotComponent("not4"), NotComponent("not5"), NotComponent("not6")}
{
    getPin(1).addNextPin(std::make_shared<nts::Pin>(getNot(0).getPin(1)));
    getNot(0).getPin(1).addPrevPin(std::make_shared<nts::Pin>(getPin(1)));
    getPin(2).addPrevPin(std::make_shared<nts::Pin>(getNot(0).getPin(2)));
    getNot(0).getPin(2).addNextPin(std::make_shared<nts::Pin>(getPin(2)));
    getPin(3).addNextPin(std::make_shared<nts::Pin>(getNot(1).getPin(1)));
    getNot(1).getPin(1).addPrevPin(std::make_shared<nts::Pin>(getPin(3)));
    getPin(4).addPrevPin(std::make_shared<nts::Pin>(getNot(1).getPin(2)));
    getNot(1).getPin(2).addNextPin(std::make_shared<nts::Pin>(getPin(4)));
    getPin(5).addNextPin(std::make_shared<nts::Pin>(getNot(2).getPin(1)));
    getNot(2).getPin(1).addPrevPin(std::make_shared<nts::Pin>(getPin(5)));
    getPin(6).addPrevPin(std::make_shared<nts::Pin>(getNot(2).getPin(2)));
    getNot(2).getPin(2).addNextPin(std::make_shared<nts::Pin>(getPin(6)));
    getPin(8).addPrevPin(std::make_shared<nts::Pin>(getNot(3).getPin(2)));
    getNot(3).getPin(2).addNextPin(std::make_shared<nts::Pin>(getPin(8)));
    getPin(9).addNextPin(std::make_shared<nts::Pin>(getNot(3).getPin(1)));
    getNot(3).getPin(1).addPrevPin(std::make_shared<nts::Pin>(getPin(9)));
    getPin(10).addPrevPin(std::make_shared<nts::Pin>(getNot(4).getPin(2)));
    getNot(4).getPin(2).addNextPin(std::make_shared<nts::Pin>(getPin(10)));
    getPin(11).addNextPin(std::make_shared<nts::Pin>(getNot(4).getPin(1)));
    getNot(4).getPin(1).addPrevPin(std::make_shared<nts::Pin>(getPin(11)));
    getPin(12).addPrevPin(std::make_shared<nts::Pin>(getNot(5).getPin(2)));
    getNot(5).getPin(2).addNextPin(std::make_shared<nts::Pin>(getPin(12)));
    getPin(13).addNextPin(std::make_shared<nts::Pin>(getNot(5).getPin(1)));
    getNot(5).getPin(1).addPrevPin(std::make_shared<nts::Pin>(getPin(13)));
}

nts::NotComponent &nts::Component4069::getNot(std::size_t index)
{
    return _nots[index];
}

nts::Tristate nts::Component4069::compute(std::size_t pin)
{
    if (pin == 0 || pin > getNbPins())
        throw std::out_of_range("4069Component: Pin out of range.");
    if (pin == 2) {
        return getNot(0).compute(2);
    }
    if (pin == 4) {
        return getNot(1).compute(2);
    }
    if (pin == 6) {
        return getNot(2).compute(2);
    }
    if (pin == 8) {
        return getNot(3).compute(2);
    }
    if (pin == 10) {
        return getNot(4).compute(2);
    }
    if (pin == 12) {
        return getNot(5).compute(2);
    }
    if (getPin(pin).getType() == PinType::OTHER)
        return nts::UNDEFINED;
    return getPin(pin).computePrev();
}

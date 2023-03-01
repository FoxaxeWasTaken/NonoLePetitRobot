/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot [WSL: Ubuntu]
** File description:
** Component4030
*/

#include "Component4030.hpp"

nts::Component4030::Component4030(std::string name)
    : AComponent(name, 14, std::vector<Pin>{
        Pin(1, PinType::INPUT, *this),
        Pin(2, PinType::INPUT, *this),
        Pin(3, PinType::OUTPUT, *this),
        Pin(4, PinType::OUTPUT, *this),
        Pin(5, PinType::INPUT, *this),
        Pin(6, PinType::INPUT, *this),
        Pin(7, PinType::OTHER, *this),
        Pin(8, PinType::INPUT, *this),
        Pin(9, PinType::INPUT, *this),
        Pin(10, PinType::OUTPUT, *this),
        Pin(11, PinType::OUTPUT, *this),
        Pin(12, PinType::INPUT, *this),
        Pin(13, PinType::INPUT, *this),
        Pin(14, PinType::OTHER, *this)
    }), _xors{XorComponent("xor1"), XorComponent("xor2"), XorComponent("xor3"), XorComponent("xor4")}
{
    getPin(1).addNextPin(std::make_shared<nts::Pin>(getXor(0).getPin(1)));
    getXor(0).getPin(1).addPrevPin(std::make_shared<nts::Pin>(getPin(1)));
    getPin(2).addNextPin(std::make_shared<nts::Pin>(getXor(0).getPin(2)));
    getXor(0).getPin(2).addPrevPin(std::make_shared<nts::Pin>(getPin(2)));
    getPin(3).addPrevPin(std::make_shared<nts::Pin>(getXor(0).getPin(3)));
    getXor(0).getPin(3).addNextPin(std::make_shared<nts::Pin>(getPin(3)));
    getPin(4).addPrevPin(std::make_shared<nts::Pin>(getXor(1).getPin(3)));
    getXor(1).getPin(3).addNextPin(std::make_shared<nts::Pin>(getPin(4)));
    getPin(5).addNextPin(std::make_shared<nts::Pin>(getXor(1).getPin(1)));
    getXor(1).getPin(1).addPrevPin(std::make_shared<nts::Pin>(getPin(5)));
    getPin(6).addNextPin(std::make_shared<nts::Pin>(getXor(1).getPin(2)));
    getXor(1).getPin(2).addPrevPin(std::make_shared<nts::Pin>(getPin(6)));
    getPin(8).addNextPin(std::make_shared<nts::Pin>(getXor(2).getPin(1)));
    getXor(2).getPin(1).addPrevPin(std::make_shared<nts::Pin>(getPin(8)));
    getPin(9).addNextPin(std::make_shared<nts::Pin>(getXor(2).getPin(2)));
    getXor(2).getPin(2).addPrevPin(std::make_shared<nts::Pin>(getPin(9)));
    getPin(10).addPrevPin(std::make_shared<nts::Pin>(getXor(2).getPin(3)));
    getXor(2).getPin(3).addNextPin(std::make_shared<nts::Pin>(getPin(10)));
    getPin(11).addPrevPin(std::make_shared<nts::Pin>(getXor(3).getPin(3)));
    getXor(3).getPin(3).addNextPin(std::make_shared<nts::Pin>(getPin(11)));
    getPin(12).addNextPin(std::make_shared<nts::Pin>(getXor(3).getPin(1)));
    getXor(3).getPin(1).addPrevPin(std::make_shared<nts::Pin>(getPin(12)));
    getPin(13).addNextPin(std::make_shared<nts::Pin>(getXor(3).getPin(2)));
    getXor(3).getPin(2).addPrevPin(std::make_shared<nts::Pin>(getPin(13)));
}

nts::XorComponent &nts::Component4030::getXor(std::size_t index)
{
    return _xors[index];
}

nts::Tristate nts::Component4030::compute(std::size_t pin)
{
    if (pin == 0 || pin > getNbPins())
        throw std::out_of_range("4030Component: Pin out of range.");
    if (pin == 3) {
        return getXor(0).compute(3);
    }
    if (pin == 4) {
        return getXor(1).compute(3);
    }
    if (pin == 10) {
        return getXor(2).compute(3);
    }
    if (pin == 11) {
        return getXor(3).compute(3);
    }
    if (getPin(pin).getType() == PinType::OTHER) {
        return nts::UNDEFINED;
    }
    return getPin(pin).computePrev();
}

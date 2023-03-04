/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot [WSL: Ubuntu]
** File description:
** Component4071
*/

#include "Component4071.hpp"

nts::Component4071::Component4071(std::string name)
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
    }), _ors{OrComponent("xor1"), OrComponent("xor2"), OrComponent("xor3"), OrComponent("xor4")}
{
    getPin(1).addNextPin(std::make_shared<nts::Pin>(getOr(0).getPin(1)));
    getOr(0).getPin(1).addPrevPin(std::make_shared<nts::Pin>(getPin(1)));
    getPin(2).addNextPin(std::make_shared<nts::Pin>(getOr(0).getPin(2)));
    getOr(0).getPin(2).addPrevPin(std::make_shared<nts::Pin>(getPin(2)));
    getPin(3).addPrevPin(std::make_shared<nts::Pin>(getOr(0).getPin(3)));
    getOr(0).getPin(3).addNextPin(std::make_shared<nts::Pin>(getPin(3)));
    getPin(4).addPrevPin(std::make_shared<nts::Pin>(getOr(1).getPin(3)));
    getOr(1).getPin(3).addNextPin(std::make_shared<nts::Pin>(getPin(4)));
    getPin(5).addNextPin(std::make_shared<nts::Pin>(getOr(1).getPin(1)));
    getOr(1).getPin(1).addPrevPin(std::make_shared<nts::Pin>(getPin(5)));
    getPin(6).addNextPin(std::make_shared<nts::Pin>(getOr(1).getPin(2)));
    getOr(1).getPin(2).addPrevPin(std::make_shared<nts::Pin>(getPin(6)));
    getPin(8).addNextPin(std::make_shared<nts::Pin>(getOr(2).getPin(1)));
    getOr(2).getPin(1).addPrevPin(std::make_shared<nts::Pin>(getPin(8)));
    getPin(9).addNextPin(std::make_shared<nts::Pin>(getOr(2).getPin(2)));
    getOr(2).getPin(2).addPrevPin(std::make_shared<nts::Pin>(getPin(9)));
    getPin(10).addPrevPin(std::make_shared<nts::Pin>(getOr(2).getPin(3)));
    getOr(2).getPin(3).addNextPin(std::make_shared<nts::Pin>(getPin(10)));
    getPin(11).addPrevPin(std::make_shared<nts::Pin>(getOr(3).getPin(3)));
    getOr(3).getPin(3).addNextPin(std::make_shared<nts::Pin>(getPin(11)));
    getPin(12).addNextPin(std::make_shared<nts::Pin>(getOr(3).getPin(1)));
    getOr(3).getPin(1).addPrevPin(std::make_shared<nts::Pin>(getPin(12)));
    getPin(13).addNextPin(std::make_shared<nts::Pin>(getOr(3).getPin(2)));
    getOr(3).getPin(2).addPrevPin(std::make_shared<nts::Pin>(getPin(13)));
}

nts::OrComponent &nts::Component4071::getOr(std::size_t index)
{
    return _ors[index];
}

nts::Tristate nts::Component4071::compute(std::size_t pin)
{
    if (pin == 3)
        return getOr(0).compute(3);
    if (pin == 4)
        return getOr(1).compute(3);
    if (pin == 10)
        return getOr(2).compute(3);
    if (pin == 11)
        return getOr(3).compute(3);
    if (getPin(pin).getType() == PinType::OTHER)
        return nts::UNDEFINED;
    return getPin(pin).computePrev();
}

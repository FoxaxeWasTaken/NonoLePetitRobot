/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot [WSL : Ubuntu]
** File description:
** Component4001
*/

#include "Component4001.hpp"

nts::Component4001::Component4001(std::string name)
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
    }), _ors{OrComponent("or1"), OrComponent("or2"), OrComponent("or3"), OrComponent("or4")},
    _nots{NotComponent("not1"), NotComponent("not2"), NotComponent("not3"), NotComponent("not4")}
{
    getPin(1).addNextPin(std::make_shared<Pin>(getOr(0).getPin(1)));
    getOr(0).getPin(1).addPrevPin(std::make_shared<Pin>(getPin(1)));
    getPin(2).addNextPin(std::make_shared<Pin>(getOr(0).getPin(2)));
    getOr(0).getPin(2).addPrevPin(std::make_shared<Pin>(getPin(2)));
    getPin(5).addNextPin(std::make_shared<Pin>(getOr(1).getPin(1)));
    getOr(1).getPin(1).addPrevPin(std::make_shared<Pin>(getPin(5)));
    getPin(6).addNextPin(std::make_shared<Pin>(getOr(1).getPin(2)));
    getOr(1).getPin(2).addPrevPin(std::make_shared<Pin>(getPin(6)));
    getPin(8).addNextPin(std::make_shared<Pin>(getOr(2).getPin(1)));
    getOr(2).getPin(1).addPrevPin(std::make_shared<Pin>(getPin(8)));
    getPin(9).addNextPin(std::make_shared<Pin>(getOr(2).getPin(2)));
    getOr(2).getPin(2).addPrevPin(std::make_shared<Pin>(getPin(9)));
    getPin(12).addNextPin(std::make_shared<Pin>(getOr(3).getPin(1)));
    getOr(3).getPin(1).addPrevPin(std::make_shared<Pin>(getPin(12)));
    getPin(13).addNextPin(std::make_shared<Pin>(getOr(3).getPin(2)));
    getOr(3).getPin(2).addPrevPin(std::make_shared<Pin>(getPin(13)));
    getOr(0).getPin(3).addNextPin(std::make_shared<Pin>(getNot(0).getPin(1)));
    getNot(0).getPin(1).addPrevPin(std::make_shared<Pin>(getOr(0).getPin(3)));
    getOr(1).getPin(3).addNextPin(std::make_shared<Pin>(getNot(1).getPin(1)));
    getNot(1).getPin(1).addPrevPin(std::make_shared<Pin>(getOr(1).getPin(3)));
    getOr(2).getPin(3).addNextPin(std::make_shared<Pin>(getNot(2).getPin(1)));
    getNot(2).getPin(1).addPrevPin(std::make_shared<Pin>(getOr(2).getPin(3)));
    getOr(3).getPin(3).addNextPin(std::make_shared<Pin>(getNot(3).getPin(1)));
    getNot(3).getPin(1).addPrevPin(std::make_shared<Pin>(getOr(3).getPin(3)));
    getNot(0).getPin(2).addNextPin(std::make_shared<Pin>(getPin(3)));
    getPin(3).addPrevPin(std::make_shared<Pin>(getNot(0).getPin(2)));
    getNot(1).getPin(2).addNextPin(std::make_shared<Pin>(getPin(4)));
    getPin(4).addPrevPin(std::make_shared<Pin>(getNot(1).getPin(2)));
    getNot(2).getPin(2).addNextPin(std::make_shared<Pin>(getPin(10)));
    getPin(10).addPrevPin(std::make_shared<Pin>(getNot(2).getPin(2)));
    getNot(3).getPin(2).addNextPin(std::make_shared<Pin>(getPin(11)));
    getPin(11).addPrevPin(std::make_shared<Pin>(getNot(3).getPin(2)));
}

nts::OrComponent &nts::Component4001::getOr(size_t index)
{
    return _ors[index];
}

nts::NotComponent &nts::Component4001::getNot(size_t index)
{
    return _nots[index];
}

nts::Tristate nts::Component4001::compute(std::size_t pin)
{
    if (pin == 3)
        return getNot(0).compute(2);
    if (pin == 4)
        return getNot(1).compute(2);
    if (pin == 10)
        return getNot(2).compute(2);
    if (pin == 11)
        return getNot(3).compute(2);
    if (getPin(pin).getType() == PinType::OTHER)
        return nts::UNDEFINED;
    return getPin(pin).computePrev();
}

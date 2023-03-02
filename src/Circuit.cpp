/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot [WSL: Ubuntu]
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include "SpecialComponent.hpp"
#include <iostream>
#include <stdexcept>

nts::Circuit::Circuit()
    : _tick(0)
{

}

void nts::Circuit::addComponent(std::unique_ptr<nts::IComponent> component)
{
    _components.push_back(std::move(component));
}

void nts::Circuit::setLink(std::string const &name1, std::size_t pin1, std::string const &name2, std::size_t pin2)
{
    nts::IComponent &component1 = *getComponent(name1);
    nts::IComponent &component2 = *getComponent(name2);

    component1.setLink(pin1, component2, pin2);
}

void nts::Circuit::simulate(std::size_t tick)
{
    addTick(tick);
    for (auto &component : _components) {
        component->simulate(_tick);
    }
    for (auto &component : _components) {
        for (std::size_t i = 1; i <= component->getNbPins(); i++) {
            component->getPin(i).setValue(component->compute(i));
        }
    }
}

std::unique_ptr<nts::IComponent> &nts::Circuit::getComponent(std::string const &name)
{
    for (auto &component : _components) {
        if (component->getName() == name)
            return component;
    }
    throw std::runtime_error("Component not found");
}

void nts::Circuit::addTick(std::size_t tick)
{
    _tick += tick;
}

void nts::Circuit::display()
{
    std::cout << "tick: " << _tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto &component : _components) {
        if (dynamic_cast<nts::InputComponent *>(component.get()) || dynamic_cast<nts::ClockComponent *>(component.get())) {
            std::cout << component->getName() << ": " << component->getPin(1).getValue() << std::endl;
        }
    }
    std::cout << "output(s):" << std::endl;
    for (auto &component : _components) {
        if (dynamic_cast<nts::OutputComponent *>(component.get())) {
            std::cout << component->getName() << ": " << component->getPin(1).getValue() << std::endl;
        }
    }
}

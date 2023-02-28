/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot [WSL: Ubuntu]
** File description:
** ComponentFactory
*/

#include "ComponentFactory.hpp"
#include <stdexcept>

nts::ComponentFactory::ComponentFactory()
{

}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createComponent(std::string const &type, std::string const &name)
{
    if (_componentMap.find(type) == _componentMap.end())
        throw std::runtime_error("ComponentFactory: Unknown component type");
    return _componentMap[type](name);
}

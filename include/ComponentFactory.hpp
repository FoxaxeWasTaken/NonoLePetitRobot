/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot [WSL: Ubuntu]
** File description:
** ComponentFactory
*/

#pragma once

#include "SpecialComponent.hpp"
#include "ElementaryComponent.hpp"
#include "Component4030.hpp"
#include "Component4069.hpp"
#include "Component4071.hpp"
#include "Component4081.hpp"
#include "Component4001.hpp"
#include <functional>
#include <map>

namespace nts {
    class ComponentFactory {
        public:
            ComponentFactory();
            ~ComponentFactory() = default;

            std::unique_ptr<nts::IComponent> createComponent(std::string const &type, std::string const &name);

        private:
            std::map<std::string, std::function<std::unique_ptr<nts::IComponent>(std::string const &)>> _componentMap = {
                {"input", [](std::string const &name) { return std::make_unique<nts::InputComponent>(name); }},
                {"output", [](std::string const &name) { return std::make_unique<nts::OutputComponent>(name); }},
                {"clock", [](std::string const &name) { return std::make_unique<nts::ClockComponent>(name); }},
                {"true", [](std::string const &name) { return std::make_unique<nts::TrueComponent>(name); }},
                {"false", [](std::string const &name) { return std::make_unique<nts::FalseComponent>(name); }},
                {"and", [](std::string const &name) { return std::make_unique<nts::AndComponent>(name); }},
                {"or", [](std::string const &name) { return std::make_unique<nts::OrComponent>(name); }},
                {"xor", [](std::string const &name) { return std::make_unique<nts::XorComponent>(name); }},
                {"not", [](std::string const &name) { return std::make_unique<nts::NotComponent>(name); }},
                {"4030", [](std::string const &name) { return std::make_unique<nts::Component4030>(name); }},
                {"4069", [](std::string const &name) { return std::make_unique<nts::Component4069>(name); }},
                {"4071", [](std::string const &name) { return std::make_unique<nts::Component4071>(name); }},
                {"4081", [](std::string const &name) { return std::make_unique<nts::Component4081>(name); }},
                {"4001", [](std::string const &name) { return std::make_unique<nts::Component4001>(name); }},
            };
    };
}

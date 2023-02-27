/*
** EPITECH PROJECT, 2023
** BSNanoTekSpice [WSL: Ubuntu]
** File description:
** main
*/

#include "SpecialComponent.hpp"
#include "ElementaryComponent.hpp"
#include <iostream>

int main(void)
{
    std::unique_ptr<nts::IComponent> gate = std::make_unique<nts::AndComponent>("gate");
    std::unique_ptr<nts::IComponent> input1 = std::make_unique<nts::FalseComponent>("input1");
    std::unique_ptr<nts::IComponent> input2 = std::make_unique<nts::TrueComponent>("input2");
    std::unique_ptr<nts::IComponent> inverter = std::make_unique<nts::NotComponent>("inverter");
    std::cout << gate->getPin(1).getType() << std::endl;
    std::cout << input1->getPin(1).getType() << std::endl;
    gate->setLink(1, *input1, 1);
    gate->setLink(2, *input2, 1);
    inverter->setLink(1, *gate, 3);
    std::cout << "!(" << input1->compute(1) << " && " << input2->compute(1) << ") -> " << inverter->compute(2) << std::endl;
    return 0;
    // nts::AndComponent gate;
    // nts::FalseComponent input1;
    // nts::TrueComponent input2;
    // nts::NotComponent inverter;
    // gate.setLink(1, input1, 1);
    // gate.setLink(2, input2, 1);
    // inverter.setLink(1, gate, 3);
    // std::cout << "!(" << input1.compute(1) << " && " << input2.compute(1) << ") -> " << inverter.compute(2) << std::endl;
    // return 0;
}

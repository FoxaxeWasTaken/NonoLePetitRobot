/*
** EPITECH PROJECT, 2023
** BSNanoTekSpice [WSL: Ubuntu]
** File description:
** main
*/

#include "ComponentFactory.hpp"
#include "Circuit.hpp"
#include "Parser.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
        return 84;
    // std::unique_ptr<nts::IComponent> gate = std::make_unique<nts::OrComponent>("gate");
    // std::unique_ptr<nts::IComponent> input1 = std::make_unique<nts::FalseComponent>("input1");
    // std::unique_ptr<nts::IComponent> input2 = std::make_unique<nts::TrueComponent>("input2");
    // std::unique_ptr<nts::IComponent> inverter = std::make_unique<nts::NotComponent>("inverter");
    // std::cout << gate->getPin(1).getType() << std::endl;
    // std::cout << input1->getPin(1).getType() << std::endl;
    // gate->setLink(1, *input1, 1);
    // gate->setLink(2, *input2, 1);
    // inverter->setLink(1, *gate, 3);
    // std::cout << "!(" << input1->compute(1) << " || " << input2->compute(1) << ") -> " << inverter->compute(2) << std::endl;
    // return 0;
    //nts::Circuit circuit;
    //nts::ComponentFactory factory;
    Parser parser(argv[1]);
    parser.parse_the_file();
    parser.delete_comment();
    parser.check_if_good_order();
    parser.set_chipset_lines();
    parser.set_links_lines();
    std::unique_ptr<nts::Circuit> circuit = parser.create_circuit(parser.get_chipset_lines());
    circuit->display();
    // tkt pout les cast c'est juste pour modifier les valeurs des inputs (faudra faire ca dans le shell)
    static_cast<nts::InputComponent *>(circuit->getComponent("in_1").get())->setBuf(true);
    static_cast<nts::InputComponent *>(circuit->getComponent("in_1").get())->setBufVal(nts::FALSE);
    static_cast<nts::InputComponent *>(circuit->getComponent("in_2").get())->setBuf(true);
    static_cast<nts::InputComponent *>(circuit->getComponent("in_2").get())->setBufVal(nts::TRUE);
    circuit->simulate(1);
    circuit->display();
    //circuit.addComponent(factory.createComponent("input", "input1"));
    //circuit.addComponent(factory.createComponent("clock", "clock"));
    //circuit.addComponent(factory.createComponent("output", "output"));
    //circuit.addComponent(factory.createComponent("and", "gate"));
    //circuit.addComponent(factory.createComponent("not", "inverter"));
    //static_cast<nts::InputComponent *>(circuit.getComponent("input1").get())->setBuf(true);
    //static_cast<nts::ClockComponent *>(circuit.getComponent("clock").get())->setBuf(true);
    //static_cast<nts::InputComponent *>(circuit.getComponent("input1").get())->setBufVal(nts::FALSE);
    //static_cast<nts::ClockComponent *>(circuit.getComponent("clock").get())->setBufVal(nts::TRUE);

    //circuit.setLink("input1", 1, "gate", 1);
    //circuit.setLink("clock", 1, "gate", 2);
    //circuit.setLink("gate", 3, "inverter", 1);
    //circuit.setLink("inverter", 2, "output", 1);
    //circuit.display();
    //std::cout << std::endl;
    //circuit.simulate(1);
    //circuit.display();
    //std::cout << std::endl;
    //circuit.simulate(1);
    //circuit.display();
    return 0;
}

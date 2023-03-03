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
#include "Global_loop.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return 84;
    Parser parser(argv[1]);
    parser.parse_the_file();
    parser.delete_comment();
    if (!(parser.check_if_good_order()))
        exit(84);
    parser.delete_unwanted_trailing_space();
    parser.set_chipset_lines();
    parser.set_links_lines();
    std::shared_ptr<nts::Circuit> circuit = parser.create_circuit(parser.get_chipset_lines());
    global_loop(circuit);
    //circuit->display();
    //circuit->simulate(1);
    //circuit->display();
    return 0;
}

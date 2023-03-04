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
    parser.check_path();
    parser.parse_the_file();
    parser.delete_comment();
    parser.delete_unwanted_trailing_space();
    parser.delete_empty_lines();
    if (parser.check_if_good_order() == false)
        exit(84);
    parser.set_chipset_lines();
    parser.print_all_lines(parser.get_chipset_lines());
    std::cout << "----------------------------" <<std::endl;
    parser.set_links_lines();
    parser.print_all_lines(parser.get_links_lines());
    std::shared_ptr<nts::Circuit> circuit = parser.create_circuit(parser.get_chipset_lines());
    Global_loop main_loop(circuit);
    main_loop.global_loop();
    return 0;
}

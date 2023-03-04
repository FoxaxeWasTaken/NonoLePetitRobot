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
    std::shared_ptr<nts::Circuit> circuit;
    Parser parser(argv[1]);
    try {
        parser.check_path();
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    try {
        parser.parse_the_file();
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    parser.delete_comment();
    parser.transform_tab_into_space();
    parser.delete_unwanted_trailing_space();
    parser.delete_empty_lines();
    try {
        parser.count_chipset_and_link();
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    try {
        parser.check_if_good_order();
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    parser.set_chipset_lines();
    try {
    parser.set_links_lines();
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    try {
    circuit = parser.create_circuit(parser.get_chipset_lines());
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    } catch (std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    Global_loop main_loop(circuit);
    main_loop.global_loop();
    return 0;
}

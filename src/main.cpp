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
    nts::Parser parser(argv[1]);
    if (!parser.load_file())
        return 84;
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
    nts::Global_loop main_loop(circuit);
    main_loop.global_loop();
    return 0;
}

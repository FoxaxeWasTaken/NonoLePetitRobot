/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot
** File description:
** Parser
*/

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Chipset.hpp"
#include "Link.hpp"
#include "Circuit.hpp"

class Parser {
    enum {
        INPUT,
        OUTPUT
    };

    public:
        Parser(std::string path);
        ~Parser();
        void parse_the_file();
        void check_path();
        void delete_comment();
        void delete_empty_lines();
        std::vector<std::string> get_all_file();
        std::vector<std::string> get_all_lines(){return _all_lines;};
        std::vector<std::string> get_chipset_lines(){return _chipset_lines;};
        std::vector<std::string> get_links_lines(){return _links_lines;};
        std::vector<Chipset> get_chipsets(){return chipsets;};
        std::vector<Link> get_links(){return _link_vector;};

        void delete_unwanted_trailing_space();
        bool check_file_is_ok(){return _file_is_ok;};
        bool check_chipset_type(std::string type);
        bool check_if_good_order();

        std::unique_ptr<nts::Circuit> create_circuit(std::vector<std::string> _all_chipset);
        std::string name_component(std::string lines);
        void print_all_lines(std::vector<std::string> lines);
        std::string type_component(std::string lines);

        void set_chipset_lines();
        void set_links_lines();
        void recup_chipsets();

        //void create_all_pins();
        //void create_all_links();

    private:
        std::string _path;
        std::vector<std::string> _all_file;
        std::vector<std::string> _all_lines;
        std::vector<std::string> _chipset_lines;
        std::vector<std::string> _links_lines;
        std::vector<std::string> _all_chipset;
        std::vector<Chipset> chipsets;

        bool _file_is_ok = true;
        bool _chipset_first = false;
        std::vector<Link> _link_vector;
};
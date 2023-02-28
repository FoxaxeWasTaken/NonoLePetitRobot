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
//#include "APin.hpp"



class Parser {
    enum {
        INPUT,
        OUTPUT
    };

    public:
        Parser(std::string path);
        ~Parser();
        void parse_the_file();
        void delete_comment();
        std::vector<std::string> get_all_file();
        std::vector<std::string> get_all_lines(){return _all_lines;};
        std::vector<std::string> get_chipset_lines(){return _chipset_lines;};
        std::vector<std::string> get_links_lines(){return _links_lines;};
        std::vector<Chipset> get_chipsets(){return chipsets;};

        bool check_file_is_ok(){return _file_is_ok;};
        bool check_chipset_type(std::string type);
        //TODOajout d'une fonction de check du nom de chaque component/pin etc
        void print_all_lines(std::vector<std::string> lines);
        void check_if_good_order();
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
        //std::vector<nts::APin> _all_pins;
};
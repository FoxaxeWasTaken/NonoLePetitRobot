/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot
** File description:
** Parser
*/

#include <stdio.h>
#include "Parser.hpp"
#include "ComponentFactory.hpp"
#include "Circuit.hpp"

Parser::Parser(std::string path)
    : _path(path)
{
};

Parser::~Parser()
{
};

std::vector<std::string> Parser::get_all_file()
{
    return _all_file;
};

void Parser::parse_the_file()
{
    std::string line;
    std::ifstream file(_path);

    if (file.is_open()) {
        while (getline(file, line))
            _all_file.push_back(line);
        file.close();
    } else
        std::cout << "Unable to open file" << std::endl;
}

void Parser::print_all_lines(std::vector<std::string> lines)
{
    for (auto it = lines.begin(); it != lines.end(); it++)
        std::cout << *it << '\n';
};


void Parser::delete_comment()
{
    size_t pos = 0;

    for (auto it = _all_file.begin(); it != _all_file.end(); it++) {
        pos = (*it).find('#');
        if (pos != std::string::npos) {
            (*it).erase(pos, (*it).length());
            _all_lines.push_back(*it);
        } else
            _all_lines.push_back(*it);
    }

};

void Parser::check_if_good_order()
{
    for (auto it = _all_lines.begin(); it != _all_lines.end(); it++) {
        if ((*it).compare(".chipsets:") == 0)
            this->_chipset_first = true;
        if ((*it).compare(".links:") == 0 && this->_chipset_first == true) {
            this->_file_is_ok = true;
            return;
        }
    }
    this->_file_is_ok = false;
    std::cerr << "Error in file: missing instruction or bad order" << std::endl;
}

void Parser::set_chipset_lines()
{
    for (auto it = _all_lines.begin(); it != _all_lines.end(); it++) {
        if ((*it).compare(".chipsets:") == 0) {
            it++;
            while ((*it).compare(".links:") != 0) {
                if ((*it).compare("\0") == 0)
                    return;
                else {
                    _chipset_lines.push_back(*it);
                    it++;
                }
            }
        }
    }
}

bool Parser::check_chipset_type(std::string type)
{
    if (type.size() != 4)
        return false;
    for (auto it = type.begin(); it != type.end(); it++) {
        if (!isdigit(*it))
            return false;
    }
    return true;
}

void Parser::set_links_lines()
{
    for (auto it = _all_lines.begin(); it != _all_lines.end(); it++) {
        if ((*it).compare(".links:") == 0) {
            it++;
            while (it != _all_lines.end()) {
                Link link((*it));
                link.set_component_1();
                link.set_pin_1();
                link.set_component_2();
                link.set_pin_2();
                _links_lines.push_back(*it);
                _link_vector.push_back(link);
                it++;
            }
            return;
        }
    }
}

std::string Parser::name_component(std::string lines)
{
    std::string name;
    std::string delimiter = " ";
    size_t pos = 0;

    pos = lines.find(delimiter);
    name = lines.substr(pos + 1);
    return name;
}

std::string Parser::type_component(std::string lines)
{
    std::string type;
    std::string delimiter = " ";
    size_t pos = 0;

    pos = lines.find(delimiter);
    type = lines.substr(0, pos);
    return type;
}


void Parser::create_circuit(std::vector<std::string> _all_chipset, std::vector<std::string> _links_lines)
{
    nts::Circuit circuit;
    nts::ComponentFactory factory;

    for (auto it = _all_chipset.begin(); it != _all_chipset.end(); it++) {
        circuit.addComponent(factory.createComponent(type_component(*it), name_component(*it)));
        //std::cout << type_component(*it) << std::endl;
        //std::cout << circuit.getComponent(name_component(*it))->getName() << std::endl;
        //std::cout << "name = " << name_component(*it) << std::endl;
        //std::cout << circuit.getComponent(name_component(*it))->getName() << std::endl;
        //std::cout << "name = " << name_component(*it) << std::endl;
        //std::cout << "type = " << type_component(*it) << std::endl;
    }

    //for (auto ti = _links_lines.begin(); ti != _links_lines.end(); ti++) {
        auto ti = _links_lines.begin();
        auto test = _link_vector.begin();
        //std::cout << test->get_component_1() << std::endl;
        std::cout << "comp 1 = " << test->get_component_1() << std::endl;
        std::cout << "comp 2 = " << test->get_component_2() << std::endl;
        std::cout << "pin 1 = " << test->get_pin_1() << std::endl;
        std::cout << "pin 2 = " << test->get_pin_2() << std::endl;
        circuit.setLink(test->get_component_1(), test->get_pin_1(), test->get_component_2(), test->get_pin_2());
        test++;
        ti++;
    //}

}

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

void Parser::delete_unwanted_trailing_space()
{
    for (auto it = _all_lines.begin(); it != _all_lines.end(); it++) {
        if ((*it).find(' ') != std::string::npos) {
            for (int i = 0; (*it).data()[i] != '\0'; i++ ) {
                if ((*it).data()[i] != ' ')
                    continue;
                else {
                    if (((*it).data()[i] == ' ' && ((*it).data()[i + 1]) == ' ') || (*it).data()[0] == ' ') {
                        (*it).erase(i, 1);
                        i--;
                    }
                }
            }
        }
    }
}

bool Parser::check_if_good_order()
{
    for (auto it = _all_lines.begin(); it != _all_lines.end(); it++) {
        if ((*it).compare(".chipsets:") == 0)
            this->_chipset_first = true;
        if ((*it).compare(".links:") == 0 && this->_chipset_first == true) {
            this->_file_is_ok = true;
            return this->_file_is_ok;
        }
    }
    std::cerr << "Error in file: missing instruction or bad order" << std::endl;
    return (this->_file_is_ok = false);
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

std::unique_ptr<nts::Circuit> Parser::create_circuit(std::vector<std::string> _all_chipset)
{
    std::unique_ptr<nts::Circuit> circuit = std::make_unique<nts::Circuit>();
    nts::ComponentFactory factory;

    for (auto it = _all_chipset.begin(); it != _all_chipset.end(); it++) {
        circuit->addComponent(factory.createComponent(type_component(*it), name_component(*it)));
    }
    for (auto it = _link_vector.begin(); it != _link_vector.end(); it++) {
        circuit->setLink(it->get_component_1(), it->get_pin_1(), it->get_component_2(), it->get_pin_2());
    }
    return circuit;
}

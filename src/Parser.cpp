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

nts::Parser::Parser(std::string path)
    : _path(path)
{
};

nts::Parser::~Parser()
{
};

void nts::Parser::check_path()
{
    if (_path.find(".nts") == std::string::npos) {
        throw std::invalid_argument("checkPath: file is not a .nts");
    }
    size_t pos = _path.find(".nts");
    if ((pos + 4) != _path.length()) {
        throw std::invalid_argument("checkPath: file is not a .nts");
    }
}

bool nts::Parser::load_file()
{
    try {
        check_path();
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    try {
        parse_the_file();
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    delete_comment();
    transform_tab_into_space();
    delete_unwanted_trailing_space();
    delete_empty_lines();
    try {
        count_chipset_and_link();
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    try {
        check_if_good_order();
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    set_chipset_lines();
    try {
    set_links_lines();
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    return true;
}

std::vector<std::string> nts::Parser::get_all_file()
{
    return _all_file;
};

void nts::Parser::parse_the_file()
{
    std::string line;
    std::ifstream file(_path);

    if (file.is_open()) {
        while (getline(file, line))
            _all_file.push_back(line);
        file.close();
    } else {
        throw std::runtime_error("getAllFiles: file could not be opened");
    }
}

void nts::Parser::print_all_lines(std::vector<std::string> lines)
{
    for (auto it = lines.begin(); it != lines.end(); it++)
        std::cout << *it << '\n';
};


void nts::Parser::delete_comment()
{
    size_t pos = 0;

    for (auto it = _all_file.begin(); it != _all_file.end(); it++) {
        pos = (*it).find('#');
        if (pos != std::string::npos) {
            (*it).erase(pos, (*it).length());
            if (!it->empty())
                _all_lines.push_back(*it);
        } else
            _all_lines.push_back(*it);
    }

};

void nts::Parser::delete_unwanted_trailing_space()
{
    for (auto it = _all_lines.begin(); it != _all_lines.end(); it++) {
        if ((*it).find(' ') != std::string::npos) {
            for (size_t i = 0; (*it).data()[i] != '\0'; i++ ) {
                if (((*it).data()[i] == ' ' && ((*it).data()[i + 1]) == ' ') || (*it).data()[0] == ' ') {
                    (*it).erase(i, 1);
                    i--;
                }
                if (i == it->length() - 1 && it->data()[i] == ' ')
                    (*it).erase(i, 1);
            }
        }
    }
}

void nts::Parser::transform_tab_into_space()
{
    for (auto it = _all_lines.begin(); it != _all_lines.end(); it++) {
        for (size_t i = 0; (*it).data()[i] != '\0'; i++ ) {
            if ((*it).data()[i] != '\t')
                continue;
            else
                (*it).replace(i, 1, " ");
        }
    }
}

void nts::Parser::delete_empty_lines()
{
    for (auto it = _all_lines.begin(); it != _all_lines.end(); it++) {
        if ((*it).empty()) {
            _all_lines.erase(it);
            it--;
        }
    }
}

void nts::Parser::check_if_good_order()
{
    bool chipset = false;

    for (auto it = _all_lines.begin(); it != _all_lines.end(); it++) {
        if ((*it).compare(".chipsets:") == 0)
            chipset = true;
        if ((*it).compare(".links:") == 0 && chipset) {
            return;
        }
    }
    throw std::invalid_argument("file is not in the good order");
}

void nts::Parser::set_chipset_lines()
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

bool nts::Parser::check_chipset_type(std::string type)
{
    if (type.size() != 4)
        return false;
    for (auto it = type.begin(); it != type.end(); it++) {
        if (!isdigit(*it))
            return false;
    }
    return true;
}

void nts::Parser::set_links_lines()
{
    for (auto it = _all_lines.begin(); it != _all_lines.end(); it++) {
        if ((*it).compare(".links:") == 0) {
            it++;
            while (it != _all_lines.end()) {
                nts::Link link((*it));
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

void nts::Parser::count_chipset_and_link()
{
    int chip = 0;
    int link = 0;

    for (auto it = _all_lines.begin(); it != _all_lines.end(); it++) {
        if (it->compare(".chipsets:") == 0)
            chip++;
        if (it->compare(".links:") == 0)
            link++;
    }
    if (chip != 1 || link != 1)
        throw std::invalid_argument("countChipsetAndLink: too many or too few chipset or link");

}

std::string nts::Parser::name_component(std::string lines)
{
    std::string name;
    std::string delimiter = " ";
    size_t pos = 0;

    pos = lines.find(delimiter);
    name = lines.substr(pos + 1);
    pos = name.find(' ');
    if (pos != std::string::npos)
        name.erase(pos, 1);
    return name;
}

std::string nts::Parser::type_component(std::string lines)
{
    std::string type;
    std::string delimiter = " ";
    size_t pos = 0;

    pos = lines.find(delimiter);
    type = lines.substr(0, pos);
    return type;
}

std::unique_ptr<nts::Circuit> nts::Parser::create_circuit(std::vector<std::string> _all_chipset)
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

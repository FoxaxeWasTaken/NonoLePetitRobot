/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot
** File description:
** Parser
*/

#include <stdio.h>
#include "Parser.hpp"

Parser::Parser(std::string path) : _path(path)
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
    for (auto it = _all_file.begin(); it != _all_file.end(); it++) {
        if ((*it).find_first_of("#") != 0 ){
            _all_lines.push_back(*it);
        }
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
                _chipset_lines.push_back(*it);
                it++;
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

void Parser::recup_chipsets()
{
    std::string name;
    std::string type;
    std::string line;
    std::string delimiter = " ";
    size_t pos = 0;

    for (auto it = _chipset_lines.begin(); it != _chipset_lines.end(); it++) {
        line = *it;
        if (isdigit((*it).data()[0])) {
            while ((pos = line.find(delimiter)) != std::string::npos) {
                type = line.substr(0, pos);
                std::cout << type << std::endl;
                line.erase(0, pos + delimiter.length());
            }
            name = line;
            if (check_chipset_type(type))
                chipsets.push_back(Chipset(name, type));
            else
                std::cerr << "Error in file: bad chipset type" << std::endl;
        }
    }
}

void Parser::set_links_lines()
{
    for (auto it = _all_lines.begin(); it != _all_lines.end(); it++) {
        if ((*it).compare(".links:") == 0) {
            it++;
            while (it != _all_lines.end()) {
                _links_lines.push_back(*it);
                it++;
            }
            return;
        }
    }
}

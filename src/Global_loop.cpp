/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot
** File description:
** Global_loop
*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>
#include "Link.hpp"
#include <strings.h>
#include "Circuit.hpp"
#include "Global_loop.hpp"
#include <signal.h>

volatile int ctrInt = 0;

void sigint_handler(int sig)
{
    (void)sig;
    ctrInt = 1;
}

void global_loop(std::shared_ptr<nts::Circuit> circuit)
{
    std::string input;
    std::cout << "> ";

    while (std::getline(std::cin, input)) {
        ctrInt = 0;
        if (input == "exit")
            exit(0);
        if (input == "simulate")
            circuit->simulate(1);
        if (input == "display")
            circuit->display();
        if (input == "loop") {
            signal(SIGINT, &sigint_handler);
            while (ctrInt == 0) {
                circuit->simulate(1);
                circuit->display();
            }
        }

        std::cout << "> ";
    }
}
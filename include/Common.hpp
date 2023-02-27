/*
** EPITECH PROJECT, 2023
** NonoLePetitRobot [WSL: Ubuntu]
** File description:
** Common
*/

#pragma once

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    enum PinType {
        INPUT,
        OUTPUT,
        OTHER
    };
}

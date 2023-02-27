/*
** EPITECH PROJECT, 2023
** BSNanoTekSpice [WSL : Ubuntu]
** File description:
** Pin
*/

#pragma once

#include "IComponent.hpp"
#include "Common.hpp"
namespace nts {
    class IComponent;

    class Pin {
        public:
            Pin(std::size_t idxPin, PinType type, IComponent &component);
            Pin(Pin const &other);
            ~Pin() = default;

            std::size_t getIdxPin() const;
            void setValue(nts::Tristate value);
            nts::Tristate getValue() const;
            PinType getType() const;
            IComponent &getComponent();
            std::vector<std::shared_ptr<Pin>> getNextPins() const;
            std::shared_ptr<Pin> getNextPin(size_t index) const;
            void addNextPin(std::shared_ptr<Pin> nextPins);
            std::vector<std::shared_ptr<Pin>> getPrevPins() const;
            std::shared_ptr<Pin> getPrevPin(size_t index) const;
            void addPrevPin(std::shared_ptr<Pin> prevPins);
            nts::Tristate computePrev() const;
            std::size_t getNbPrevPins() const;
            std::size_t getNbNextPins() const;

        private:
            std::size_t _idxPin;
            nts::Tristate _value;
            PinType _type;
            IComponent &_component;
            std::vector<std::shared_ptr<Pin>> _nextPins;
            std::vector<std::shared_ptr<Pin>> _prevPins;
    };
}
    // class InputPin : public APin {
    //     public:
    //         InputPin(std::size_t nbPin, IComponent *component);
    //         InputPin(InputPin const &other);
    //         ~InputPin() override = default;

    //         std::shared_ptr<APin> getPrevPin() const;
    //         void setPrevPin(std::shared_ptr<APin> prevPin);
    //         std::shared_ptr<APin> getNextPin() const;
    //         void setNextPin(std::shared_ptr<APin> nextPin);
    //         nts::Tristate computePrev() const;

    //     private:
    //         std::shared_ptr<APin> _prevPin;
    //         std::shared_ptr<APin> _nextPin;
    // };

    // class OutputPin : public APin {
    //     public:
    //         OutputPin(std::size_t nbPin, IComponent *component);
    //         OutputPin(OutputPin const &other);
    //         ~OutputPin() override = default;

    //         std::vector<std::shared_ptr<APin>> getNextPins() const;
    //         std::shared_ptr<APin> getNextPin(size_t index) const;
    //         void setNextPin(std::shared_ptr<APin> nextPins);
    //         std::vector<std::shared_ptr<APin>> getPrevPins() const;
    //         std::shared_ptr<APin> getPrevPin(size_t index) const;
    //         void setPrevPin(std::shared_ptr<APin> prevPins);

    //     private:
    //         std::vector<std::shared_ptr<APin>> _nextPins;
    //         std::vector<std::shared_ptr<APin>> _prevPins;
    // };

    // class OtherPin : public APin {
    //     public:
    //         OtherPin(std::size_t nbPin, IComponent *component);
    //         OtherPin(OtherPin const &other);
    //         ~OtherPin() override = default;
    // };

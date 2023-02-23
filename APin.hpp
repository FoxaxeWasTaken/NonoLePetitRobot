/*
** EPITECH PROJECT, 2023
** BSNanoTekSpice [WSL : Ubuntu]
** File description:
** APin
*/

#include "IComponent.hpp"

namespace nts {
    class APin {
        public:
            APin() = delete;
            virtual ~APin() = default;

            std::size_t getIdxPin() const;
            void setValue(nts::Tristate value);
            nts::Tristate getValue() const;
            IComponent *getComponent() const;

        protected:
            APin(std::size_t nbPin, IComponent *component);

        private:
            std::size_t _idxPin;
            nts::Tristate _value;
            IComponent *_component;
    };
}

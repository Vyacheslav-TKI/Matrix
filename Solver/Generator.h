#pragma once

namespace miit::data::generators
{
    template <typename T>
    class Generator
    {
    public:
        /**
         * @brief ¬иртуальный деструктор
         */
        virtual ~Generator() = default;

        /**
         * @brief ¬иртуальный метод генерировани¤
         * @return —генерированное значение типа T
         */
        virtual T generate() = 0;
    };
}

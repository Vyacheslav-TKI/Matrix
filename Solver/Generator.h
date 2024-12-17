#pragma once

namespace matrixx
{
    template <typename T>
    /**
     * @brief абстрактный класс Generator представл¤ет генератор значений.
     * @tparam T “тип данных, которые будет генерировать класс-наследник.
     */
    class Generator {
    public:
        /**
        * @brief виртуальный деструктор
         */
        virtual ~Generator() = default;

        /**
         * @brief „чисто виртуальна¤ функци¤ для генерации значения типа T
         * @return T —генерированное значение типа T.
         */
        virtual T generate() = 0;
    };
}
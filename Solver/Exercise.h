#pragma once

namespace matrixx
{
    template <typename T>
    /**
     * @brief јбстрактный класс Generator представл¤ет генератор значений.
     * @tparam T “ип данных, которые будет генерировать класс-наследник.
     */
    class Generator {
    public:
        /**
        * @brief ¬иртуальный деструктор
         */
        virtual ~Generator() = default;

        /**
         * @brief „исто виртуальна¤ функци¤ дл¤ генерации значени¤ типа T
         * @return T —генерированное значение типа T.
         */
        virtual T generate() = 0;
    };
}
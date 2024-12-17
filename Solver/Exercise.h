#pragma once

namespace matrixx
{
    template <typename T>
    /**
     * @brief абстрактный класс Generator представляет генератор значений.
     * @tparam T тип данных, которые будет генерировать класс-наследник.
     */
    class Generator {
    public:
        /**
        * @brief виртуальный деструктор
         */
        virtual ~Generator() = default;

        /**
         * @brief чисто виртуальна¤ функция для генерации значения типа T
         * @return T сгенерированное значение типа T.
         */
        virtual T generate() = 0;
    };
}
#pragma once

namespace matrixx
{
    template <typename T>
    /**
     * @brief ����������� ����� Generator ������������ ��������� ��������.
     * @tparam T ��� ������, ������� ����� ������������ �����-���������.
     */
    class Generator {
    public:
        /**
        * @brief ����������� ����������
         */
        virtual ~Generator() = default;

        /**
         * @brief ����� ����������� ������� ��� ��������� �������� ���� T
         * @return T ��������������� �������� ���� T.
         */
        virtual T generate() = 0;
    };
}
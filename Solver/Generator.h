#pragma once

namespace miit::data::generators
{
    template <typename T>
    class Generator
    {
    public:
        virtual ~Generator() = default;

        virtual T generate() = 0;
    };
}

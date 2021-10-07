#pragma once
#include <vector>
#include <stdexcept>

namespace Containers
{
    template <typename T>
    class Matrix
    {
        std::vector<T> _inner;
        unsigned int _dimx, _dimy;

    public:
        Matrix()
        {
            _dimx = 0;
            _dimy = 0;
            _inner.resize(_dimx * _dimy);
        }

        Matrix(unsigned int dimx, unsigned int dimy, std::vector<T> inputMatrix)
            : _dimx(dimx), _dimy(dimy)
        {
            _inner = inputMatrix;
        }

        T& operator()(unsigned int x, unsigned int y)
        {
            if (x >= _dimx || y >= _dimy)
                throw std::out_of_range("matrix indices out of range");
            return _inner[_dimx * y + x];
        }

        Matrix* operator=(Matrix<int> inputMatrix)
        {
            _dimx = inputMatrix._dimx;
            _dimy = inputMatrix._dimy;
            _inner = inputMatrix._inner;
            return this;
        }
    };
}
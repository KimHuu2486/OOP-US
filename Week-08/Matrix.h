#pragma once
#include <algorithm>
#include <stdexcept>

template <class T>
class Matrix
{
private:
    T *m_matrix;
    int m_rows;
    int m_cols;

private:
    class Row
    {
    private:
        T *m_row;
        int m_col;

    public:
        Row(T *row, int col)
        {
            m_row = row;
            m_col = col;
        }
        T &operator[](int col)
        {
            if (col < 0 || col >= m_col)
            {
                throw std::out_of_range("out_of_range");
            }
            return m_row[col];
        }
    };

public:
    Matrix() : m_matrix(nullptr), m_rows(0), m_cols(0) {};

    Matrix(const int &r, const int &c) : Matrix()
    {
        if (r <= 0 || c <= 0)
        {
            return;
        }

        m_rows = r;
        m_cols = c;
        m_matrix = new T[m_rows * m_cols]();
    }

    Matrix(const Matrix &matrix)
        : m_matrix(nullptr), m_rows(matrix.m_rows), m_cols(matrix.m_cols)
    {
        if (m_rows > 0 && m_cols > 0 && matrix.m_matrix != nullptr)
        {
            m_matrix = new T[m_rows * m_cols];
            std::copy(matrix.m_matrix,
                      matrix.m_matrix + m_rows * m_cols,
                      m_matrix);
        }
    }

    ~Matrix()
    {
        if (m_matrix != nullptr)
        {
            delete[] m_matrix;
        }
        m_matrix = nullptr;
        m_rows = 0;
        m_cols = 0;
    }

public:
    Matrix &operator=(const Matrix &other)
    {
        if (this == &other)
            return *this;

        Matrix tmp(other);
        std::swap(m_rows, tmp.m_rows);
        std::swap(m_cols, tmp.m_cols);
        std::swap(m_matrix, tmp.m_matrix);

        return *this;
    }

    Row operator[](const int &r)
    {
        if (r < 0 || r >= m_rows)
        {
            throw std::out_of_range("out_of_range");
        }
        return Row(m_matrix + r * m_cols, m_cols);
    }
};
#include "Cinema.h"
#include <algorithm>

Cinema::Cinema(const int &r, const int &c)
    : Cinema()
{
    if (r > 0 && c > 0)
    {
        m_rows = r;
        m_cols = c;
        m_seats = Matrix<double>(m_rows, m_cols);
        m_booked = Matrix<bool>(m_rows, m_cols);
    }
}

Cinema::Cinema(const Cinema &other)
    : m_seats(other.m_seats),
      m_booked(other.m_booked),
      m_rows(other.m_rows),
      m_cols(other.m_cols)
{
}

void Cinema::setCentralPrices(const double &price)
{
    if (m_rows == 0 || m_cols == 0)
        return;

    int center1 = (m_rows - 1) / 2;

    for (int j = 0; j < m_cols; ++j)
    {
        m_seats[center1][j] = price;
    }

    if (m_rows % 2 == 0)
    {
        int center2 = center1 + 1;
        for (int j = 0; j < m_cols; ++j)
        {
            m_seats[center2][j] = price;
        }
    }
}

void Cinema::setPrices()
{
    if (m_rows == 0 || m_cols == 0)
        return;

    int center1 = (m_rows - 1) / 2;
    int left, right;

    if (m_rows % 2 == 0)
    {
        left = center1 - 1;
        right = center1 + 2;
    }
    else
    {
        left = center1 - 1;
        right = center1 + 1;
    }

    while (left >= 0 && right < m_rows)
    {
        double price = m_seats[left + 1][0] - 0.5;

        for (int j = 0; j < m_cols; ++j)
        {
            m_seats[left][j] = price;
            m_seats[right][j] = price;
        }

        --left;
        ++right;
    }
}

bool Cinema::isEmpty(const int &r, const int &c)
{
    if (0 <= r && r < m_rows && 0 <= c && c < m_cols)
    {
        return !m_booked[r][c];
    }
    return false;
}

double Cinema::priceAtSeat(const int &r, const int &c)
{
    if (0 <= r && r < m_rows && 0 <= c && c < m_cols)
    {
        return m_seats[r][c];
    }
    return -1.0;
}

bool Cinema::book(const int &r, const int &c)
{
    if (0 <= r && r < m_rows && 0 <= c && c < m_cols)
    {
        if (!m_booked[r][c])
        {
            m_booked[r][c] = true;
            return true;
        }
    }
    return false;
}

double Cinema::revenue()
{
    double totalPrice = 0.0;

    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            if (m_booked[i][j])
            {
                totalPrice += m_seats[i][j];
            }
        }
    }

    return totalPrice;
}
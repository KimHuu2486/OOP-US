#include "Polynomial.h"

Polynomial::Polynomial()
    : m_degree(0) 
{
    m_coef = new double [1];
    m_coef[0] = 0.0;
}

Polynomial::Polynomial(const int& degree, const double* coef) {
    // Giả sử mảng coef truyền vào phù hợp với tham số degree
    m_degree = degree;
    m_coef = new double[m_degree + 1];
    for (int i = 0; i <= m_degree; i++) {
        m_coef[i] = coef[i];
    }
}

Polynomial::Polynomial(const Polynomial& src) {
    m_degree = src.m_degree;
    m_coef = new double[m_degree + 1];
    for (int i = 0; i <= m_degree; i++) {
        m_coef[i] = src.m_coef[i];
    }
}

Polynomial::~Polynomial() {
    if (m_coef != nullptr) {
        delete[] m_coef;
        m_coef = nullptr;
        m_degree = -1;
    }
}

int Polynomial::degree() {
    return m_degree;
}

void Polynomial::setDegree(const int& degree) {
    if (degree == m_degree) {
        return;
    }

    double* newCoef = new double[degree + 1];
    int limit = std::min(m_degree, degree);

    for (int i = 0; i <= limit; i++) {
        newCoef[i] = m_coef[i];
    }
    
    for (int i = limit + 1; i <= degree; i++) {
        newCoef[i] = 0.0;
    }

    delete[] m_coef;
    m_coef = newCoef;
    m_degree = degree;
}

double Polynomial::coefficient(const int& degree) {
    if (degree >= 0 && degree <= m_degree) {
        return m_coef[degree];
    }
    return 0.0; // Trả về 0.0 khi degree không hợp lệ
}

void Polynomial::setCoefficient(const int& degree, const double& newCoef) {
    if (degree >= 0 && degree <= m_degree) {
        m_coef[degree] = newCoef;
    }
}

Polynomial Polynomial::operator+(const Polynomial& poly) const {
    int maxDeg = std::max(m_degree, poly.m_degree);
    int minDeg = std::min(m_degree, poly.m_degree);

    double* newCoef = new double[maxDeg + 1];

    for (int i = 0; i <= minDeg; i++)
        newCoef[i] = m_coef[i] + poly.m_coef[i];

    if (m_degree > poly.m_degree) {
        for (int i = minDeg + 1; i <= maxDeg; i++)
            newCoef[i] = m_coef[i];
    } 
    else {
        for (int i = minDeg + 1; i <= maxDeg; i++)
            newCoef[i] = poly.m_coef[i];
    }

    Polynomial result(maxDeg, newCoef);
    delete[] newCoef; 
    return result;
}

Polynomial Polynomial::operator-(const Polynomial& poly) const {
    int maxDeg = std::max(m_degree, poly.m_degree);
    int minDeg = std::min(m_degree, poly.m_degree);

    double* newCoef = new double[maxDeg + 1];

    for (int i = 0; i <= minDeg; i++)
        newCoef[i] = m_coef[i] - poly.m_coef[i];

    if (m_degree > poly.m_degree) {
        for (int i = minDeg + 1; i <= maxDeg; i++)
            newCoef[i] = m_coef[i];
    } 
    else {
        for (int i = minDeg + 1; i <= maxDeg; i++)
            newCoef[i] = 0.0 - poly.m_coef[i];
    }

    Polynomial result(maxDeg, newCoef);
    delete[] newCoef; 
    return result;
}

Polynomial Polynomial::operator*(const Polynomial& poly) const {
    int newDegree = m_degree + poly.m_degree;
    double* newCoef = new double[newDegree + 1];
    
    for (int i = 0; i <= newDegree; i++) {
        newCoef[i] = 0.0;
    }

    for (int i = 0; i <= m_degree; i++) {
        for (int j = 0; j <= poly.m_degree; j++) {
            newCoef[i + j] += m_coef[i] * poly.m_coef[j];
        }
    }

    Polynomial result(newDegree, newCoef);
    delete[] newCoef;
    return result;
}

Polynomial& Polynomial::operator=(Polynomial poly) {
    std::swap(m_degree, poly.m_degree);
    std::swap(m_coef, poly.m_coef);
    return *this;
}

bool Polynomial::operator<(const Polynomial& poly) const {
    if (m_degree != poly.m_degree)
        return m_degree < poly.m_degree;

    for (int deg = m_degree; deg >= 0; --deg) {
        if (m_coef[deg] != poly.m_coef[deg])
            return m_coef[deg] < poly.m_coef[deg];
    }
    return false;
}

bool Polynomial::operator>(const Polynomial& poly) const {
    if (m_degree != poly.m_degree)
        return m_degree > poly.m_degree;

    for (int deg = m_degree; deg >= 0; --deg) {
        if (m_coef[deg] != poly.m_coef[deg])
            return m_coef[deg] > poly.m_coef[deg];
    }
    return false;
}

bool Polynomial::operator==(const Polynomial& poly) const {
    if (m_degree != poly.m_degree)
        return false;

    for (int deg = m_degree; deg >= 0; --deg) {
        if (m_coef[deg] != poly.m_coef[deg])
            return false;
    }
    return true;
}

bool Polynomial::operator>=(const Polynomial& poly) const {
    return !(*this < poly);
}

bool Polynomial::operator<=(const Polynomial& poly) const {
    return !(*this > poly);
} 

bool Polynomial::operator!=(const Polynomial& poly) const {
    return !(*this == poly);
}

Polynomial Polynomial::operator!() const {
    if (m_degree == 0) {
        double zero = 0.0;
        return Polynomial(0, &zero);
    }

    int newDegree = m_degree - 1;
    double* newCoef = new double[newDegree + 1];

    for (int i = 0; i <= newDegree; i++) {
        newCoef[i] = m_coef[i + 1] * (i + 1);
    }

    Polynomial result(newDegree, newCoef);
    delete[] newCoef;
    return result;
}

Polynomial Polynomial::operator~() const {
    int newDegree = m_degree + 1;
    double* newCoef = new double[newDegree + 1];

    newCoef[0] = 0.0; // Đặt hệ số tự do của nguyên hàm là 0
    
    for (int i = 1; i <= newDegree; i++) {
        newCoef[i] = m_coef[i - 1] / i;
    }

    Polynomial result(newDegree, newCoef);
    delete[] newCoef;
    return result;
}

std::ostream& operator<<(std::ostream& out, const Polynomial& src) {
    for (int i = src.m_degree; i >= 0; i--) {
        if (src.m_coef[i] == 0) continue;

        if (i != src.m_degree && src.m_coef[i] > 0) {
            out << " + ";
        }
        else if (src.m_coef[i] < 0) {
            out << " - ";
        }

        double absCoef = fabs(src.m_coef[i]);
        if (!(absCoef == 1 && i > 0)) out << absCoef;
        if (i > 0) out << "x";
        if (i > 1) out << "^" << i;
    }
    return out;
}

std::istream& operator>>(std::istream& in, Polynomial& src) {
    int deg;
    std::cout << "Nhap bac cua da thuc: ";
    in >> deg;
    src.setDegree(deg);

    std::cout << "Nhap " << deg + 1 << " he so tu bac 0 -> " << deg << ": ";
    for (int i = 0; i <= deg; i++) {
        double value;
        in >> value;
        src.setCoefficient(i, value);
    }
    return in;
}
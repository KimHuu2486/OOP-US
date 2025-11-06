#include "init_vector.h"

init_vector::init_vector() {}

init_vector::init_vector(int N)
{
    m_vec.resize(N);
}

void init_vector::initEvenOddList(const int &N)
{
    auto myrand = [](int min, int max)
    {
        return [soft = std::mt19937(std::random_device()()),
                dist = std::uniform_int_distribution<int>(min, max)]() mutable
        {
            return dist(soft);
        };
    };

    m_vec.resize(N);
    std::vector<int> evens((N + 1) / 2);
    std::iota(evens.begin(), evens.end(), 1);

    int idx = 0;
    auto rnd = myrand(0, 100);

    std::generate(m_vec.begin(), m_vec.end(), [&idx, &evens, &rnd]()
                  {
        int val;
        if (idx % 2 == 0) {
            val = evens[idx/2];
        }
        else {
            val = rnd();
        }
        idx++;
        return val; });
}

void init_vector::initPrimeList(const int &N)
{
    m_vec.resize(N);
    int curPrime = 2;

    auto isPrime = [](int n)
    {
        if (n < 2)
            return false;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    };

    std::generate(m_vec.begin(), m_vec.end(), [&curPrime, &isPrime]()
                  {
        while (!isPrime(curPrime)) {
            curPrime++;
        }
        return curPrime++; });
}

void init_vector::print()
{
    for (const int &num : m_vec)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
}
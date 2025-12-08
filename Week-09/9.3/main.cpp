#include <iostream>
#include <string>
#include "Animal.h"
#include "Lion.h"
#include "Cheetah.h"
#include "Antelope.h"
#include "Dog.h"
#include "Horse.h"
#include "Human.h"

void compareSpeed(const Animal& a1, const Animal& a2) {
    std::cout << a1.species() << " speed: " << a1.speed() << " km/h" << std::endl;
    std::cout << a2.species() << " speed: " << a2.speed() << " km/h" << std::endl;

    if (a1.speed() > a2.speed()) {
        std::cout << a1.species() << " is faster than " << a2.species() << std::endl;
    } else if (a1.speed() < a2.speed()) {
        std::cout << a2.species() << " is faster than " << a1.species() << std::endl;
    } else {
        std::cout << a1.species() << " and " << a2.species() << " have the same speed" << std::endl;
    }
}

int main() {
    Lion lion;
    Cheetah cheetah;
    Antelope antelope;
    Dog dog;
    Horse horse;
    Human human;

    compareSpeed(lion, cheetah);
    std::cout << std::endl;

    compareSpeed(antelope, horse);
    std::cout << std::endl;

    compareSpeed(dog, human);
    std::cout << std::endl;

    compareSpeed(human, lion);

    return 0;
}
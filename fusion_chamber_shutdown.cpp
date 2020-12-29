//A laboratory is testing how atoms react in ionic state during nuclear fusion.They introduce different elements with Hydrogen in high temperatureand pressurized chamber.Due to unknown reason the chamber lost its powerand the elements in it started precipitating
//Given the number of atoms of Carbon[C], Hydrogen[H] and Oxygen[O] in the chamber.Calculate how many molecules of Water[H2O], Carbon Dioxide[CO2] and Methane[CH4] will be produced following the order of reaction affinity below
//
//1. Hydrogen reacts with Oxygen = H2O
//2. Carbon   reacts with Oxygen = CO2
//3. Carbon   reacts with Hydrogen = CH4

#include <array>

std::array<int, 3> burner(int c, int h, int o) {
    int water = 0;
    int co2 = 0;
    int methane = 0;
    while ((h > 1) && (o > 0))
    {
        water++;
        o--;
        h -= 2;
    }
    while ((c > 0) && (o > 1))
    {
        co2++;
        c--;
        o -= 2;
    }
    while ((c > 0) && (h > 3))
    {
        methane++;
        c--;
        h -= 4;
    }
    return std::array<int, 3>{water, co2, methane};
}
#include <iostream>

enum class Color {RED, ORANGE};
enum class Rank {FIRST, SECOND};
enum class Gear {FIRST, SECOND};

int main() {
    Color c1 = Color::RED;
    Rank r1 = Rank::FIRST;
    Gear g1 = Gear::FIRST;

    // now we cannot compare objects of two diff enums
    return 0;
}
#include "LibraryCode.hpp"

Validator::Validator(int low, int high): mLow{low}, mHigh{high} {}

bool Validator::inRange(int value) {
    return mLow <= value && value <= mHigh;
}

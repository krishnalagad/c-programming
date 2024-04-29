#ifndef LIBRARYCODE_HPP
#define LIBRARYCODE_HPP

class Validator {
    private:
        int mLow, mHigh;
    public:
        Validator() = delete;
        Validator(int low, int high);
        bool inRange(int value);
};

#endif // LIBRARYCODE_HPP

#include <iostream>

class DataModel {
    private:
        int _id {-1};
        float _value {0.0f};
    public:
        DataModel() = default;
        ~DataModel() = default;
        DataModel(const DataModel&) = default;
        DataModel& operator=(const DataModel&) = default;
        DataModel& operator=(DataModel&&) = default;
        DataModel(DataModel&&) = default;

        DataModel(int id, float value): _id(id), _value(value) {}

        int id() const { return _id; }
        void setId(int id) { _id = id; }

        float value() const { return _value; }
        void setValue(float value) { _value = value; }
};

int main() {
    return 0;
}
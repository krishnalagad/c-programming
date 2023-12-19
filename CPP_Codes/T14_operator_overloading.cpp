#include <iostream>

class Point{
    private:
        int x, y;
    public:
        Point() {x = y = 0;}
        Point(int x, int y) {this->x = x; this->y = y;}
        void display() {
            std::cout<<"\nx = "<<this->x<<"\ny = "<<this->y<<std::endl;
        }

        Point operator +(Point &point) {
            Point ans;
            ans.x = this->x + point.x;
            ans.y = this->y + point.y;
            return ans;
        }
};

int main(void) {
    Point p1(3, 4), p2(1, 2);
    Point p3 = p1 + p2;
    p3.display();
    return 0;
}
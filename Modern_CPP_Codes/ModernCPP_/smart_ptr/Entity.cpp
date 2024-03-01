#include <iostream>
#include <memory>

class Entity {
    private:
        int data1;
        float data2;
    public:
        Entity() { std::cout<<"Entity obj created!!"<<std::endl; }
        Entity(int d1, float d2): data1(d1), data2(d2) { std::cout<<"Entity obj created!!"<<std::endl; }
        ~Entity() { std::cout<<"Entity obj destroyed!!"<<std::endl; }
        void show() { std::cout<<"show() method invoked!!-> "<<data1<<" "<<data2<<std::endl; }
};

int main() {
    /*
        smart pointer: unique pointer -> Cannot copy unique_ptr to other because both the copy
        constructor and assignment operator of unique pointer are deleted.
    */
    {
        std::unique_ptr<Entity> entity1 = std::make_unique<Entity>(22, 34.6f);
        // std::unique_ptr<Entity> e1 = entity;    // not allowed
        entity1->show();
        std::unique_ptr<Entity> entity2 = std::make_unique<Entity>(222, 34.6f);
        entity2->show();
    }

    /*
        smart pointer: shared pointer -> We can share or make copy of shared pointer, it has 
        reference block that keeps track of all the instances of shared pointer created. shared
        ptr get destroyed when all of its instances get destroyed.
    */
    {
        std::shared_ptr<Entity> instance1;
        {
            std::shared_ptr<Entity> instance2 = std::make_shared<Entity>(10, 12.4f);
            instance2->show();
            instance1 = instance2;
            std::shared_ptr<Entity> instance3 = std::make_shared<Entity>(100, 12.4f);
            instance3->show();
        }
        instance1->show();
    }

    /*
        smart pointer: weak pointer -> it doesn't kepp the count of reference counter like shared
        pointer.
    */
    {
        std::shared_ptr<Entity> sharedInstance = std::make_shared<Entity>(11, 12.5f);
        sharedInstance->show();
        {
            sharedInstance->show();
            std::weak_ptr<Entity> weakInstance = sharedInstance;
            if (auto sharedCopy = weakInstance.lock()) 
                sharedCopy->show();
            else 
                std::cout << "weakInstance is expired." << std::endl;
        }
    }
    
    return 0;
}
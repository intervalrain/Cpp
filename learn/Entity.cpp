#include <iostream>
#include <string>

class Entity{
public:
      void print() const{
          std::cout << "Hello!" << std::endl;
      }
};

class ScopedPtr{
private:
    Entity* m_Obj;
public:
    ScopedPtr(Entity* entity)
      : m_Obj(entity)
    {
    }

    ~ScopedPtr()
    {
        delete m_Obj;
    }

    Entity* operator->(){
        return m_Obj;
    }

};

int main(){
    Entity e;
    e.print();

    Entity* ptr = &e;
    Entity& entity = *ptr;

    entity.print();
    (*ptr).print();
    ptr->print();

    ScopedPtr entityObj = new Entity();
    entityObj->print();
    return 0;
}


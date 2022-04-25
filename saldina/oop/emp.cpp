#include <iostream>
#include <vector>
using std::string;
using std::vector;

class AbstractEmployee {
    virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee{
private:
    string Name;
    string Company;
    int Age;
protected:

public:
    Employee(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }

    void setName(string name){
        Name = name;
    }
    string getName(){
        return Name;
    }
    void setCompany(string company){
        Company = company;
    }
    string getCompany(){
        return Company;
    }
    void setAge(int age){
        Age = age;
    }
    int getAge(){
        return Age;
    }

    void intro(){
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }

    void AskForPromotion(){
        if (Age > 28)
            std::cout << Name << " got promoted!" << std::endl;
        else
            std::cout << Name << ", sorry No promotion for you!" << std::endl;
    }
    virtual void Work(){
        std::cout << Name << " is checking email, task backlog, performing tasks..." << std::endl;
    }
};

class Developer: public Employee{
public:
    string FavProgrammingLaguage;
    Developer(string name, string company, int age, string language)
        : Employee(name, company, age){
        FavProgrammingLaguage = language;
    }
    void FixbBug(){
        std::cout << getName() << "fixed up using " << FavProgrammingLaguage << std::endl;
    }
    void Work(){
        std::cout << getName() << " writing " << FavProgrammingLaguage << " code" << std::endl;
    }
};

class Teacher: public Employee{
public:
    string Subject;
    Teacher(string name, string company, int age, string subject)
        : Employee(name, company, age){
        Subject = subject;
    }
    void PrepareLesson(){
        std::cout << getName() << " is preparing " << Subject << " lesson" << std::endl;
    }
    void Work(){
        std::cout << getName() << " is teaching " << Subject << std::endl;
    }

};

int main()
{
    Developer d = Developer("Saldina", "YT-CodeBeauty", 25, "C++");
    Teacher t = Teacher("Rain", "UMC", 30, "Math");

    Employee *e1 = &d;
    Employee *e2 = &t;

    e1->Work();
    e2->Work();

    return 0;

}

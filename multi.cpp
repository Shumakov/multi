#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

//#define DEBUG 1

class Human {
protected:
    string name;
    int age;
    string colorHair;
public:
    string getName() const { return name; }
    int  getAge() const { return age; }

    Human(string name, int age, string colorHair) :
        name{ name }, age{ age }, colorHair{ colorHair } {

#ifdef DEBUG
        cout << "Создаем человека " << name << endl;
#endif
    }

    ~Human() {
#ifdef DEBUG
        cout << "Удаляем человека " << name << endl;
#endif
    }

    void print() const {
        cout << "Я человек, меня зовут " << name << endl;
    }
};


class Student {
protected:
    string group;
public:
    Student(string group) :group{ group } {
#ifdef DEBUG
        cout << "Создаем студента  группы " << group << endl;
#endif
    }

    ~Student() {
#ifdef DEBUG
        cout << "Удаляем студента группы " << group << endl;
#endif
    }

    string getGroup() const { return group; }

    virtual void learn() const {
        cout << "Я как-то учусь" << endl;
    }
    void typeStudent() {
        cout << "Я какой-то студент" << endl;
    }

    void print()const {
        cout << "Я студент группы " << group << endl;
    }
};


// Студент дневного отделения
class FullTimeStudent : public Human, public Student {

public:
    FullTimeStudent(string name, int age, string colorHair, string group) :
        Human(name, age, colorHair),
        Student(group)
    {
#ifdef DEBUG
        cout << "Создаем студента дневного отделения" << endl;
#endif
    }
    ~FullTimeStudent() {
#ifdef DEBUG
        cout << "Удаляем студента дневного отделения " << name << "  группы " << group << endl;
#endif
    }

    void learn()const {
        cout << "Я учусь на дневном отделении" << endl;
    }

    void print()const {
        //Student::print();
        //Human::print();
        cout << "Я студент дневного отделения" << endl;
    }
};

// Студент вечернего отделения
class EveningDepartmentStudent : public Human, public Student {
public:
    EveningDepartmentStudent(string name, int age, string colorHair, string group) :
        Human(name, age, colorHair),
        Student(group) {

#ifdef DEBUG
        cout << "Создаем студента вечернего отделения" << endl;
#endif
    }

    ~EveningDepartmentStudent() {
#ifdef DEBUG
        cout << "Удаляем студента вечернего отделения " << name << "  группы " << group << endl;
#endif
    }

    void learn()const {
        cout << "Я учусь на вечернем отделении" << endl;
    }

    void print()const {
        cout << "Я студент вечернего отделения" << endl;
        //Student::print();
       // Human::print();
    }
};

// Студент заочного отделения
class CorrespondenceDepartmentStudent : public Human, public Student {
public:
    CorrespondenceDepartmentStudent(string name, int age, string colorHair, string group) :
        Human(name, age, colorHair),
        Student(group) {
#ifdef DEBUG
        cout << "Создаем студента заочного отделения" << endl;
#endif
    }

    ~CorrespondenceDepartmentStudent() {
#ifdef DEBUG
        cout << "Удаляем студента заочного отделения " << name << "  группы " << group << endl;
#endif
    }

    void learn() const {
        cout << "Я учусь на заочном отделении" << endl;
    }

    void print()const {
        cout << "Я студент заочного отделения" << endl;
        //Student::print();
        //Human::print();
    }
};


class Weapon {
public:
    virtual void use_me() const = 0;

    virtual ~Weapon(){
    
    };
};

class Knife : public Weapon {
public:    

    Knife() {
        cout << " СОЗДАН нож" << endl;
    }

    ~Knife() {
        cout << " УДАЛЕН нож" << endl;
    }


    void use_me() const override {
        cout << " Использован нож" << endl;
    }
};


class Gun : public Weapon {
public:

    Gun() {
        cout << " СОЗДАН пистолет" << endl;
    }

    ~Gun() {
        cout << " УДАЛЕН пистолет" << endl;
    }

    void use_me() const override {
        cout << " Использован пистолет" << endl;
    }
};

class AutoGun : public Weapon {
public:
    void use_me() const override {
        cout << " Использован автомат" << endl;
    }
};

class ShotGun : public Weapon {
public:

    ShotGun() {
        cout << " СОЗДАН дробовик" << endl;
    }

    ~ShotGun() {
        cout << " УДАЛЕН дробовик" << endl;
    }


    void use_me() const override {
        cout << " Использован дробовик" << endl;
    }
};


class Player {

    vector <Weapon*> weapons;

public:

    ~Player() {
        for (auto w : weapons)
            delete w;
    }

    void addWeapon(Weapon* w) {
        weapons.push_back(w);
    }

    void shoot() {
        for (auto w : weapons)
            w->use_me();
    }

};


class A {
public:
    A() {
        cout << "Создан калсс A" << endl;
    }
    ~A() {
        cout << "Удален калсс A" << endl;
    }
};


class B: public A {
public:
    B() {
        cout << "Создан калсс B, выделена память" << endl;
    }
    ~B() {
        cout << "Удален калсс B, освобождена память" << endl;
    }
};




int main(){

    setlocale(LC_ALL, "Rus");

    ////A a1;
    //B* b1 = new B{};
    //A* ptr = b1;

    //delete ptr;
    //

    //return 0;


    Player player;

    //Knife* k = new Knife();

    //delete k;



    player.addWeapon(new Knife());
    player.addWeapon(new Gun());
    player.addWeapon(new ShotGun());    
    player.shoot();


    return 0;

    FullTimeStudent fs{"Student1", 22, "Black","Group 1"};
    cout << fs.getName() << endl;
    fs.learn();

    //Human* h1 = &fs;

    //h1->print();

    //Student *st = &fs;

    //st->print();
    //st->learn();

    //return 0;

    EveningDepartmentStudent es{ "Student2", 22, "Black","Group 2" };

    cout << es.getName() << endl;
    es.learn();

    CorrespondenceDepartmentStudent cf{ "Student3", 22, "Black","Group 3" };


    cout << cf.getName() << endl;
    cf.learn();

    cout << endl << endl;

    const int SIZE = 3;
    Student** sts = new Student*[SIZE]{ &fs,&es,&cf };
    for (int i{}; i < SIZE; ++i)
        sts[i]->learn();


    cout << endl << endl;

    vector <Student*> v_sts;

    v_sts.push_back(&fs);
    v_sts.push_back(&es);
    v_sts.push_back(&cf);

    for (auto e : v_sts)
        e->learn();






    
}

/*
Разработать классы  разного оружия, который умеет быть использованным
Разработать класс "Игрок", который умеет играть (использовать какое-то оружие)
У игрока есть много разного оружия и он его использует в цикле друг за другом
*/



/*
Домашнее задание

Сконструируйте классы и отношения, описывающие следующие объекты:
транспортное средство как таковое vehicle
велосипед bicycle
спортивный велосипед sport_bicycle
классический велосипед classic_bicycle
детский велосипед children_bicycle
автосредство automobile
легковая машина car
автобус bus
грузовик truck

Дальше на ваше усмотрение и фантазию!

Для данной архитектуры определите общие и различные признаки.
Постройте иерархию классов, определите виртуальные функции,
методы и поля классов.

Создайте класс человек, который сможет хранить гараж транспортных средств
и сможет ими пользоваться, обслуживать, смотреть технические характеристики.

Наполните свое приложение необходимыми экземплярами и продемонстрируйте работу ваших классов.
*/
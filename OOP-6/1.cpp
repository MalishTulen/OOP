#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    virtual string getType() = 0;
    virtual bool isDangerous() = 0;
    virtual ~Animal() {}
};

class Monkey : public Animal {
public:
    string getType() override {
        return "Monkey";
    }

    bool isDangerous() override {
        return false;
    }
};

class Lion : public Animal {
public:
    string getType() override {
        return "Lion";
    }

    bool isDangerous() override {
        return true;
    }
};

class Snake : public Animal {
public:
    string getType() override {
        return "Snake";
    }

    bool isDangerous() override {
        return true;
    }
};

class ZooKeeper {
private:
    int dangerousCount;

public:
    ZooKeeper() : dangerousCount(0) {}

    void handleAnimal(Animal* a) {
        if (a->isDangerous()) {
            dangerousCount++;
        }
    }

    int getDangerousCount() {
        return dangerousCount;
    }
};

/*
int main() {
    ZooKeeper z;
    Monkey *m = new Monkey();
    z.handleAnimal(m);
    delete m;

    m = new Monkey();
    z.handleAnimal(m);
    delete m;

    Lion *l = new Lion();
    z.handleAnimal(l);
    delete l;

    cout << z.getDangerousCount() << endl;

    return 0;
}
*/

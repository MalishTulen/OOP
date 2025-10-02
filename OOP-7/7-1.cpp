#include <iostream>
using namespace std;

namespace namespaceA {
    class Engine {
    public:
        void run() {
            cout << "EngineA run" << endl;
        }
    };
}

namespace namespaceB {
    class Engine {
    public:
        void run() {
            cout << "EngineB run" << endl;
        }
    };
}

namespace namespaceC {
    class Engine {
    public:
        void run() {
            cout << "EngineC run" << endl;
        }
    };
}

class MyEngine {
private:
    namespaceA::Engine engineA;
    namespaceB::Engine engineB;
    namespaceC::Engine engineC;

public:
    void run(unsigned int number) {
        if (number == 1) {
            engineA.run();
        } else if (number == 2) {
            engineB.run();
        } else if (number == 3) {
            engineC.run();
        }
    }
};

/*
int main() {
    MyEngine e;
    e.run(1);
    e.run(2);
    e.run(3);
    e.run(10);

    return 0;
}*/

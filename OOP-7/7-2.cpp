#include <iostream>
using namespace std;

class Storage
{
protected:
    unsigned int size;
    int* data;

public:
    Storage(unsigned int n) : size(n) {
        data = new int[n];
    }

    virtual ~Storage() {
        delete[] data;
    }

    unsigned int getSize() {
        return size;
    }

    int getValue(unsigned int i) {
        return data[i];
    }

    void setValue(unsigned int i, int value) {
        data[i] = value;
    }
};

class TestStorage : public Storage {
protected:
    int* more_data;

public:
    TestStorage(unsigned int n) : Storage(n) {
        more_data = new int[n];
    }

    ~TestStorage() {
        delete[] more_data;
    }
};

int main() {
    Storage* ts = new TestStorage(42);
    delete ts;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

class SpacePort
{
private:
    vector<bool> docks;

public:
    SpacePort(unsigned int size) : docks(size, false) {}

    bool requestLanding(unsigned int dockNumber) {
        if (dockNumber >= docks.size()) {
            return false;
        }
        if (docks[dockNumber]) {
            return false;
        }
        docks[dockNumber] = true;
        return true;
    }

    bool requestTakeoff(unsigned int dockNumber) {
        if (dockNumber >= docks.size()) {
            return false;
        }
        if (!docks[dockNumber]) {
            return false;
        }
        docks[dockNumber] = false;
        return true;
    }
};

/*
int main() {
    SpacePort s(5);
    cout << boolalpha << s.requestLanding(0) << endl;
    cout << boolalpha << s.requestLanding(4) << endl;
    cout << boolalpha << s.requestLanding(5) << endl;

    cout << boolalpha << s.requestTakeoff(0) << endl;
    cout << boolalpha << s.requestTakeoff(4) << endl;
    cout << boolalpha << s.requestTakeoff(5) << endl;

    return 0;
}*/

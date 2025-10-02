#include <iostream>
using namespace std;

class GasHolder
{
private:
    float volume;
    float temperature;
    float total_moles;

public:
    GasHolder(float v) : volume(v), temperature(273.0), total_moles(0.0) {}

    ~GasHolder() {}

    void inject(float m, float M) {
        total_moles += m / M;
    }

    void heat(float dT) {
        temperature += dT;
    }

    void cool(float dT) {
        temperature -= dT;
        if (temperature < 0) {
            temperature = 0;
        }
    }

    float getPressure() {
        const float R = 8.31;
        return (total_moles * R * temperature) / volume;
    }
};

/*
int main() {
    GasHolder h(1.0);
    h.inject(29, 29);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.inject(29, 29);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.heat(273);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.cool(373);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.cool(373);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;

    return 0;
}
*/

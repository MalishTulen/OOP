#include <iostream>
#include <vector>
using namespace std;

class Car
{
protected:
    bool allowsBoarding;
    bool allowsLoading;
    unsigned int numberOfSeats;
    unsigned int numberOfContainers;

public:
    Car(bool allowsBoarding, bool allowsLoading, unsigned int numberOfSeats, unsigned int numberOfContainers) {
        this->allowsBoarding = allowsBoarding;
        this->allowsLoading = allowsLoading;
        this->numberOfSeats = numberOfSeats;
        this->numberOfContainers = numberOfContainers;
    }

    ~Car() {}

    bool isBoardingAllowed() const { return allowsBoarding; }

    bool isLoadingAllowed() const { return allowsLoading; }

    unsigned int getNumberOfSeats() const { return numberOfSeats; }

    unsigned int getNumberOfContainers() const { return numberOfContainers; }
};

class ConvoyManager
{
private:
    unsigned int totalSeats;
    unsigned int totalContainers;

public:
    ConvoyManager() : totalSeats(0), totalContainers(0) {}

    void registerCar(const Car& c) {
        if (c.isBoardingAllowed()) {
            totalSeats += c.getNumberOfSeats();
        }
        if (c.isLoadingAllowed()) {
            totalContainers += c.getNumberOfContainers();
        }
    }

    unsigned int getTotalSeats() const {
        return totalSeats;
    }

    unsigned int getTotalContainers() const {
        return totalContainers;
    }
};

int main() {
    ConvoyManager cm;

    Car c1(true, false, 12, 3);  cm.registerCar(c1);
    Car c2(false, true, 12, 3);  cm.registerCar(c2);
    Car c3(true, true, 12, 3);  cm.registerCar(c3);
    Car c4(false, false, 12, 3);  cm.registerCar(c4);

    cout << "Total available seats: " << cm.getTotalSeats() << endl;
    cout << "Total available containers: " << cm.getTotalContainers() << endl;

    return 0;
}

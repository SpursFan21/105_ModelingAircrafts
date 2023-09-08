#include <iostream>
#include <string>
#include <vector>

class Aircraft {
private:
    std::string manufacturer;
    std::string model;
    int yearOfManufacture;

public:
    Aircraft(const std::string& company, const std::string& type, int year)
        : manufacturer(company), model(type), yearOfManufacture(year) {}

    virtual void displayInfo() const {
        std::cout << "Manufacturer: " << manufacturer << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Year of Manufacture: " << yearOfManufacture << std::endl;
    }

    bool operator==(const Aircraft& other) const {
        return yearOfManufacture == other.yearOfManufacture;
    }
};

class Airplane : public Aircraft {
private:
    double wingspan;
    std::string engineType;

public:
    Airplane(const std::string& company, const std::string& type, int year, double span, const std::string& engine)
        : Aircraft(company, type, year), wingspan(span), engineType(engine) {}

    void displayInfo() const override {
        Aircraft::displayInfo();
        std::cout << "Wingspan: " << wingspan << " meters" << std::endl;
        std::cout << "Engine Type: " << engineType << std::endl;
    }
};

class Helicopter : public Aircraft {
private:
    double rotorDiameter;
    int maximumPassengers;

public:
    Helicopter(const std::string& company, const std::string& type, int year, double rotor, int maxPass)
        : Aircraft(company, type, year), rotorDiameter(rotor), maximumPassengers(maxPass) {}

    void displayInfo() const override {
        Aircraft::displayInfo();
        std::cout << "Rotor Diameter: " << rotorDiameter << " meters" << std::endl;
        std::cout << "Maximum Passengers: " << maximumPassengers << std::endl;
    }
};

int main() {
    std::vector<Aircraft*> aircraftList;

    aircraftList.push_back(new Airplane("Boeing", "747", 1990, 68.4, "Jet"));
    aircraftList.push_back(new Helicopter("Airbus", "H225", 2005, 12.2, 19));
    aircraftList.push_back(new Airplane("Airbus", "A320", 2000, 35.8, "Jet"));
    aircraftList.push_back(new Helicopter("Bell", "407", 2015, 10.5, 6));

    std::cout << "Aircraft Information:\n";
    for (const Aircraft* aircraft : aircraftList) {
        aircraft->displayInfo();
        std::cout << std::endl;
    }

    if (*aircraftList[0] == *aircraftList[2]) {
        std::cout << "The first and third aircraft have the same year of manufacture.\n";
    }
    else {
        std::cout << "The first and third aircraft have different years of manufacture.\n";
    }

    for (Aircraft* aircraft : aircraftList) {
        delete aircraft;
    }

    return 0;
}

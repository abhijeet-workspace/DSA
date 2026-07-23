// Abstraction Basics — OOP pillar 4
// Abstract SmartDevice with pure virtuals; concrete Light/Thermostat implement them.
#include <iostream>
#include <string>

class SmartDevice {
protected:
    std::string deviceName; // shared identity
    bool isOn; // power state

public:
    SmartDevice(std::string name) : deviceName(name), isOn(false) {}

    virtual void performDuty() = 0; // must implement
    virtual void getDeviceStatus() = 0; // must implement

    void turnOn() { // shared concrete API
        isOn = true;
        std::cout << deviceName << " is now powered ON." << std::endl;
    }

    void turnOff() {
        isOn = false;
        std::cout << deviceName << " is now powered OFF." << std::endl;
    }

    virtual ~SmartDevice() {} // polymorphic delete-safe
};

class SmartLight : public SmartDevice {
private:
    int brightness; // 0..100

public:
    SmartLight(std::string name) : SmartDevice(name), brightness(50) {}

    void performDuty() override {
        if (isOn) {
            std::cout << "[Light Duty]: Illuminating room at " << brightness
                      << "% brightness." << std::endl;
        } else {
            std::cout << "[Light Duty]: Cannot illuminate. Device is OFF." << std::endl;
        }
    }

    void getDeviceStatus() override {
        std::cout << "Device: " << deviceName << " | Power: " << (isOn ? "ON" : "OFF")
                  << " | Brightness: " << brightness << "%" << std::endl;
    }

    void setBrightness(int level) {
        brightness = level;
        std::cout << "Brightness set to " << brightness << "%." << std::endl;
    }
};

class SmartThermostat : public SmartDevice {
private:
    double targetTemperature;

public:
    SmartThermostat(std::string name) : SmartDevice(name), targetTemperature(22.0) {}

    void performDuty() override {
        if (isOn) {
            std::cout << "[Thermostat Duty]: Regulating room temperature to "
                      << targetTemperature << " C." << std::endl;
        } else {
            std::cout << "[Thermostat Duty]: Idle. Device is OFF." << std::endl;
        }
    }

    void getDeviceStatus() override {
        std::cout << "Device: " << deviceName << " | Power: " << (isOn ? "ON" : "OFF")
                  << " | Target Temperature: " << targetTemperature << " C" << std::endl;
    }

    void setTemperature(double temp) {
        targetTemperature = temp;
        std::cout << "Target Temperature adjusted to " << targetTemperature
                  << " C." << std::endl;
    }
};

int main() {
    std::cout << "=== OOP Pillar 4: Abstraction ===" << std::endl;

    SmartDevice* light = new SmartLight("Bedroom Light");
    SmartDevice* thermostat = new SmartThermostat("Living Room Thermostat");

    std::cout << "\n--- Interacting with SmartLight ---" << std::endl;
    light->getDeviceStatus();
    light->turnOn();
    static_cast<SmartLight*>(light)->setBrightness(85);
    light->performDuty();

    std::cout << "\n--- Interacting with SmartThermostat ---" << std::endl;
    thermostat->getDeviceStatus();
    thermostat->turnOn();
    static_cast<SmartThermostat*>(thermostat)->setTemperature(20.5);
    thermostat->performDuty();
    thermostat->turnOff();
    thermostat->performDuty();

    delete light;
    delete thermostat;
    return 0;
}

#include <iostream>
#include <string>

using namespace std;

class EnvironmentSensor {
private:
    int currentTemperature;

public:
    EnvironmentSensor() {
        currentTemperature = 0;
    }

    void setCurrentTemperature(int temperature) {
        currentTemperature = temperature;
    }

    int getCurrentTemperature() {
        return currentTemperature;
    }
};

class WaterHeater {
private:
    int heatingTemperature;

public:
    WaterHeater() {
        heatingTemperature = 0;
    }

    void setHeatingTemperature(int temperature) {
        heatingTemperature = temperature;
    }

    int getHeatingTemperature() {
        return heatingTemperature;
    }

    void heatWater(int requiredTemperature) {
        cout << "Heating water to " << requiredTemperature << " degrees Celsius." << endl;
    }
};

class SmartGeyser {
private:
    EnvironmentSensor* sensor;
    WaterHeater* heater;

public:
    SmartGeyser(EnvironmentSensor* envSensor, WaterHeater* waterHeater) {
        sensor = envSensor;
        heater = waterHeater;
    }

    void activateGeyser(string season) {
        cout << "Geyser activated." << endl;
        int currentTemp = sensor->getCurrentTemperature();
        cout << "Current temperature: " << currentTemp << " degrees Celsius." << endl;
        int requiredTemp = calculateRequiredTemperature(currentTemp, season);
        heater->heatWater(requiredTemp);
    }

    int calculateRequiredTemperature(int currentTemperature, string season) {
        if (season == "summer") {
            return currentTemperature - 10; // Adjust for summer
        } else if (season == "winter") {
            return currentTemperature + 10; // Adjust for winter
        } else {
            return currentTemperature; // No adjustment for other seasons
        }
    }
};

class HomeOwner {
public:
    void getOutOfBed() {
        cout << "Homeowner gets out of bed." << endl;
    }
};

int main() {
    EnvironmentSensor sensor;
    WaterHeater heater;
    SmartGeyser geyser(&sensor, &heater);
    HomeOwner owner;

    string season;
    int currentTemp;

    cout << "Enter the current season (winter/summer): ";
    cin >> season;
    cout << "Enter the current temperature in degrees Celsius: ";
    cin >> currentTemp;

    sensor.setCurrentTemperature(currentTemp);

    owner.getOutOfBed();
    geyser.activateGeyser(season);

    return 0;
}

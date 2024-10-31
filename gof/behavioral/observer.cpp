#include <iostream>
#include <string>
using namespace std;
#include <vector>

// Observer interface
class Observer {
  public:
    virtual void update(float temperature, float humidity, float pressure) = 0;
};

// Subject (WeatherStation) class
class WeatherStation {
  private:
    float temperature;
    float humidity;
    float pressure;
    vector<Observer *> observers;

  public:
    void registerObserver(Observer *observer) {
      observers.push_back(observer);
    }

    void removeObserver(Observer *observer) {
      // You can implement the removal logic if needed.
    }

    void notifyObservers() {
      for (Observer *observer : observers) {
        observer->update(temperature, humidity, pressure);
      }
    }

    void setMeasurements(float temp, float hum, float press) {
      temperature = temp;
      humidity = hum;
      pressure = press;

      notifyObservers();
    }
};

// Concrete Observer
class Display : public Observer {
  public:
    void update(float temperature, float humidity, float pressure) {
      cout << "Display: Temperature: " << temperature << "°C, "
           << "Humidity: " << humidity << "%, "
           << "Pressure: " << pressure << " hPa"
           << endl;
    }
};

int main() {
  WeatherStation weatherStation;
  Display display;

  // Register displays as observers
  weatherStation.registerObserver(&display);

  // Simulate weather data updates
  weatherStation.setMeasurements(25.5, 60, 1013.2);
  weatherStation.setMeasurements(24.8, 58, 1014.5);

  return 0;
}


// Output
// Display: Temperature: 25.5xc2xb0C, Humidity: 60%, Pressure: 1013.2 hPa
// Display: Temperature: 24.8xc2xb0C, Humidity: 58%, Pressure: 1014.5 hPa
#include <Adafruit_Sensor.h>
#include "thingProperties.h"
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const int sensor_pin = A0;

void setup() {
  Serial.begin(9600);
  dht.begin();
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  }
void loop() {
  ArduinoCloud.update();
  readtemp();
  onMoistureChange();
}

void readtemp() {
  temp = dht.readTemperature();
  Serial.print("Temperature = ");
  Serial.print(temp);
  Serial.println();
  delay(2000);
}

void onMoistureChange()  {
  //humidity
  float moisture;
  moisture = (100.00 - ((analogRead(sensor_pin)/1023.00) * 100.00));
  Serial.print("Soil Moisture(in Percentage) = ");
  Serial.print(moisture);
  Serial.println("%");
  delay(1000);
}

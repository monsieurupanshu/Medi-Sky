#include <SoftwareSerial.h>
#include "Timer.h"
#include <PulseSensorPlayground.h> 

// Initialize the pulse sensor and software serial for ESP8266
PulseSensorPlayground pulseSensor; 
SoftwareSerial esp8266(10, 11); // Rx, Tx

// WiFi and server settings
#define SSID "your_wifi_name"
#define PASS "your_wifi_password"
#define IP "184.106.153.149" // thingspeak.com IP

String msg = "GET /update?key=Your_Api_Key";

void setup() {
    Serial.begin(9600);
    esp8266.begin(115200);

    pulseSensor.analogInput(PulseWire);
    pulseSensor.blinkOnPulse(LED13);
    pulseSensor.setThreshold(Threshold);

    if (pulseSensor.begin()) {
        Serial.println("PulseSensor ready!");
    }

    Serial.println("AT");
    esp8266.println("AT");
    delay(3000);

    if (esp8266.find("OK")) {
        connectWiFi();
    }

    t.every(10000, getReadings);
    t.every(10000, updateInfo);
}


void loop() {
    panic_button(); // Call the panic button function

    // Update any timers
    t.update();

}

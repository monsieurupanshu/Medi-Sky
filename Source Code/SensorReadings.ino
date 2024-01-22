void getReadings() {
    int raw_myTemp = analogRead(A1);
    double Voltage = (raw_myTemp / 1023.0) * 5000; // Convert to millivolts
    double tempC = Voltage * 0.1; // Convert to degrees Celsius
    double myTemp = (tempC * 1.8) + 32; // Convert to Fahrenheit
    Serial.println(myTemp);

    int myBPM = pulseSensor.getBeatsPerMinute();
    if (pulseSensor.sawStartOfBeat()) {
        Serial.println(myBPM);
    }
    delay(20);
}
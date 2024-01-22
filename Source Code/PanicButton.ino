void panic_button() {
    int panic = digitalRead(8);
    if (panic == HIGH) {
        Serial.println("Panic button pressed!");

        String cmd = "AT+CIPSTART=\"TCP\",\"";
        cmd += IP;
        cmd += "\",80";
        Serial.println(cmd);
        esp8266.println(cmd);
        delay(2000);

        if (esp8266.find("Error")) {
            return;
        }

        cmd = msg;
        cmd += "&field3=1"; // Indicate panic button pressed
        cmd += "\r\n";

        Serial.print("AT+CIPSEND=");
        esp8266.print("AT+CIPSEND=");
        Serial.println(cmd.length());
        esp8266.println(cmd.length());
        delay(1000);

        if (esp8266.find(">")) {
            Serial.print(cmd);
            esp8266.print(cmd);
        }
        delay(1000);
        esp8266.find("SEND OK");
    }
}
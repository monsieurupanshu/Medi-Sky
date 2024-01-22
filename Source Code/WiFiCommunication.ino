boolean connectWiFi() {
    Serial.println("AT+CWMODE=1");
    esp8266.println("AT+CWMODE=1");
    delay(2000);

    String cmd = "AT+CWJAP=\"";
    cmd += SSID;
    cmd += "\",\"";
    cmd += PASS;
    cmd += "\"";
    Serial.println(cmd);
    esp8266.println(cmd);
    delay(5000); // Wait for the ESP8266 to connect

    if (esp8266.find("OK")) {
        Serial.println("Connected to WiFi");
        return true;
    } else {
        Serial.println("Failed to connect to WiFi");
        return false;
    }
}

void updateInfo() {
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
    cmd += "&field1="; // Field 1 for BPM
    cmd += String(myBPM);
    cmd += "&field2="; // Field 2 for temperature
    cmd += String(myTemp);
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
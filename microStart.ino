#define START_PIN 2 //example pin, could be changed to any pin

void setup() {
    pinMode(START_PIN, INPUT);
    stopBot();
}

void loop() {
    if (digitalRead(START_PIN) == HIGH) {
        startBot();
    } else {
        stopBot();
    }
}

void startBot() {
    //bot logic, gang
}

void stopBot() {
    //bot logic, gang
}
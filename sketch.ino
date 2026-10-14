
const int TEMP_SENSOR = 34;
const int GAS_SENSOR = 35;

const int RED_LED = 26;
const int GREEN_LED = 27;
const int BUZZER = 25;

const int TEMP_LIMIT = 60;
const int GAS_LIMIT = 65;

void setup() {
  Serial.begin(115200);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.println("IoT Smart Safety Monitoring System");
  Serial.println("System Started Successfully!");
}

void loop() {
  int tempLevel = map(analogRead(TEMP_SENSOR), 0, 4095, 0, 100);
  int gasLevel = map(analogRead(GAS_SENSOR), 0, 4095, 0, 100);

  bool danger = (tempLevel > TEMP_LIMIT ||
                 gasLevel > GAS_LIMIT);

  Serial.print("Temperature Level: ");
  Serial.print(tempLevel);
  Serial.print(" | Gas Level: ");
  Serial.print(gasLevel);

  if (danger) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    tone(BUZZER, 2000);

    Serial.println(" | WARNING: UNSAFE CONDITION!");
  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    noTone(BUZZER);

    Serial.println(" | STATUS: SAFE");
  }

  delay(1000);
}

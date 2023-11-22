const int ldrPin = A0;   // LDR analog input pin
const int ledPin = 7;    // LED output pin
int threshold = 35; // threshold for the Ldr
int delay = 500; // Time delay so our microcontroller can breath

void setup() {
  pinMode(ledPin, OUTPUT);    // Set LED pin as output
  Serial.begin(9600);         // Initialize serial communication
}

void loop() {
  int sensorValue = analogRead(ldrPin);   // Read the sensor value
  int lightIntensity = map(sensorValue, 0, 1023, 0, 100);   // Map the sensor value to a range of 0-100
  Serial.print("Light Intensity: ");
  Serial.print(lightIntensity);
  Serial.println("%");
  if (lightIntensity < threshold) {
    digitalWrite(ledPin, HIGH);    // Turn on the LED
  } else {
    digitalWrite(ledPin, LOW);     // Turn off the LED
  }
  delay(500);   // Delay for stability and to avoid rapid changes
}

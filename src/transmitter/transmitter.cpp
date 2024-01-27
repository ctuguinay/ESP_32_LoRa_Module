#include <HardwareSerial.h>

// Set Button Pin
const int buttonPin = 27;

HardwareSerial gsmSerial(1);  // Use UART1 on ESP32

void setup() {
  // Sync Serial Monitor baud rate with rate set in PlatformIO
  Serial.begin(9600);

  // Verify pin mode
  pinMode(buttonPin, INPUT);

  // GSM module communication, RX on P14, TX on P12
  gsmSerial.begin(115200, SERIAL_8N1, 14, 12);

  // Check if there is data available from the GSM module
  if (gsmSerial.available()) {
    char c = gsmSerial.read();
    Serial.write(c);  // Print the received character to Serial monitor
  }

  // Send initial AT command to the GSM module
  gsmSerial.println("AT");
  delay(1000);  // Wait for the module to respond

  // Read and print the response from the GSM module. Should receive "+OK".
  Serial.print("Output of AT command: ");
  while (gsmSerial.available()) {
    char responseChar = gsmSerial.read();
    Serial.write(responseChar);
  }
  // Print a newline for better readability
  Serial.println();

  // Wait for 5 seconds before sending the next set of commands
  delay(5000);

  // Send RF Frequency band command to the GSM module. Should receive "+OK".
  gsmSerial.println("AT+BAND=915000000,M"); // 915Mhz, which is the center frequency for ISM
  delay(1000);  // Wait for the module to respond

  // Read and print the response from the GSM module
  Serial.print("Output of AT+BAND command: ");
  while (gsmSerial.available()) {
    char responseChar = gsmSerial.read();
    Serial.write(responseChar);
  }
}

void loop() {
  // Read the state of the button pin
  int buttonState = digitalRead(buttonPin);

  // Check if the button is pressed
  if (buttonState == HIGH) {
    Serial.println("Button pressed!");

    // Send message to address 0. Should receive "+OK" from GSM module
    gsmSerial.println("AT+SEND=0,10,_TEST_TEST");
    delay(1000);  // Wait for the module to respond

    // Read and print the response from the GSM module
    Serial.print("Output of AT+SEND command: ");
    while (gsmSerial.available()) {
      char responseChar = gsmSerial.read();
      Serial.write(responseChar);
    }
  }
}

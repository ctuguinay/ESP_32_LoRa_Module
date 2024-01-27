#include <HardwareSerial.h>

HardwareSerial gsmSerial(1);  // Use UART1 on ESP32

void setup() {
  Serial.begin(9600); // Serial monitor
  gsmSerial.begin(115200, SERIAL_8N1, 14, 12);  // GSM module communication, RX on P14, TX on P12
}

void loop() {
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
  Serial.println();  // Print a newline for better readability

  delay(5000);  // Wait for 5 seconds before sending the next set of commands

  // Send RF Frequency band command to the GSM module. Should receive "+OK".
  gsmSerial.println("AT+BAND=915000000,M"); // 915Mhz, which is the center frequency for ISM
  delay(1000);  // Wait for the module to respond

  // Read and print the response from the GSM module
  Serial.print("Output of AT+BAND command: ");
  while (gsmSerial.available()) {
    char responseChar = gsmSerial.read();
    Serial.write(responseChar);
  }
  Serial.println();  // Print a newline for better readability

  delay(5000);  // Wait for 5 seconds before sending the next set of commands
}

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Servo.h>  // Include Servo library for controlling ESC with PWM

// SSID and Password for your ESP Access Point
const char* ssid = "Robot Wifi";
const char* password = "87654321";

// String to store app command state
String command;

// Define the ESC control pin (D1 pin in this example)
const int escPin = D1;  // You can change this pin depending on your setup

// Create a Servo object to control the ESC (ESC works with PWM signals)
Servo esc;

ESP8266WebServer server(80);

// Function to handle the incoming HTTP request
void HTTP_handleRoot(void) {
  if (server.hasArg("State")) {
    command = server.arg("State");  // Store the state argument
    Serial.println("Received command: " + command);  // Print the received command to Serial

    // Convert the command (string) to an integer
    int speed = command.toInt();  // Convert the received string to an integer

    // If the command is valid (between 0 and 100), map it to a PWM range
    if (speed >= 0 && speed <= 100) {
      int pwmValue = map(speed, 0, 10, 0, 2000);  // Map the speed to PWM range (0 to 180)
      esc.write(pwmValue);  // Send PWM signal to ESC to control the motor speed
      Serial.println("Mapped PWM Value: " + String(pwmValue));
    } else {
      Serial.println("Invalid command. Please send a value between 0 and 100.");
    }
  } else {
    Serial.println("No command received.");
  }
  server.send(200, "text/html", "Command received: " + command);  // Respond to the client
}

void setup() {
  Serial.begin(115200);

  // Setting up the NodeMCU as a Wi-Fi Access Point
  WiFi.mode(WIFI_AP);  // Only Access Point mode
  WiFi.softAP(ssid, password);  // Start HOTspot

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  // Attach the ESC pin to the Servo object
  esc.attach(escPin);  // Initialize ESC control on the defined pin
  esc.write(0);  // Start with the motor stopped (0% throttle)

  // Starting WEB-server 
  server.on("/", HTTP_handleRoot);
  server.onNotFound(HTTP_handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();  // Handle incoming HTTP requests
}

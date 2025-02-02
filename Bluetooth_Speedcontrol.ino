#include <Servo.h>

Servo esc;  // Create a Servo object to control the ESC (BLDC motor)

char data;  // Variable to store incoming data from the app

void setup() {
  Serial.begin(9600);      // Start serial communication for debugging
  esc.attach(9);           // Attach the ESC to pin 9 on Arduino (PWM pin)

  // Initialize the ESC to a safe position (min speed)
  esc.writeMicroseconds(1000);  // Minimum pulse width to start the motor (adjust as needed)
  delay(2000);                   // Wait for ESC to initialize
}

void loop() {
  if (Serial.available() > 0) {  // Check if data is available from Bluetooth
    data = Serial.read();        // Read the data sent from the app

    int speed = map(data, '0', '9', 1000, 2000);  // Map received data (0-9) to ESC PWM range (1000-2000)
    
    esc.writeMicroseconds(speed);  // Set the motor speed (PWM signal)
    
    Serial.print("Received speed: ");
    Serial.println(speed);
  }
}

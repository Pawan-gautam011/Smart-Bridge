#include <Servo.h>  // Include Servo library

Servo tap_servo;  // Declare a Servo object named "tap_servo"
int sensor_pin = 13;  // Pin connected to the sensor
int tap_servo_pin = 12;  // Pin connected to the servo
int val;  // Variable to store s

void setup() {
  pinMode(sensor_pin, INPUT);  // Set sensor_pin as an input
  tap_servo.attach(tap_servo_pin);  // Attach the tap_servo to the specified pin
  Serial.begin(9600);   // Start serial communication at 9600 baud rate
}

void loop() {
  val = digitalRead(sensor_pin);  // Read the value from the sensor_pin and store in val variable

  if (val == 0) {  // If sensor detects something
    Serial.println("Water detected. Raising the bridge.");
    tap_servo.write(90);  // Move the tap_servo to 90 degrees
  } else {  // If sensor doesn't detect anything
    tap_servo.write(0);  // Move the tap_servo to 0 degrees which says bridge is down
    Serial.println("No water detected. Lowering the bridge.");
  }
}

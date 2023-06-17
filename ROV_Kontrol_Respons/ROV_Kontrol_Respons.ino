#include <Servo.h> // Library Servo

#define SER_BAUD_RATE 2000000 // Define serial baud rate in arduino 2000000
#define PIN_GRIP 7 // Define servo pin for arm gripper is 7
#define VER_PIN_A 3 // Define thruster pin is 3
#define VER_PIN_B 4 // Define thruster pin is 4
#define HOR_PIN_A 5 // Define thruster pin is 5
#define HOR_PIN_B 6 // Define thruster pin is 6
#define HOR_PIN_C 8 // Define thruster pin is 8
#define HOR_PIN_D 9 // Define thruster pin is 9

/* initialize value for servo as arm gripper */
int GRIP_FULL_GRIP = 0; // Define full grip condition servo angle for gripper
int GRIP_HALF_GRIP = 45; // Define half grip condition servo angle for gripper
int RELEASE_GRIP = 90; // Define full release condition servo angle for gripper

int ZERO_SPEED = 0; // Define zero speed for thruster
int READ_STICK = 'X'; // Initialize serial communication, initiaze as a to consider the value is char 

Servo gripper; // Arm gripper using pin pwm 7
Servo thruster1, thruster2, thruster3, thruster4, thruster5, thruster6; // Thruster using pin 

void setup() {
  /* for serial communication */
  Serial.begin(SER_BAUD_RATE); // Serial monitor switch to 2000000
  
  /* Servo attach */
  gripper.attach(PIN_GRIP, 1000, 2000); // Min max servo value from calibration

  /* Hardcode the servo normal angle */
  gripper.write(RELEASE_GRIP); // Full release condition for gripper

  /* Thruster attach */
  thruster1.attach(VER_PIN_A, 1000, 2000); // Using pin pwm 3 for vertical movement
  thruster2.attach(VER_PIN_B, 1000, 2000); // Using pin pwm 4 for vertical movement
  thruster3.attach(HOR_PIN_A, 1000, 2000); // Using pin pwm 5 for horizontal movement
  thruster4.attach(HOR_PIN_B, 1000, 2000); // Using pin pwm 6 for horizontal movement
  thruster5.attach(HOR_PIN_C, 1000, 2000); // Using pin pwm 8 for horizontal movement
  thruster6.attach(HOR_PIN_D, 1000, 2000); // Using pin pwm 9 for horizontal movement


  /* Hardcode thruster zero speed */
  thruster1.attach(ZERO_SPEED); // Make sure value of thruster horizontal is 1000
  thruster2.attach(ZERO_SPEED); // Make sure value of thruster horizontal is 1000
  thruster3.write(ZERO_SPEED); // Make sure value of thruster vertical is 1000
  thruster4.write(ZERO_SPEED); // Make sure value of thruster vertical is 1000
  thruster5.write(ZERO_SPEED); // Make sure value of thruster vertical is 1000
  thruster6.write(ZERO_SPEED); // Make sure value of thruster vertical is 1000
}

void loop() {
  if (Serial.available() > 0)
  {
    /* Detect input char */
    READ_STICK = Serial.read();
    Serial.println(READ_STICK);

    /* --- Start of range parsing data --- */

    /* slow dive condition */
    if (READ_STICK == 'a')
    {
      
    }
    if (READ_STICK == 'b')
    {
      
    }
    if (READ_STICK == 'c')
    {
      
    }
    /* slow floating condition */
    if (READ_STICK == 'd')
    {
      
    }
    if (READ_STICK == 'e')
    {
      
    }
    /* full release condition*/
    if (READ_STICK == 'f')
    {
      gripper.write(RELEASE_GRIP);
    }
    if (READ_STICK == 'g')
    {
      
    }
    /* half grip condition */
    if (READ_STICK == 'h')
    {
      gripper.write(GRIP_HALF_GRIP);
    }
    /* full grip condition */
    if (READ_STICK == 'i') 
    {
      gripper.write(GRIP_FULL_GRIP);
    }
    /* Shifts slowly to the left condition */
    if (READ_STICK == 'j')
    {
      
    }
    /* Shifts slowly to the right condition */
    if (READ_STICK == 'k')
    {
      
    }
    if (READ_STICK == 'l')
    {
      
    }
    if (READ_STICK == 'm')
    {
      
    }
    if (READ_STICK == 'n')
    {
      
    }
    if (READ_STICK == 'o')
    {
      
    }
    if (READ_STICK == 'p')
    {
      
    }
    if (READ_STICK == 'q')
    {
      
    }
    if (READ_STICK == 'r')
    {
      
    }
    if (READ_STICK == 's')
    {
      
    }
    if (READ_STICK == 't')
    {
      
    }
    if (READ_STICK == 'u')
    {
      
    }
    if (READ_STICK == 'v')
    {
      
    }
    if (READ_STICK == 'w')
    {
      
    }
    if (READ_STICK == 'x')
    {
      
    }
    if (READ_STICK == 'z')
    {
      
    }
    if (READ_STICK == 'z')
    {
      
    }
    if (READ_STICK == 'aa')
    {
      
    }
    if (READ_STICK == 'bb')
    {
      
    }
    if (READ_STICK == 'cc')
    {
      
    }
    
    /* --- End of range parsing data --- */
  }

}
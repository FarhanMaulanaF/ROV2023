#include <Servo.h> // Library Servo

#define SER_BAUD_RATE 2000000 // Define serial baud rate in arduino 2000000
#define PIN_GRIP 7 // Define servo pin for arm gripper is 7
#define PIN_ROLL_GRIP 2 // Define servo pin for arm gripper roller is 2
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
Servo roll_gripper; // Servo for rolling the gripper 2
Servo thruster1, thruster2, thruster3, thruster4, thruster5, thruster6; // Thruster using pin 

void setup() {
  /* for serial communication */
  Serial.begin(SER_BAUD_RATE); // Serial monitor switch to 2000000
  
  /* Servo attach */
  gripper.attach(PIN_GRIP, 1000, 2000); // Min max servo value from calibration
  roll_gripper.attach(PIN_ROLL_GRIP, 1000, 2000); // Min max servo value from calibration

  /* Hardcode the servo normal angle */
  gripper.write(RELEASE_GRIP); // Full release condition for gripper
  roll_gripper.write(GRIP_FULL_GRIP); // Normal condition for gripper roller rotation

  /* Thruster attach */
  thruster1.attach(VER_PIN_A, 1000, 2000); // Using pin pwm 3 for vertical movement
  thruster2.attach(VER_PIN_B, 1000, 2000); // Using pin pwm 4 for vertical movement
  thruster3.attach(HOR_PIN_A, 1000, 2000); // Using pin pwm 5 for horizontal movement
  thruster4.attach(HOR_PIN_B, 1000, 2000); // Using pin pwm 6 for horizontal movement
  thruster5.attach(HOR_PIN_C, 1000, 2000); // Using pin pwm 8 for horizontal movement
  thruster6.attach(HOR_PIN_D, 1000, 2000); // Using pin pwm 9 for horizontal movement


  /* Hardcode thruster zero speed */
  thruster1.write(ZERO_SPEED); // Make sure thruster on stop condition
  thruster2.write(ZERO_SPEED); // Make sure thruster on stop condition
  thruster3.write(ZERO_SPEED); // Make sure thruster on stop condition
  thruster4.write(ZERO_SPEED); // Make sure thruster on stop condition
  thruster5.write(ZERO_SPEED); // Make sure thruster on stop condition
  thruster6.write(ZERO_SPEED); // Make sure thruster on stop condition
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
      thruster1.write(0);
      thruster2.write(0);
      thruster3.write(0);
      thruster4.write(0);
      thruster5.write(0);
      thruster6.write(0);
    }
    /* slow right Yaw condition */
    if (READ_STICK == 'b')
    {
      thruster1.write(0);
      thruster2.write(0);
      thruster3.write(1300);
      thruster4.write(0);
      thruster5.write(1300);
      thruster6.write(0);
    }
    /* slow left Yaw condition */
    if (READ_STICK == 'c')
    {
      thruster1.write(0);
      thruster2.write(0);
      thruster3.write(0);
      thruster4.write(1300);
      thruster5.write(0);
      thruster6.write(1300);
    }
    /* slow floating condition */
    if (READ_STICK == 'd')
    {
      thruster1.write(1300);
      thruster2.write(1300);
      thruster3.write(0);
      thruster4.write(0);
      thruster5.write(0);
      thruster6.write(0);
    }
    /* roll right gripper */
    if (READ_STICK == 'e')
    {
      roll_gripper.write(-90);
    }
    /* full release condition*/
    if (READ_STICK == 'f')
    {
      gripper.write(RELEASE_GRIP);
    }
    /* roll right gripper */
    if (READ_STICK == 'g')
    {
      roll_gripper.write(90);
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
    /* Shifted left slowly condition */
    if (READ_STICK == 'j')
    {
      thruster1.write(0);
      thruster2.write(0);
      thruster3.write(1300);
      thruster4.write(0);
      thruster5.write(0);
      thruster6.write(1300);
    }
    /* Shifted right slowly condition */
    if (READ_STICK == 'k')
    {
      thruster1.write(0);
      thruster2.write(0);
      thruster3.write(0);
      thruster4.write(1300);
      thruster5.write(1300);
      thruster6.write(0);
    }
    /* Shifted back slowly condition */
    if (READ_STICK == 'l')
    {
      thruster1.write(0);
      thruster2.write(0);
      thruster3.write(1300);
      thruster4.write(1300);
      thruster5.write(0);
      thruster6.write(0);
    }
    /* Shifted froward slowly condition */
    if (READ_STICK == 'm')
    {
      thruster1.write(0);
      thruster2.write(0);
      thruster3.write(0);
      thruster4.write(0);
      thruster5.write(1300);
      thruster6.write(1300);
    }
    /* Shifted back rapidly condition */
    if (READ_STICK == 'n')
    {
      thruster1.write(0);
      thruster2.write(0);
      thruster3.write(1700);
      thruster4.write(1700);
      thruster5.write(0);
      thruster6.write(0);
    }
    /* Shifted back slowly condition */
    if (READ_STICK == 'o')
    {
      thruster1.write(0);
      thruster2.write(0);
      thruster3.write(1300);
      thruster4.write(1300);
      thruster5.write(0);
      thruster6.write(0);
    }
    /* Shifted froward rapidly condition */
    if (READ_STICK == 'p')
    {
      thruster1.write(0);
      thruster2.write(0);
      thruster3.write(0);
      thruster4.write(0);
      thruster5.write(1800);
      thruster6.write(1800);
    }
    /* Shifted froward slowly condition */
    if (READ_STICK == 'q')
    {
      thruster1.write(0);
      thruster2.write(0);
      thruster3.write(0);
      thruster4.write(0);
      thruster5.write(1300);
      thruster6.write(1300);
    }
    /* Crab right rapidly condition */
    if (READ_STICK == 'r')
    {
      thruster1.write(0);
      thruster2.write(0);
      thruster3.write(0);
      thruster4.write(1800);
      thruster5.write(1800);
      thruster6.write(0);
    }
    /* Crab right slowly condition */
    if (READ_STICK == 's')
    {
        // Belum dipake karena masih belum berguna umpan yang ini
    }
    /* Crab left rapidly condition */
    if (READ_STICK == 't')
    {
      thruster1.write(0);
      thruster2.write(0);
      thruster3.write(1800);
      thruster4.write(0);
      thruster5.write(0);
      thruster6.write(1800);
    }
    /* Crab left slowly condition */
    if (READ_STICK == 'u')
    {
      // Belum dipake karena masih belum berguna umpan yang ini
    }
    /* fast dive condition */
    if (READ_STICK == 'v')
    {
      thruster1.write(0);
      thruster2.write(0);
      thruster3.write(0);
      thruster4.write(0);
      thruster5.write(0);
      thruster6.write(0);
    }
    /* slow dive condition */
    if (READ_STICK == 'w')
    {
      thruster1.write(0);
      thruster2.write(0);
      thruster3.write(0);
      thruster4.write(0);
      thruster5.write(0);
      thruster6.write(0);
    }
    /* fast floating condition */
    if (READ_STICK == 'x')
    {
      thruster1.write(1800);
      thruster2.write(1800);
      thruster3.write(0);
      thruster4.write(0);
      thruster5.write(0);
      thruster6.write(0);
    }
    /* slow floating condition */
    if (READ_STICK == 'y')
    {
      thruster1.write(1300);
      thruster2.write(1300);
      thruster3.write(0);
      thruster4.write(0);
      thruster5.write(0);
      thruster6.write(0);
    }
    /* fast right Yaw condition */
    if (READ_STICK == 'z')
    {
      thruster1.write(0);
      thruster2.write(0);
      thruster3.write(1800);
      thruster4.write(0);
      thruster5.write(1800);
      thruster6.write(0);
    }
    /* slow right Yaw condition */
    if (READ_STICK == 'A')
    {
      thruster1.write(0);
      thruster2.write(0);
      thruster3.write(1300);
      thruster4.write(0);
      thruster5.write(1300);
      thruster6.write(0);
    }
    /* fast left Yaw condition */
    if (READ_STICK == 'B')
    {
      thruster1.write(0);
      thruster2.write(0);
      thruster3.write(0);
      thruster4.write(1800);
      thruster5.write(0);
      thruster6.write(1800);
    }
    /* slow right Yaw condition */
    if (READ_STICK == 'Z')
    {
      thruster1.write(0);
      thruster2.write(0);
      thruster3.write(0);
      thruster4.write(1300);
      thruster5.write(0);
      thruster6.write(1300);
    }
    
    /* --- End of range parsing data --- */
  }
  else 
  {
      thruster1.write(0);
      thruster2.write(0);
      thruster3.write(0);
      thruster4.write(0);
      thruster5.write(0);
      thruster6.write(0);
  }
}

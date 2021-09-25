#include <Servo.h>

#include "CarDefs.h"

char commandChar;
char steerCommandChar;
char specialCommandChar;

Servo myservo;

void setup() {
    Serial.begin(115200);
    
    pinMode(motor1_EN, OUTPUT);
    pinMode(motor1_A, OUTPUT);
    pinMode(motor1_B, OUTPUT);
    pinMode(motor2_EN, OUTPUT);
    pinMode(motor2_A, OUTPUT);
    pinMode(motor2_B, OUTPUT);
    
    myservo.attach(servoPin);
    myservo.write(angle_val);
}

void loop() {
    receiveCommandsFromEsp();
    
    controlDirection();
    specialControl();
    controlSteering();
    setSpeedToAll(speed_val);
}

void receiveCommandsFromEsp()
{
    char charSniffer = Serial.read();
    //char dummy = Serial.read();
    //Serial.print("Sniffer: "); Serial.println(charSniffer);
    if (charSniffer == '<')
    {
        delay(10);
        commandChar = Serial.read();
        Serial.print("command: "); Serial.println(commandChar);
    }
    else if (charSniffer == '{')
    {
        delay(10);
        steerCommandChar = Serial.read();
        Serial.print("Steer: "); Serial.println(steerCommandChar);
    }
    else if (charSniffer == '[')
    {
        delay(10);
        specialCommandChar = Serial.read();
        Serial.print("special: "); Serial.println(specialCommandChar);
    }
    else if (charSniffer == (byte)'(')
    {
        delay(10);
        //speedChar = (char)Serial.read();
        speed_val = (int)Serial.read();  
        Serial.print("speed: "); Serial.println(speed_val);
    }

}

void controlDirection()
{
    //Serial.print("onBreakRight: "); Serial.println(onBreakRight);
    //Serial.print("onBreakLeft: "); Serial.println(onBreakLeft);
    if (commandChar == 'F')
    {
            //Serial.print("onBreakRight: "); Serial.println(onBreakRight);
             //Serial.print("onBreakLeft: "); Serial.println(onBreakLeft);
         Serial.println("moving foward");
        if (onBreakRight == true)
        {
                       Serial.print("onBreakRight: "); Serial.println(onBreakRight);
            onBreakRight = false;
            onBreakLeft = false;
                        Serial.print("leaving onBreakRight: "); Serial.println(onBreakRight);
            angle_val = 90;
            //myservo.write(angle_val);
        }
        if (onBreakLeft == true)
        {
                        Serial.print("onBreakLeft: "); Serial.println(onBreakLeft);
            onBreakRight = false;
            onBreakLeft = false;
                        Serial.print("leaving onBreakRight: "); Serial.println(onBreakLeft);
            angle_val = 90;
            //myservo.write(angle_val);
        }

        move_forward(speed_val);
    }
    
    else if (commandChar == 'B')
    {
   //     Serial.println("moving backward");

        if (onBreakRight == true)
        {
                       Serial.print("onBreakRight: "); Serial.println(onBreakRight);
            onBreakRight = false;
            onBreakLeft = false;
                        Serial.print("leaving onBreakRight: "); Serial.println(onBreakRight);
            angle_val = 90;
            //myservo.write(angle_val);
        }
        if (onBreakLeft == true)
        {
                        Serial.print("onBreakLeft: "); Serial.println(onBreakLeft);
            onBreakRight = false;
            onBreakLeft = false;
                        Serial.print("leaving onBreakRight: "); Serial.println(onBreakLeft);
            angle_val = 90;
            //myservo.write(angle_val);
        }
        
        move_backward(speed_val);
    }
    
    else if (commandChar == 'S')
    {
        onBreakRight = false;
        onBreakLeft = false;
   //     Serial.println("stop");
        stop_car();
    }
    commandChar = '0';
}

void controlSteering(bool fine_steering=false)
{
    if(fine_steering)
    {
        steer_angle = STEER_ANGLE/2;
    }
    else
    {
        steer_angle = STEER_ANGLE;
    }
    // servo to left
    if(steerCommandChar == 'L')
    { 
      if(angle_val >= steer_angle)
      {     
        angle_val -= steer_angle;
        Serial.print("angle: "); Serial.println(angle_val);
      }
      steerCommandChar = '0';
    } 

    // servo to left 
    else if (steerCommandChar == 'R')
    {
      if(angle_val <= (180 - steer_angle))
      {     
        angle_val += steer_angle;
        Serial.print("angle: "); Serial.println(angle_val);
      }   
      steerCommandChar= '0';     
    } 
    
    //Serial.print("angle: "); Serial.println(angle_val);
    myservo.write(angle_val);
}

void specialControl()
{
    if(specialCommandChar == 'Y')
    {
        specialCommandChar = '0';
        angle_val = 0;
        myservo.write(angle_val);
        break_left(speed_val);
        specialCommandChar = '0';
    }
    else if(specialCommandChar == 'X')
    {
        specialCommandChar = '0';
        angle_val = 180;
        myservo.write(angle_val);
        break_right(speed_val);
        specialCommandChar = '0';
    }
}

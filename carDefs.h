#define STEER_ANGLE 30

const byte motor1_A = 6;
const byte motor1_B = 7;
const byte motor1_EN = 5;

const byte motor2_A = 8;
const byte motor2_B = 9;
const byte motor2_EN = 11;

const byte motorsPins[] = { motor1_A, motor1_B, motor1_EN,
                           motor2_A, motor2_B, motor2_EN };

const byte servoPin = 4;

bool onBreakRight = false;
bool onBreakLeft = false;

int speed_val = 0; 
int angle_val = 90;

enum carDirection{
    Stop,
    Forward,
    Backward
};

carDirection direction = Stop;

void setMotorSpeed(const byte motor_en_pin, int set_speed)
{
    analogWrite(motor_en_pin, set_speed);
}

void setSpeedToAll(int set_speed)
{
    byte en_pins[2] = {motor1_EN, motor2_EN};
    for (int i = 0; i < sizeof(en_pins); i++)
    {
        setMotorSpeed(en_pins[i], set_speed);
    }
}

void move_backward(int speed_val)
{
    digitalWrite(motor1_A, HIGH);
    digitalWrite(motor1_B, LOW);

    digitalWrite(motor2_A, HIGH);
    digitalWrite(motor2_B, LOW);

    setSpeedToAll(speed_val);
}

void move_forward(int speed_val)
{
    digitalWrite(motor1_A, LOW);
    digitalWrite(motor1_B, HIGH);

    digitalWrite(motor2_A, LOW);
    digitalWrite(motor2_B, HIGH);

    setSpeedToAll(speed_val);
}

void stop_car()
{
    digitalWrite(motor1_A, LOW);
    digitalWrite(motor1_B, LOW);

    digitalWrite(motor2_A, LOW);
    digitalWrite(motor2_B, LOW);
}

void break_left(int speed_val)
{
    onBreakLeft = true;
    onBreakRight = false;
        Serial.print("onBreakRight: "); Serial.println(onBreakRight);
    Serial.print("onBreakLeft: "); Serial.println(onBreakLeft);
    Serial.println("break left!");
    digitalWrite(motor1_A, LOW);
    digitalWrite(motor1_B, HIGH);
    setMotorSpeed(motor1_EN, speed_val);
    
    digitalWrite(motor2_A, HIGH);
    digitalWrite(motor2_B, HIGH);
    setMotorSpeed(motor2_EN, 0);
}


void break_right(int speed_val)
{
    onBreakRight = true;
    onBreakLeft = false;
    Serial.print("onBreakRight: "); Serial.println(onBreakRight);
    Serial.print("onBreakLeft: "); Serial.println(onBreakLeft);
    Serial.println("break right!");
    digitalWrite(motor1_A, HIGH);
    digitalWrite(motor1_B, HIGH);
    setMotorSpeed(motor1_EN, 0);
    
    digitalWrite(motor2_A, LOW);
    digitalWrite(motor2_B, HIGH);
    setMotorSpeed(motor2_EN, speed_val);
}

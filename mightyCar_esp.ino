#include <iostream>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ESP8266HTTPClient.h>
//#include <WiFiClient.h>
//#include <AsyncElegantOTA.h>

#include "htmls.h"


#ifndef STASSID
#define STASSID "aloni"
#define STAPSK  "0524663051"
#endif

String speed_in;
int speed_val = 0;
int prevSpeed;

byte speedByte;
 

String cmd_in;
char command = 'S';


String steer_cmd_in;
char steer_command;


String special_cmd_in;
char special_cmd;


AsyncWebServer server(80);

void connect_to_wifi();

void setup() {
  Serial.begin(115200);

  connect_to_wifi();
  
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send_P(200, "text/html", car_html);
  });

  server.on("/car", HTTP_GET, [](AsyncWebServerRequest *request){
        if (request->hasParam("cmd")) {
            cmd_in = request->getParam("cmd")->value();
        }
        request->send_P(200, "text/html", car_html);
        char cmd_in_array[2];
        cmd_in.toCharArray(cmd_in_array, 2);
        command = cmd_in_array[0];
        //Serial.print("command: "); Serial.println(command);
  });

    server.on("/car2", HTTP_GET, [](AsyncWebServerRequest *request){
        if (request->hasParam("cmd")) {
            steer_cmd_in = request->getParam("cmd")->value();
        }
        request->send_P(200, "text/html", car_html);
        char cmd_in_array[2];
        steer_cmd_in.toCharArray(cmd_in_array, 2);
        steer_command = cmd_in_array[0];
        //Serial.print("steer command: "); Serial.println(steer_command);
  });
  
server.on("/car1", HTTP_GET, [](AsyncWebServerRequest *request){
        if (request->hasParam("speed")) {
            speed_in = request->getParam("speed")->value();
            speed_val = speed_in.toInt() * 2.5;
            speedByte = (char)speed_val;
        }
        request->send_P(200, "text/html", car_html);
        //Serial.println(speed_in);
  });

server.on("/special", HTTP_GET, [](AsyncWebServerRequest *request){
        if (request->hasParam("cmd")) {
            special_cmd_in = request->getParam("cmd")->value();
        }
        request->send_P(200, "text/html", car_html);
        char cmd_in_array[2];
        special_cmd_in.toCharArray(cmd_in_array, 2);
        special_cmd = cmd_in_array[0];
        //Serial.print("special command: "); Serial.println(special_cmd);
  });

  Serial.println("Starting HTTP server");
  server.begin();
}

void loop() {
    sendCommands();
}

void connect_to_wifi()
{
      const char *ssid = STASSID;
      const char *password = STAPSK;

// For static IP address
      IPAddress local_IP(10, 0, 0, 222);
      IPAddress gateway(10, 0, 0, 138);
      IPAddress subnet(255, 255, 0, 0);
        
      WiFi.mode(WIFI_STA);
      WiFi.begin(ssid, password);
      
      Serial.println("");
       // set wifi configuration
      if (!WiFi.config(local_IP, gateway, subnet)) {
         Serial.println("STA Failed to configure");
      }
      // Wait for connection
      Serial.println("Connecting to server!");
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
      }
      Serial.println("");
      Serial.print("Connected to ");
      Serial.println(ssid); 
      Serial.print("IP address: ");
      Serial.println(WiFi.localIP());

      WiFi.setAutoReconnect(true);
      WiFi.persistent(true);
}

void sendCommands()
{   
    if(command != '0') 
    {
        sendDirectionCommand();
    }
    if(steer_command != '0') 
    {
        sendSteerCommand();
    }
    if(special_cmd != '0')
    {
        sendSpecialCommand();
    }
    // if speed rise or fall more than 5
    if(speed_val > prevSpeed + 2 || speed_val < prevSpeed - 2)
    {
        sendSpeed();
        prevSpeed = speed_val;
    }
}

void sendDirectionCommand()
{
    char commandBuff[3];
    commandBuff[0] = '<';
    commandBuff[1] = command;
    commandBuff[2] = '>';
    for(int i = 0; i < sizeof(commandBuff); i++)
    {
        Serial.write(commandBuff[i]); 
    }
    command = '0';
}

void sendSteerCommand()
{
    char steerCommandBuff[3];
    steerCommandBuff[0] = '{';
    steerCommandBuff[1] = steer_command;
    steerCommandBuff[2] = '}';
    for(int i = 0; i < sizeof(steerCommandBuff); i++)
    {
        Serial.write(steerCommandBuff[i]); 
    }
    steer_command = '0';
}

void sendSpecialCommand()
{
    char specialCommandBuff[3];
    specialCommandBuff[0] = '[';
    specialCommandBuff[1] = special_cmd;
    specialCommandBuff[2] = ']';
    for(int i = 0; i < sizeof(specialCommandBuff); i++)
    {
        Serial.write(specialCommandBuff[i]); 
    }
    special_cmd = '0';
}

void sendSpeed()
{
    byte speedToSend[] = {'(', speedByte, ')'};
    
    
    for(int i = 0; i < sizeof(speedToSend); i++)
    {
        Serial.write(speedToSend[i]);
    }

}

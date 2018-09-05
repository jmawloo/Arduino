/*
This example shows how to connect to Cayenne using an ESP8266 and send/receive sample data.

The CayenneMQTT Library is required to run this sketch. If you have not already done so you can install it from the Arduino IDE Library Manager.

Steps:
1. If you have not already installed the ESP8266 Board Package install it using the instructions here: https://github.com/esp8266/Arduino#installing-with-boards-manager.
2. Select your ESP8266 board from the Tools menu.
3. Set the Cayenne authentication info to match the authentication info from the Dashboard.
4. Set the network name and password.
5. Compile and upload the sketch.
6. A temporary widget will be automatically generated in the Cayenne Dashboard. To make the widget permanent click the plus sign on the widget.
*/

//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>

// WiFi network info.
char ssid[] = "IoT2018";
char wifiPassword[] = "00000000";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
/*Sarfaraaz's stuff
char username[] = "6c501cb0-e5cf-11e7-a7fa-d17981e51595";
char password[] = "637ddc505ab95dac05fa13dcb42c1d429380f395";
char clientID[] = "d3a34560-2f97-11e8-b1c6-0d0b749c9848";
*/
char username[] = "6b8ca860-2f8b-11e8-8d26-a9f2d7c18bc5";
char password[] = "304f3355e530b16abb2c617ebdbf82159f469b2b";
char clientID[] = "25112b50-2fad-11e8-ac80-85ded0fe5d33"; 

double val = 0;
int sensorPin = A0; //For the motion detection.
void setup() {
	Serial.begin(9600);
	Cayenne.begin(username, password, clientID, ssid, wifiPassword);
  pinMode(sensorPin,INPUT); //Sound sensor
}

void loop() {
	Cayenne.loop();
 //Anything after this takes in info from the sensors.
 val = analogRead(sensorPin);
 Serial.println(val);//Sound sensor
}

// Default function for sending sensor data at intervals to Cayenne.
// You can also use functions for specific channels, e.g CAYENNE_OUT(1) for sending channel 1 data.
CAYENNE_OUT_DEFAULT()
{
	// Write data to Cayenne here. This example just sends the current uptime in milliseconds on virtual channel 0.
	Cayenne.virtualWrite(0, millis());
  Cayenne.virtualWrite(1, val);
	// Some examples of other functions you can use to send data.
	//Cayenne.celsiusWrite(1, 22.0);
	//Cayenne.luxWrite(2, 700);
	//Cayenne.virtualWrite(3, 50, TYPE_PROXIMITY, UNIT_CENTIMETER);
}

// Default function for processing actuator commands from the Cayenne Dashboard.
// You can also use functions for specific channels, e.g CAYENNE_IN(1) for channel 1 commands.
CAYENNE_IN_DEFAULT()
{
	CAYENNE_LOG("Channel %u, value %s", request.channel, getValue.asString());
	//Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}


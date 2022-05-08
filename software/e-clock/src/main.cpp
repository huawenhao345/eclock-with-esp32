#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <time.h>
#include "WeatherNow.h"

const char *ssid = "斯是陋室";                //Your wifi's name
const char *password = "wwdxthsjlcsrlq";     //Your wifi's password

const char *ntpServer = "us.pool.ntp.org";
const long gmtOffset_sec = 3600 * 7;
const int daylightOffset_sec = 3600;

// void printLocalTime()                    //Time print test
// {
//   struct tm timeinfo;
//   if (!getLocalTime(&timeinfo))
//   {
//     Serial.println("Failed to obtain time");
//     return;
//   }
//   Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
// }

void setup()
{
  Serial.begin(9600);

  // connect to WiFi
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)     //WiFi connect test
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected");

  // init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  // printLocalTime();

  // disconnect WiFi as it's no longer needed
  // WiFi.disconnect(true);
  // WiFi.mode(WIFI_OFF);
}

void loop()
{
  
}
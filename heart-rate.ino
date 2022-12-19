#include <WiFi.h>
#include <ThingSpeak.h>
WiFiClient client;

long myChannelNumber = 1836580;
const char myWriteAPIKey[] = "EO89ON095440TE1W";

const char* ssid= "500";
const char* password ="hello3214";

int PulseSensorPurplePin = 32; 
int LED13 = 13;

int Signal;                // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 550;
void setup() 
{
  Serial.begin(115200);
  pinMode(LED13,OUTPUT);
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("ESP32 is connected to the internet ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}
void loop() 
{
  Signal = analogRead(PulseSensorPurplePin)/40;
  Serial.println(Signal);
  ThingSpeak.writeField(myChannelNumber, 1,Signal, myWriteAPIKey);
}

#include <MQTTClient.h>
#include <Bridge.h>
#include <BridgeClient.h>

BridgeClient net;
MQTTClient client;
unsigned long lastMillis = 0;
const int L1 = 2;


void setup() {
    // put your setup code here, to run once:
    Bridge.begin();
    Serial.begin(9600);
    client.begin("52.16.200.13", net);
    pinMode(L1, OUTPUT);
  
    connect();
    client.onMessage(messageReceived);
}
  
void loop() {
    
   client.loop();
  
    if(!client.connected()) {connect();}
  
    // publish a message roughly every second.
    if(millis() - lastMillis > 1000) {
      lastMillis = millis();
      client.publish("/hello", "world");
    }
 }

void connect() {
 
  Serial.print("connecting...");
  while (!client.connect("arduino", "b2ec5fb1", "08dddf858eb2a12c")) {Serial.print(".");}
  Serial.println("\n connected!");
  
  client.subscribe("/home/garden/fountain");


}


void messageReceived(String &topic, String &payload) {
  Serial.print("incoming: ");
  Serial.print(topic);
  Serial.print(" - ");
  Serial.print(payload);
  Serial.println();

  if(payload == "ON"){setLedON();}
  if(payload == "OFF"){setLedOFF();}
}

void setLedON(){
   digitalWrite(L1, HIGH); //allumer L1
}

void setLedOFF(){
   digitalWrite(L1, LOW); //eteindre L1
}

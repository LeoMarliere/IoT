#include <MQTTClient.h>
#include <Bridge.h>
#include <BridgeClient.h>

BridgeClient net;
MQTTClient client;

void setup() {
  // put your setup code here, to run once:
  Bridge.begin();
  Serial.begin(9600);
  client.begin("52.16.200.13", net);
  connect();
  //client.onMessage(messageReceived);
}

void loop() {
  // put your main code here, to run repeatedly:
  client.loop();
  if(!client.connected()) {connect();}
  
  int i = 0;
  while (i<100){
    client.publish("Temperature", "25degré, wallah y fait chaud");
    delay(10000);
    i++;
  }

}

void connect() {
 
  Serial.print("connecting...");
  while (!client.connect("arduino", "b2ec5fb1", "08dddf858eb2a12c")) {Serial.print(".");}
  Serial.println("\n connected!");
  
  client.subscribe("/home/garden/fountain");


}

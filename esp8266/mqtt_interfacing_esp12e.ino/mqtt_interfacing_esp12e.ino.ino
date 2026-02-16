
#include <ESP8266WiFi.h>//this is for wifi coneection with my network
#include <PubSubClient.h> // this library is for the mqtt communication used to publish the data obtained 

#define PIR D5// most suitable can use d6 and d7 also ig 

const char* ssid = "Abhinav's A35";
const char* password = "12345678";
const char* mqtt_server = "test.mosquitto.org";//tried to use roker.hivemq.com took time connecting 

WiFiClient espClient; // provides with a proepr channel for connection 
PubSubClient client(espClient); // used for mqtt messaging 

unsigned long lastMsg = 0;

// to setup wifi connection 
void setup_wifi() {
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password); //ssid is wifi hotspot name btw 

//waiting until it is connected 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");
}

//when mqtt disconnects function is to reconnect it 
void reconnect() {
//loop until it's connected again 
  while (!client.connected()) {

    Serial.print("MQTT connecting...");

    String clientId = "ESP8266-";             //creating unique id to filter outb
    clientId += String(random(0xffff), HEX);

    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
    } else {
      Serial.print("Failed, rc=");
      Serial.println(client.state());
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);// serial monitor communication speed 
  pinMode(PIR, INPUT);

  setup_wifi(); //wiifi fucntion called 

  client.setServer(mqtt_server, 1883); // client server is sset as mqtt server cuz this is inclded library 
}

void loop() {

  if (!client.connected()) reconnect();

  client.loop();

  unsigned long now = millis();

  if (now - lastMsg > 2000) {       //publish every 2s ideally it shd be more than 5s ig to be efficient 

    lastMsg = now;

    client.publish("hotel/room101/motion", "TEST");

    Serial.println("Publishing TEST");
  }
}







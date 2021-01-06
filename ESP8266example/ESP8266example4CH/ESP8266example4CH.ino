#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

const char* ssid = "your-wifi-ssid";
const char* password = "your-wifi-password";
const char* mqtt_server = "raspberry-pi-IP";

const int Relay1 = 0; //D3
const int Relay2 = 2; //D4
const int Relay3 = 14;//D5
const int Relay4 = 12;//D6

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;
char json_c[200];
bool state = false;

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.println();
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    json_c[i] = payload[i];
  }
  StaticJsonDocument<200> doc;
  DeserializationError error = deserializeJson(doc, json_c);
  
  if (strcmp(topic,"device/relay1") == 0) {
    state = doc["on"];
    Serial.println(state);
    if (state == false){
      digitalWrite(Relay1, LOW);
      Serial.println("Relay 1 apagado");
    }
    if (state == true){
      digitalWrite(Relay1, HIGH);
      Serial.println("Relay 1 encendido");
    }
  }
  if (strcmp(topic,"device/relay2") == 0) {
    state = doc["on"];
    Serial.println(state);
    if (state == false){
      digitalWrite(Relay2, LOW);
      Serial.println("Relay 2 apagado");
    }
    if (state == true){
      digitalWrite(Relay2, HIGH);
      Serial.println("Relay 2 encendido");
    }
  }
  if (strcmp(topic,"device/relay3") == 0) {
    state = doc["on"];
    Serial.println(state);
    if (state == false){
      digitalWrite(Relay3, LOW);
      Serial.println("Relay 3 apagado");
    }
    if (state == true){
      digitalWrite(Relay3, HIGH);
      Serial.println("Relay 3 encendido");
    }
  }
  if (strcmp(topic,"device/relay4") == 0) {
    state = doc["on"];
    Serial.println(state);
    if (state == false){
      digitalWrite(Relay4, LOW);
      Serial.println("Relay 4 apagado");
    }
    if (state == true){
      digitalWrite(Relay4, HIGH);
      Serial.println("Relay 4 encendido");
    }
  }
}
boolean reconnect() {
 if (client.connect("ESP8266Client")) {
   client.subscribe("device/relay1");
   client.subscribe("device/relay2");
   client.subscribe("device/relay3");
   client.subscribe("device/relay4");
   return client.connected();
 }
 Serial.println("I think connect failed.");
 return 0;
}
void setup() {
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);
  
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  delay(1000);
}

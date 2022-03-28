// Including Libraries
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>

/// Declartion and initialization of WIFI Username, Password and mqtt server
const char* ssid = "Umer AAA";
const char* password = "01011968";
const char* mqtt_server = "test.mosquitto.org";

// Subscribed Topics
#define sub0 "LED1/led1"
#define sub1 "LED2/led2"
#define sub2 "LED3/led3"
#define sub3 "LED4/led4"
#define sub4 "LED5/led5"
#define sub5 "LED6/led6"
#define sub6 "LED7/led7"
#define sub7 "LED8/led8"
#define sub8 "LED9/led9"

#define Blink "Blink/blink"

// Establishing Wifi Connection
WiFiClient ESPClient;
PubSubClient client(ESPClient);

String Bulb = "";

void setup_wifi()
{
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while(WiFi.status()!=WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("WiFi Connected!");
  Serial.print("ESP_IP_Address: ");
  Serial.println(WiFi.localIP());
  
  
}

void callback(char* topic, byte* payload, unsigned int length) 
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  
  if(strstr(topic, sub0))///////////////////////// LED1
  {
    for (int i = 0; i < length; i++) 
    {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    if((char)payload[0] == '1')
    {
      digitalWrite(D0, HIGH);
      Serial.println("LED 1 ON");    
    }
    else
    {
      digitalWrite(D0, LOW);
      Serial.println("LED 1 OFF");
    }
  }
  else if(strstr(topic, sub1)) ///////////////////////// LED2
  {
    for (int i = 0; i < length; i++) 
    {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    if((char)payload[0] == '1')
    {
      digitalWrite(D1, HIGH);
      Serial.println("LED 2 ON");    
    }
    else
    {
      digitalWrite(D1, LOW);
      Serial.println("LED 2 OFF");
    }
  }
  else if(strstr(topic, sub2)) //////////////////// LED3
  {
    for (int i = 0; i < length; i++) 
    {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    if((char)payload[0] == '1')
    {
      digitalWrite(D2, HIGH);
      Serial.println("LED 3 ON");    
    }
    else
    {
      digitalWrite(D2, LOW);
      Serial.println("LED 3 OFF");
    }
  }
  else if(strstr(topic, sub3))////////////////////// LED4
  {
    for (int i = 0; i < length; i++) 
    {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    if((char)payload[0] == '1')
    {
      digitalWrite(D3, HIGH);
      Serial.println("LED 4 ON");    
    }
    else
    {
      digitalWrite(D3, LOW);
      Serial.println("LED 4 OFF");
    }
  }
  else if(strstr(topic, sub4)) ///////////////////// LED5
  {
    for (int i = 0; i < length; i++) 
    {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    if((char)payload[0] == '1')
    {
      digitalWrite(D4, HIGH);
      Serial.println("LED 5 ON");    
    }
    else
    {
      digitalWrite(D4, LOW);
      Serial.println("LED 5 OFF");
    }
  }
  else if(strstr(topic, sub5))///////////////////// LED6
  {
    for (int i = 0; i < length; i++) 
    {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    if((char)payload[0] == '1')
    {
      digitalWrite(D0, HIGH); 
      digitalWrite(D1, HIGH);
      digitalWrite(D2, HIGH);
      digitalWrite(D3, HIGH);
      
      digitalWrite(D6, HIGH);
      digitalWrite(D7, HIGH);
      digitalWrite(D8, HIGH);
      Serial.println("LED 6 ON");    
    }
    else
    {
      digitalWrite(D0, LOW); 
      digitalWrite(D1, LOW);
      digitalWrite(D2, LOW);
      digitalWrite(D3, LOW);
      
      digitalWrite(D6, LOW);
      digitalWrite(D7, LOW);
      digitalWrite(D8, LOW);
      Serial.println("LED 6 OFF");
    }
  }
  else if(strstr(topic, sub6))
  {
    for (int i = 0; i < length; i++) 
    {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    if((char)payload[0] == '1')
    {
      digitalWrite(D6, HIGH);
      Serial.println("LED 7 ON");    
    }
    else
    {
      digitalWrite(D6, LOW);
      Serial.println("LED 7 OFF");
    }
  }
  else if(strstr(topic, sub7))
  {
    for (int i = 0; i < length; i++) 
    {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    if((char)payload[0] == '1')
    {
      digitalWrite(D7, HIGH);
      Serial.println("LED 8 ON");    
    }
    else
    {
      digitalWrite(D7, LOW);
      Serial.println("LED 8 OFF");
    }
  }
  else if(strstr(topic, sub8))
  {
    for (int i = 0; i < length; i++) 
    {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    if((char)payload[0] == '1')
    {
      digitalWrite(D8, HIGH);
      Serial.println("LED 9 ON");    
    }
    else
    {
      digitalWrite(D8, LOW);
      Serial.println("LED 9 OFF");
    }
  }
  else
  {
    Serial.println("unsubscribed topic");
  }

//  // Switch on the LED if an 1 was received as first character
//  if ((char)payload[0] == '1') {
//    digitalWrite(BUILTIN_LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
//  } 
//  else
//  {
//    digitalWrite(BUILTIN_LED, HIGH);  // Turn the LED off by making the voltage HIGH
//  }

}

void reconnect1()
{
  // Loop until we're reconnected
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str()))
    {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic", "hello world");
      // ... and resubscribe
      //client.subscribe("esp8266/output");
      client.subscribe(sub0);
      client.subscribe(sub1);
      client.subscribe(sub2);
      client.subscribe(sub3);
      client.subscribe(sub4);
      client.subscribe(sub5);
      client.subscribe(sub6);
      client.subscribe(sub7);
      client.subscribe(sub8);
      client.subscribe(Blink);
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void setup() {
  
  // put your setup code here, to run once:
  // Relays
  pinMode(D0, OUTPUT); // Relay 1
  pinMode(D1, OUTPUT); // Relay 2
  pinMode(D2, OUTPUT); // Relay 3
  pinMode(D3, OUTPUT); // Relay 4
  
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT); // LED 1
  pinMode(D7, OUTPUT); // LED 2
  pinMode(D8, OUTPUT); // LED 3

  digitalWrite(D0, HIGH); 
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  
  digitalWrite(D4, LOW);
  digitalWrite(D5, LOW);
  digitalWrite(D6, LOW);
  digitalWrite(D7, LOW);
  digitalWrite(D8, LOW);
  
  Serial.begin(9600);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
   
}

void loop() 
{
  if(!client.connected())
  {
    reconnect1();
  }
  client.loop();
}

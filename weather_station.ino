#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Arduino_JSON.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(D1, D2, D3, D5, D6, D7);

const char* ssid = "WIFI_SSID";
const char* password = "WIFI_PSWD";

String openWeatherMapApiKey = "xxxxxxxxxxxxxxxxxxxxxxxxx";  //API key
String city = "xxxxxxxx";
String countryCode = "xx";

unsigned long lastTime = 0;
unsigned long timerDelay = 10000;

String jsonBuffer;

void setup() {
  Serial.begin(115200);
  lcd.begin(16,2);
  lcd.print("Weather station");
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  lcd.setCursor(0,0);
  lcd.print(" WIFI connected");
  lcd.setCursor(1,1);
  lcd.print(WiFi.localIP());
  delay(1000);
  lcd.clear();
}

void loop()
{
  
  if ((millis() - lastTime) > timerDelay) {

    if(WiFi.status()== WL_CONNECTED){
      String serverPath = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "," + countryCode + "&APPID=" + openWeatherMapApiKey;
      
      jsonBuffer = httpGETRequest(serverPath.c_str());
      Serial.println(jsonBuffer);
      JSONVar myObject = JSON.parse(jsonBuffer);
      
      if(JSON.typeof(myObject) == "undefined")
      {
        Serial.println("Parsing input failed!");
        return;
      }
    
      Serial.print("JSON object = ");
      Serial.println(myObject);
      Serial.print("Temperature: ");
      int temp=myObject["main"]["temp"];
      Serial.println(temp-273);
      lcd.setCursor(0,0);
      lcd.print("Temperature: ");
      lcd.setCursor(12,0);
      lcd.print(temp-273);
      lcd.setCursor(15,0);
      lcd.print("C");
      Serial.print("Pressure: ");
      Serial.println(myObject["main"]["pressure"]);
      Serial.print("Humidity: ");
      Serial.println(myObject["main"]["humidity"]);
      lcd.setCursor(2,1);
      lcd.print("Humidity : ");
      lcd.setCursor(12,1);
      lcd.print(myObject["main"]["humidity"]);
      lcd.setCursor(15,1);
      lcd.print("%");
      Serial.print("Wind Speed: ");
      Serial.println(myObject["wind"]["speed"]);
      Serial.print("Longitude: ");
      Serial.println(myObject["coord"]["lon"]);
      Serial.print("Latitude: ");
      Serial.println(myObject["coord"]["lat"]);
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}

String httpGETRequest(const char* serverName)
{
  WiFiClient client;
  HTTPClient http;
  http.begin(client, serverName);
  int httpResponseCode = http.GET();
  
  String payload = "{}"; 
  
  if(httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  http.end();
  return payload;
}

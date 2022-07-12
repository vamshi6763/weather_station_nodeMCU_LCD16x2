# weather_station
Weather report on LCD using NodeMCU and openweathermap.org


Libraries to be installed:
1. LiquidCrystal
2. Arduino_JSON

Components required:
1. NodeMCU
2. LCD 16x2
3. jumpwires
4. openweather API key

NOTE: Install NodeMCU drivers for arduino IDE.

Procedure:
1. Goto sketch -> include library -> manage libraries.
2. Search for "LiquidCrystal" by Arduino, then click on install.
3. Search for "Arduino_JSON" by Arduino, then click on install.
4. Replace "WIFI_SSID" with your wifi name and replace "WIFI_PSWD" with your wifi password.
5. In line 12 of code, Enter your API key from the openweathermap.org.
6. In line 13 and 14, Enter your city name and country code as per your location in openweathermap.org respectively.
7. Now upload the program by selecting the correct board and port.


How to get an API key from openweather map:
1. goto the site -> https://openweathermap.org/
2. create and account.
3. goto homepage -> click your name on the top right -> select My API keys.
![Screenshot (10)](https://user-images.githubusercontent.com/101927825/178481667-5c1441a5-1b06-48e1-8898-d53ee9f47063.png)
4. Here you can see your cityname and country code of your location.
5. In the "MY API keys" section, we can use the default API key or we can generate a new API key.
6. Now use this API key in your program.

Connections:

![16X2-LCD-PINS](https://user-images.githubusercontent.com/101927825/178484376-1b380a87-cd7a-46b3-a445-68ff3cb3b736.png)

    LCD    -->     NodeMCU
1. VSS --> GND
2. VDD --> vin
3. VO --> from pot
4. RS --> D1
5. RW --> GND
6. E --> D2
7. D0 --> No connection
8. D1 --> No connection
9. D2 --> No connection
10. D3 --> No connection
11. D4 --> D3
12. D5 --> D5
13. D6 --> D6
14. D7 --> D7
15. A --> 3.3v
16. K --> GND


OUTPUT:
![20220712_002438](https://user-images.githubusercontent.com/101927825/178482269-8f9d1df3-f1a1-4815-8f9c-00fd9422d083.jpg)

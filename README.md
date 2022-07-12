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


OUTPUT:
![20220712_002438](https://user-images.githubusercontent.com/101927825/178482269-8f9d1df3-f1a1-4815-8f9c-00fd9422d083.jpg)

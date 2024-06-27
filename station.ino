#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 3     // Pin which is connected to the DHT sensor
#define DHTTYPE DHT22   // DHT 22 (AM2302)

DHT dht(DHTPIN, DHTTYPE);

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  dht.begin();
  if(!display.begin(SSD1306_I2C_ADDRESS, OLED_RESET)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.print("Weather Station");
  display.display();
}

void loop() {
  // Reading temperature and humidity
  float humidity = dht.readHumidity();
  float temperatureC = dht.readTemperature();
  float temperatureF = temperatureC * 9.0 / 5.0 + 32.0;

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperatureC)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Printing data to serial monitor
  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(temperatureF);
  Serial.println(F("°F "));

  // Printing data to the OLED display
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Weather Station");
  display.setCursor(0,20);
  display.print("Temp: ");
  display.print(temperatureF);
  display.print(" F");
  display.setCursor(0,40);
  display.print("Humidity: ");
  display.print(humidity);
  display.print(" %");
  display.display();

  // Delay for 1 minute
  delay(60000);
}

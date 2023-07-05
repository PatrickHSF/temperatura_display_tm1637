/* Arduino example sketch to display DHT11 temperature readings on a TM1637 4-digit 7-segment display. More info: www.www.makerguides.com */

// Inclua as bibliotecas:
#include <TM1637Display.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

// definindo os pinos
#define CLK 2
#define DIO 3
#define DHTPIN 4

// criando as variaveis
int temperature_celsius;
int temperature_fahrenheit;

// Criar símbolo de grau Celsius:
const uint8_t celsius[] = {
  SEG_A | SEG_B | SEG_F | SEG_G,  // Circle
  SEG_A | SEG_D | SEG_E | SEG_F   // C
};

// Crie o símbolo do grau Fahrenheit:
const uint8_t fahrenheit[] = {
  SEG_A | SEG_B | SEG_F | SEG_G,  // Circle
  SEG_A | SEG_E | SEG_F | SEG_G   // F
};

// Defina o tipo DHT, descomente qualquer tipo que esteja usando!
#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Criar objeto de exibição do tipo TM1637Display:
TM1637Display display = TM1637Display(CLK, DIO);
// Criar objeto dht do tipo DHT:
DHT dht = DHT(DHTPIN, DHTTYPE);

void setup() {
  // Definir o brilho da tela (0-7):
  display.setBrightness(0);
  // Limpar o visor:
  display.clear();
  // Sensor de configuração:
  dht.begin();
  // Inicie a comunicação serial a uma taxa de transmissão de 9600:
  Serial.begin(9600);
  // Aguarde a abertura do console:
  delay(2000);
}

void loop() {
  // Leia a temperatura em Celsius e Fahrenheit:
  temperature_celsius = dht.readTemperature();
  temperature_fahrenheit = dht.readTemperature(true);
  // Imprima a temperatura no Serial Monitor:
  Serial.println(temperature_celsius);
  //Serial.println(temperature_fahrenheit);

  // Mostre a temperatura no display do TM1637:
  display.showNumberDec(temperature_celsius, false, 2, 0);
  display.setSegments(celsius, 2, 2);

  delay(2000);

  //display.showNumberDec(temperature_fahrenheit, false, 2, 0);
  //display.setSegments(fahrenheit, 2, 2);

  //delay(2000);
}
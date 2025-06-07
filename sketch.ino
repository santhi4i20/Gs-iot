#include <DHT.h>
#include <ArduinoJson.h>



// --- PINOS ---
#define TRIG_PIN   8      // TRIG do HC-SR04
#define ECHO_PIN   9      // ECHO do HC-SR04
#define DHTPIN     7      // DATA do DHT22
#define RAINPIN    A0     // Potenciômetro (simula sensor de chuva)



// --- CONFIGURAÇÃO DO DHT22 ---
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);





void setup() {

  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  dht.begin();

  Serial.println("Sistema iniciado com sucesso.");
}



float lerNivelAgua() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duracao = pulseIn(ECHO_PIN, HIGH, 30000);
  float distancia = duracao * 0.034 / 2.0;

  return distancia;
}




void loop() {
  
  float nivel = lerNivelAgua();
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();
  int valorChuva = analogRead(RAINPIN);
  bool estaChovendo = valorChuva < 500; // ajuste conforme teste

  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Erro ao ler DHT22.");

    delay(2000);
    return;
  }


  StaticJsonDocument<256> doc;

  doc["agua_cm"] = nivel;
  doc["chuva"] = estaChovendo;
  doc["umidade"] = umidade;
  doc["temperatura"] = temperatura;

  char buffer[256];
  serializeJsonPretty(doc, buffer);
  Serial.println(buffer);

  delay(5000);

}

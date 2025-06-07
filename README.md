# Projeto SafeWater – Global Solution 2025

Este projeto foi desenvolvido como parte do **Global Solution 2025 da FIAP**, com foco em criar uma solução tecnológica para monitoramento de enchentes em tempo real, utilizando sensores conectados via Arduino Uno e simulação no Wokwi.

## Objetivo

Oferecer um sistema acessível e funcional que permita:
- Medir o nível da água em regiões de risco
- Detectar chuva e condições de umidade elevada
- Exibir os dados em tempo real no Serial Monitor
- Servir de base para integração com plataformas futuras como dashboards ou envio MQTT

## Tecnologias Utilizadas

- **Arduino Uno (via Wokwi)** – Microcontrolador principal  
- **HC-SR04 Ultrassônico** – Sensor de nível da água  
- **DHT22** – Sensor de temperatura e umidade  
- **Potenciômetro** – Simula sensor de chuva analógico  
- **ArduinoJson + DHT.h** – Bibliotecas para leitura e formatação dos dados  

## Simulação no Wokwi

Link do projeto Wokwi:  
[https://wokwi.com/projects/433132003366776833](https://wokwi.com/projects/433132003366776833)

A cada 5 segundos, o sistema coleta os dados e os imprime em formato JSON:

```json
{
  "agua_cm": 7.42,
  "chuva": true,
  "umidade": 85.3,
  "temperatura": 26.4
}

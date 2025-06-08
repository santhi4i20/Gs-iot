## SafeWater – Global Solution FIAP 2025
Este projeto foi desenvolvido como parte do Global Solution da FIAP em 2025. O objetivo é propor uma solução tecnológica para monitoramento e suporte em situações de enchentes e alagamentos em áreas urbanas, unindo sensores físicos, conectividade e visualização de dados em tempo real.

## Objetivo
Ajudar a população e os órgãos públicos a monitorar áreas de risco de enchentes, receber alertas em tempo real e acessar dados ambientais críticos como umidade, temperatura e nível da água.

## Solução
Desenvolvemos um sistema baseado em Arduino e IoT com três sensores:

HC-SR04 (Ultrassônico) – Mede o nível da água em centímetros.

DHT22 – Monitora a umidade relativa do ar e a temperatura.

Potenciômetro – Simula um sensor de chuva (valor analógico).

Os dados são enviados em formato JSON para o monitor serial, e posteriormente integrados ao Node-RED via protocolo MQTT.

## Tecnologias Utilizadas
Arduino Uno (via Wokwi) – Microcontrolador principal

Sensores: HC-SR04, DHT22, Potenciômetro

Node-RED – Gateway para visualização e integração de dados

MQTT (Mosquitto Broker local) – Comunicação entre o Arduino e o painel

Dashboard do Node-RED – Interface para visualização em tempo real

## O que foi feito no Node-RED
No Node-RED, criamos um fluxo que:

Simula a publicação de dados via MQTT no tópico safewater/arduino/data.

Processa os dados recebidos em JSON, fazendo o parse dos campos.

Exibe as informações na dashboard por meio de três medidores (nível da água, temperatura e umidade).

Permite o monitoramento em tempo real via URL local: http://127.0.0.1:1880/ui.


## Vídeo de Apresentação
Assista ao vídeo de apresentação do projeto:
https://youtu.be/7J9_lbeBuoQ?feature=shared

## Código Arduino
O código lê os dados dos sensores e envia um JSON com os campos:

json
Copiar
Editar
{
  "agua_cm": 13.5,
  "chuva": true,
  "umidade": 82.6,
  "temperatura": 24.1
}
Esse JSON é transmitido a cada 5 segundos via Serial.

## Integrantes
Henrique Pecora Vieira de Souza – RM556612

Santhiago De Gobbi Barros de Souza – RM98420

Lívia de Oliveira Lopes – RM556281

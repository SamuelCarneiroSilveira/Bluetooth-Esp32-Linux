#include "Arduino.h"
#include "BluetoothSerial.h"

BluetoothSerial ESP_BT; // Cria um objeto para o Bluetooth

void setup() {
  pinMode(2, OUTPUT); // Configura a GPIO2 como saída
  digitalWrite(2, LOW); // Inicializa a GPIO2 como desligada

  Serial.begin(115200); // Inicia a comunicação serial
  ESP_BT.begin("ESP32_Test_BT"); // Inicia o Bluetooth com o nome "ESP32_Test_BT"

  Serial.println("Bluetooth device is ready to pair");
}

void loop() {
  if (ESP_BT.available()) { // Verifica se há dados disponíveis para ler
    String msg = ESP_BT.readString(); // Lê a mensagem recebida
    Serial.println("Received: " + msg); // Exibe a mensagem no Serial Monitor

    if (msg == "ON") {
      digitalWrite(2, HIGH); // Liga a GPIO2
      ESP_BT.println("GPIO2 ligado");
    } else if (msg == "OFF") {
      digitalWrite(2, LOW); // Desliga a GPIO2
      ESP_BT.println("GPIO2 desligado");
    } else {
      ESP_BT.println("Comando não reconhecido");
    }
  }
}

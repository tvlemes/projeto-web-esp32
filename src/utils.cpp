#include <utility>
#include <SPIFFS.h>
#include <Arduino.h>
#include "utils.h"

// Função para ler a Temperatura interna do ESP32
float temp() {
  float temperature = temperatureRead(); 
  return temperature;
}

// Função para retornar o Espaço em Disco
std::pair<int, int> storage() {
  // Obtém as informações de armazenamento
  unsigned int totalBytes = SPIFFS.totalBytes();
  unsigned int usedBytes = SPIFFS.usedBytes();

  // Retorna o par de valores
  return std::make_pair(totalBytes, usedBytes);
}
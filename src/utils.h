#include <utility>
#include <SPIFFS.h>

#ifndef UTILS
#define UTILS

// Função para ler a Temperatura interna do ESP32
float temp();

// Função para retornar o Espaço em Disco
std::pair<int, int> storage();

#endif

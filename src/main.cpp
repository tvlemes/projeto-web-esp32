
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include "routes.h"

// Configuração da rede Wi-Fi
const char* ssid = "Rosimar2.4g";
const char* password = "92900606";

// Cria o servidor na porta 80
AsyncWebServer server(80);  

void setup() {
  Serial.begin(115200);

  // Conecta-se ao Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado ao Wi-Fi!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());

  // Função das rotas
  privateRoutes(server);

  // Inicia o servidor
  server.begin();  
  Serial.println("Servidor iniciado!");
}

void loop() {

}


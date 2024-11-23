#include <SPIFFS.h>
#include <ESPAsyncWebServer.h>
#include "routes.h"
#include "utils.h"

// Função das rotas
void privateRoutes(AsyncWebServer& server) {
    // Inicializa o SPIFFS
    if (!SPIFFS.begin(true)) {
      Serial.println("Erro ao montar o sistema de arquivos SPIFFS");
      return;
    }

    // Serve o arquivo index.html
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
      request->send(SPIFFS, "/index.html", "text/html");
    });

    // Serve o arquivo dashboard.html
    server.on("/pages/dashboard.html", HTTP_GET, [](AsyncWebServerRequest *request) {
      float temperature = temp(); 
      auto space = storage();
      int availableBytes = space.first - space.second;

      // Lê o arquivo HTML do SPIFFS
      String html;
      File file = SPIFFS.open("/pages/dashboard.html", "r");
      if (file) {
        html = file.readString();  // Lê o conteúdo do arquivo
        file.close();
      } else {
        html = "<h1>Erro ao carregar o arquivo!</h1>";
      }

      // Substitui o placeholder {{TEMP}} pelo valor da temperatura
      html.replace("{{TEMP}}", String(temperature));
      html.replace("{{totalBytes}}", String(space.first / 1024));  
      html.replace("{{usedBytes}}", String(space.second / 1024));  
      html.replace("{{availableBytes}}", String(availableBytes / 1024));  

      // Envia o conteúdo HTML para o navegador
      request->send(200, "text/html", html);
    });
    
    // Serve o arquivo listar.html
    server.on("/pages/listar.html", HTTP_GET, [](AsyncWebServerRequest *request) {
      request->send(SPIFFS, "/pages/listar.html", "text/html");
    });
    
    // Serve o arquivo cadastrar.html
    server.on("/pages/cadastrar.html", HTTP_GET, [](AsyncWebServerRequest *request) {
      request->send(SPIFFS, "/pages/cadastrar.html", "text/html");
    });
}

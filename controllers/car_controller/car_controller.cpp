// Bibliotecas do Webots
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

// Biblioteca utilizada para obter o diretório atual
#include <filesystem>

// Bibliotecas padrão da linguagem
#include <iostream>
#include <fstream>
#include <string>

using namespace webots;

int main() {

  // Cria a instância do robô
  Robot robot;

  // Obtém o passo de simulação definido no mundo do Webots
  int timestep =
      (int)robot.getBasicTimeStep();

  // Obtém os motores esquerdo e direito do robô
  Motor *leftMotor =
      robot.getMotor("left wheel motor");

  Motor *rightMotor =
      robot.getMotor("right wheel motor");

  // Verifica se ambos os motores foram encontrados
  if (!leftMotor || !rightMotor) {
    std::cout << "Motores nao encontrados!"
              << std::endl;
    return 1;
  }

  // Configura os motores para rotação contínua
  leftMotor->setPosition(INFINITY);
  rightMotor->setPosition(INFINITY);

  // Inicializa o robô parado
  leftMotor->setVelocity(0.0);
  rightMotor->setVelocity(0.0);

  // Exibe o diretório atual para auxiliar na depuração
  std::cout
    << std::filesystem::current_path()
    << std::endl;

  // Loop principal da simulação
  while (robot.step(timestep) != -1) {

    // Abre o arquivo contendo o comando enviado pela interface Web
    std::ifstream file(
      "../../worlds/command.txt"
    );

    // Verifica se o arquivo foi aberto corretamente
    if (file) {
      std::cout << "Arquivo aberto!" << std::endl;
    }
    else {
      std::cout << "Nao consegui abrir o arquivo!" << std::endl;
    }

    // Caso não exista comando, mantém o robô parado
    std::string cmd = "S";

    // Lê o comando presente no arquivo
    if (file)
      file >> cmd;

    // Executa a ação correspondente ao comando recebido

    // Movimento para frente
    if (cmd == "F") {

      leftMotor->setVelocity(6.0);
      rightMotor->setVelocity(6.0);

    }
    // Movimento para trás
    else if (cmd == "B") {

      leftMotor->setVelocity(-6.0);
      rightMotor->setVelocity(-6.0);

    }
    // Rotação para a esquerda
    else if (cmd == "L") {

      leftMotor->setVelocity(-3.0);
      rightMotor->setVelocity(3.0);

    }
    // Rotação para a direita
    else if (cmd == "R") {

      leftMotor->setVelocity(3.0);
      rightMotor->setVelocity(-3.0);

    }
    // Qualquer outro comando mantém o robô parado
    else {

      leftMotor->setVelocity(0.0);
      rightMotor->setVelocity(0.0);
    }
  }

  return 0;
}
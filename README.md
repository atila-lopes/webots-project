````markdown
# Scorpion

> Sistema de controle remoto de um robô móvel no Webots por meio de uma interface Web.

## 📖 Descrição

O **Scorpion** é um projeto desenvolvido com o objetivo de controlar um robô móvel no simulador **Webots** utilizando uma interface web. O sistema integra diferentes tecnologias para permitir que comandos enviados pelo navegador sejam executados pelo robô em tempo real.

A arquitetura do projeto é composta por três módulos principais:

- **Interface Web**, responsável pela interação com o usuário;
- **Servidor Flask**, responsável pela comunicação entre a interface e o simulador;
- **Controlador em C++**, responsável por interpretar os comandos e controlar os motores do robô no Webots.

O projeto foi desenvolvido para fins acadêmicos, servindo como base para estudos em robótica móvel, integração de sistemas, comunicação cliente-servidor e desenvolvimento de aplicações embarcadas.

---

# ✨ Funcionalidades

- Controle remoto via navegador;
- Movimento para frente;
- Movimento para trás;
- Rotação para a esquerda;
- Rotação para a direita;
- Parada do robô;
- Comunicação em tempo real entre navegador e simulador;
- Arquitetura simples e modular.

---

# 🏗️ Arquitetura

```text
┌──────────────┐
│   Usuário    │
└──────┬───────┘
       │
       ▼
┌──────────────┐
│ Interface Web│
│ HTML + JS    │
└──────┬───────┘
       │ HTTP POST
       ▼
┌──────────────┐
│ Flask Server │
└──────┬───────┘
       │
       ▼
 command.txt
       │
       ▼
┌──────────────┐
│ Controlador  │
│ C++ Webots   │
└──────┬───────┘
       │
       ▼
 Motores do Robô
````

---

# 📁 Estrutura do Projeto

```text
Scorpion/
│
├── controllers/
│   └── car_controller/
│       └── car_controller.cpp
│
├── web/
│   ├── index.html
│   ├── script.js
│   └── server.py
│
├── worlds/
│   ├── command.txt
│   └── *.wbt
│
└── README.md
```

---

# 🛠️ Tecnologias Utilizadas

* Webots
* C++
* Python 3
* Flask
* HTML5
* JavaScript
* HTTP
* Git

---

# 🚗 Comandos Disponíveis

| Botão    | Código | Ação                             |
| -------- | :----: | -------------------------------- |
| Frente   |  **F** | Move o robô para frente          |
| Ré       |  **B** | Move o robô para trás            |
| Esquerda |  **L** | Rotaciona o robô para a esquerda |
| Direita  |  **R** | Rotaciona o robô para a direita  |
| Parar    |  **S** | Interrompe o movimento           |

---

# ⚙️ Funcionamento

O funcionamento do sistema ocorre conforme as etapas abaixo:

1. O usuário pressiona um botão na interface web;
2. O JavaScript envia uma requisição HTTP POST para o servidor Flask;
3. O servidor recebe o comando;
4. O comando é gravado no arquivo `worlds/command.txt`;
5. O controlador em C++ lê continuamente esse arquivo;
6. O controlador interpreta o comando;
7. As velocidades dos motores são atualizadas;
8. O robô executa o movimento correspondente.

---

# 📦 Requisitos

Antes de executar o projeto, é necessário possuir instalado:

* Webots;
* Python 3;
* Flask;
* Compilador C++;
* Git.

---

# 🚀 Instalação

## 1. Clonar o repositório

```bash
git clone <url-do-repositorio>
```

---

## 2. Entrar na pasta

```bash
cd Scorpion
```

---

## 3. Instalar o Flask

```bash
pip install flask
```

---

## 4. Abrir o projeto no Webots

Abra o arquivo `.wbt` localizado na pasta `worlds`.

---

## 5. Iniciar o servidor

Entre na pasta `web`:

```bash
cd web
```

Execute:

```bash
python server.py
```

O servidor será iniciado na porta **5000**.

---

## 6. Abrir a interface

Acesse:

```
http://localhost:5000
```

---

## 7. Executar a simulação

Inicie a simulação no Webots e utilize os botões da interface para controlar o robô.

---

# 🔄 Fluxo de Comunicação

```text
Usuário
   │
   ▼
Interface Web
   │
   ▼
Servidor Flask
   │
   ▼
command.txt
   │
   ▼
Controlador C++
   │
   ▼
Motores
```

---

# 📚 Objetivos Educacionais

Este projeto aborda conceitos importantes de:

* Robótica móvel;
* Simulação computacional;
* Desenvolvimento em C++;
* Desenvolvimento Web;
* Comunicação HTTP;
* Integração entre aplicações;
* Controle de motores;
* Arquitetura cliente-servidor.

---

# 🚀 Melhorias Futuras

* Controle por teclado;
* Controle via joystick;
* Comunicação utilizando WebSockets;
* Integração com ROS 2;
* Controle de velocidade variável;
* Leitura de sensores em tempo real;
* Feedback do estado do robô na interface;
* Interface responsiva;
* Sistema de autenticação;
* Comunicação por TCP/IP.

---

# 👨‍💻 Autor

Desenvolvido por **Átila Lopes Bernardino**.

---

# 📄 Licença

Este projeto foi desenvolvido para fins acadêmicos e educacionais.

```
```

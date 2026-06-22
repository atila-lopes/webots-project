import pygame
import time

COMMAND_FILE = "worlds/command.txt"

pygame.init()
pygame.joystick.init()

if pygame.joystick.get_count() == 0:
    print("Nenhum controle encontrado.")
    exit()

joystick = pygame.joystick.Joystick(0)
joystick.init()

print("--------------------------------")
print("Controle conectado!")
print("Nome:", joystick.get_name())
print("--------------------------------")

ultimo_comando = ""

while True:

    pygame.event.pump()

    # Analógico esquerdo
    eixo_x = joystick.get_axis(0)
    eixo_y = joystick.get_axis(1)

    comando = "S"

    deadzone = 0.30

    if eixo_y < -deadzone:
        comando = "F"

    elif eixo_y > deadzone:
        comando = "B"

    elif eixo_x < -deadzone:
        comando = "L"

    elif eixo_x > deadzone:
        comando = "R"

    if comando != ultimo_comando:

        with open(COMMAND_FILE, "w") as arquivo:
            arquivo.write(comando)

        print("Comando:", comando)

        ultimo_comando = comando

    time.sleep(0.02)
# 🚦 Semáforo com Raspberry Pi Pico e LED RGB
Projeto de um semáforo periódico implementado com Raspberry Pi Pico W, utilizando o LED RGB da placa BitDogLab.
## 🔥 Funcionalidades Principais
- **Ciclo Automático de 3s:**  
  Vermelho (3s) → Azul (3s) → Verde (3s)
- **Feedback Serial:**  
  - Timestamp a cada 1 segundo
  - Logs de transição entre estados
- **Controle Preciso:**  
  - Uso de timer hardware para temporização
    ## 📦 Hardware Necessário
| Componente              | Especificações                  |
|-------------------------|---------------------------------|
| Placa BitDogLab         | Com Raspberry Pi Pico W         |
| LED RGB                 | Integrado (GPIO 11, 12, 13)     |
| Computador              | Para programação e monitoramento|

*Pinagem Oficial BitDogLab:**
- Vermelho: GPIO13
- Verde: GPIO11
- Azul: GPIO12

## 💻 Instalação e Uso

### Pré-requisitos
- [SDK do Raspberry Pi Pico](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf)
- Compilador ARM (gcc-arm-none-eabi)
- CMake
- ### Passo a Passo
1. **Clone o repositório:**
   ```bash
   git clone https://github.com/seu-usuario/semaforo-pico.git
   cd semaforo-pico
  2. ### **Compile o projeto:**
     mkdir build && cd build
     cmake .. && make
  3. ### **Grave na placa:**

  ## PROJETO DESENVOLVIDO POR CÉSAR REBOUÇAS COSTA 

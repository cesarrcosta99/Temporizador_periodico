#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos do LED RGB (BitDogLab)
#define LED_VERMELHO 13
#define LED_AZUL 12
#define LED_VERDE 11

// Estados do semáforo
typedef enum
{
    VERMELHO,
    AZUL,
    VERDE
} EstadoSemaforo;
static absolute_time_t start_time; // Variável para armazenar o tempo inicial

// Função de callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t)
{
    static EstadoSemaforo estado = VERMELHO;

    // Desliga todos os LEDs primeiro
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERDE, 0);

    // Atualiza o estado
    switch (estado)
    {
    case VERMELHO:
        gpio_put(LED_VERMELHO, 1);
        estado = AZUL;
        break;

    case AZUL:
        gpio_put(LED_AZUL, 1);
        estado = VERDE;
        break;

    case VERDE:
        gpio_put(LED_VERDE, 1);
        estado = VERMELHO;
        break;
    }

    return true; // Mantém o timer ativo
}

int main()
{
    stdio_init_all();

    // Configuração dos LEDs
    gpio_init(LED_VERMELHO);
    gpio_init(LED_AZUL);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

     // Inicialização explícita do tempo
    start_time = get_absolute_time(); // Captura o tempo "zero"

    // Inicializa o timer periódico (3000ms = 3 segundos)
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal
    while (1)
    {
       // Calcula o tempo relativo desde o início
        int64_t elapsed_time = absolute_time_diff_us(start_time, get_absolute_time()) / 1000;
        printf("Tempo decorrido: %lld ms\n", elapsed_time);
        sleep_ms(1000); // Imprime a cada 1 segundo
    }

    return 0;
}
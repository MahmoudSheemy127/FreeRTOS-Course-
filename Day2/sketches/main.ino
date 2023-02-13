#include <Arduino_FreeRTOS.h>
#include <FreeRTOSConfig.h>
#define LED 13
#define LED2 12

void blink_led(void *pv);
void blink_led2(void *pv);

void setup()
{
    pinMode(LED,OUTPUT);
    pinMode(LED2,OUTPUT);

    xTaskCreate(blink_led,NULL,configMINIMAL_STACK_SIZE,NULL,2,NULL);
    xTaskCreate(blink_led2,NULL,configMINIMAL_STACK_SIZE,NULL,3,NULL);

    vTaskStartScheduler();
}

void loop()
{

}

void blink_led(void *pv) //starvation
{
    int LEDSTATE = HIGH;
    while(1)
    {
        digitalWrite(LED,LEDSTATE);
        LEDSTATE = !LEDSTATE;
        vTaskDelay(500 / portTICK_PERIOD_MS); //periodicity
    }
}

void blink_led2(void *pv)
{
    int LEDSTATE = HIGH;
    while(1)
    {
        digitalWrite(LED2,LEDSTATE);
        LEDSTATE = !LEDSTATE;
        vTaskDelay(800 / portTICK_PERIOD_MS); //periodicity
    }
}
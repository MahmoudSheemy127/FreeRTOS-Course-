#include <Arduino.h>
#line 1 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino"
#include <Arduino_FreeRTOS.h>
#include <semphr.h>
#include <LiquidCrystal.h>

#define btn 0

LiquidCrystal lcd(13,12,11,10,9,8);


void task1(void *pv);
void task2(void *pv);


//SemaphoreHandle_t binary_semaphore;
SemaphoreHandle_t counting_semaphore;

#line 17 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino"
void setup();
#line 29 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino"
void loop();
#line 17 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino"
void setup()
{
    lcd.begin(16,2);
    pinMode(btn,INPUT_PULLUP);
    //vSemaphoreCreateBinary(binary_semaphore);
    counting_semaphore = xSemaphoreCreateCounting(5,0);
    //xSemaphoreTake(binary_semaphore,200/portTICK_PERIOD_MS);
    xTaskCreate(task1,NULL,configMINIMAL_STACK_SIZE,NULL,2,NULL);
    xTaskCreate(task2,NULL,configMINIMAL_STACK_SIZE,NULL,3,NULL);
    vTaskStartScheduler();
}

void loop()
{

}


void task1(void *pv)
{
    int ret;
    while(1)
    {
        lcd.clear();
        _delay_ms(100);
        ret = xSemaphoreTake(counting_semaphore,200/portTICK_PERIOD_MS);
        if(ret == pdPASS)
        {
            //common resource
            //critical section
            lcd.print("Button is pressed");
            vTaskDelay(800/portTICK_PERIOD_MS);
        }
    }
}

void task2(void *pv)
{
    while(1)
    {
        if(digitalRead(btn) == 0)
        {
            //give semaphore
            xSemaphoreGive(counting_semaphore);
        }
        vTaskDelay(200/portTICK_PERIOD_MS);
    }
}

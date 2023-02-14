#include <Arduino.h>
#line 1 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino"
#include <Arduino_FreeRTOS.h>
#include <LiquidCrystal.h>
#include <semphr.h>

LiquidCrystal lcd(13,12,11,10,9,8);

void task1(void *pv);
void task2(void *pv);


#line 11 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino"
void setup();
#line 19 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino"
void loop();
#line 11 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino"
void setup()
{
    lcd.begin(16,2);
    xTaskCreate(task1,NULL,configMINIMAL_STACK_SIZE,NULL,2,NULL); //Ready state
    xTaskCreate(task2,NULL,configMINIMAL_STACK_SIZE,NULL,1,NULL);
    vTaskStartScheduler();
}

void loop()
{

}

void task1(void *pv)
{
    while(1)
    {
        lcd.clear();
        lcd.print("12/12/2023");
        vTaskDelay(200/portTICK_PERIOD_MS);
    }
}

void task2(void *pv)
{
    while(1)
    {
        lcd.clear();
        lcd.print("02:33 PM");
        vTaskDelay(800/portTICK_PERIOD_MS);
    }
}


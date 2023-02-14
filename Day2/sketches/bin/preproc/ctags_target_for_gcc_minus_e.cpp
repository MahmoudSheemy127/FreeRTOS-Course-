# 1 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino"
# 2 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino" 2
# 3 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino" 2
# 4 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino" 2

LiquidCrystal lcd(13,12,11,10,9,8);

void task1(void *pv);
void task2(void *pv);


void setup()
{
    lcd.begin(16,2);
    xTaskCreate(task1,
# 14 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino" 3 4
                     __null
# 14 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino"
                         ,( 192 ),
# 14 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino" 3 4
                                                   __null
# 14 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino"
                                                       ,2,
# 14 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino" 3 4
                                                          __null
# 14 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino"
                                                              ); //Ready state
    xTaskCreate(task2,
# 15 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino" 3 4
                     __null
# 15 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino"
                         ,( 192 ),
# 15 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino" 3 4
                                                   __null
# 15 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino"
                                                       ,1,
# 15 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino" 3 4
                                                          __null
# 15 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino"
                                                              );
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
        vTaskDelay(200/( (TickType_t) 1000 / ( (TickType_t)( (uint32_t)128000 >> (
# 30 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino" 3
                      0 
# 30 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino"
                      /* portUSE_WDTO to use the Watchdog Timer for xTaskIncrementTick*/ + 11) ) ) /* 2^11 = 2048 WDT scaler for 128kHz Timer*/ ));
    }
}

void task2(void *pv)
{
    while(1)
    {
        lcd.clear();
        lcd.print("02:33 PM");
        vTaskDelay(800/( (TickType_t) 1000 / ( (TickType_t)( (uint32_t)128000 >> (
# 40 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino" 3
                      0 
# 40 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day2\\sketches\\SchedulingSketch2\\two_tasks.ino"
                      /* portUSE_WDTO to use the Watchdog Timer for xTaskIncrementTick*/ + 11) ) ) /* 2^11 = 2048 WDT scaler for 128kHz Timer*/ ));
    }
}

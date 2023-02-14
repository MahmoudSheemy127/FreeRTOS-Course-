# 1 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino"
# 2 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino" 2
# 3 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino" 2
# 4 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino" 2



LiquidCrystal lcd(13,12,11,10,9,8);


void task1(void *pv);
void task2(void *pv);


//SemaphoreHandle_t binary_semaphore;
SemaphoreHandle_t counting_semaphore;

void setup()
{
    lcd.begin(16,2);
    pinMode(0,0x2);
    //vSemaphoreCreateBinary(binary_semaphore);
    counting_semaphore = xQueueCreateCountingSemaphore( ( 5 ), ( 0 ) );
    //xSemaphoreTake(binary_semaphore,200/portTICK_PERIOD_MS);
    xTaskCreate(task1,
# 24 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino" 3 4
                     __null
# 24 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino"
                         ,( 192 ),
# 24 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino" 3 4
                                                   __null
# 24 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino"
                                                       ,2,
# 24 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino" 3 4
                                                          __null
# 24 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino"
                                                              );
    xTaskCreate(task2,
# 25 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino" 3 4
                     __null
# 25 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino"
                         ,( 192 ),
# 25 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino" 3 4
                                                   __null
# 25 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino"
                                                       ,3,
# 25 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino" 3 4
                                                          __null
# 25 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino"
                                                              );
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
        ret = xQueueSemaphoreTake( ( counting_semaphore ), ( 200/( (TickType_t) 1000 / ( (TickType_t)( (uint32_t)128000 >> (
# 42 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino" 3
             0 
# 42 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino"
             /* portUSE_WDTO to use the Watchdog Timer for xTaskIncrementTick*/ + 11) ) ) /* 2^11 = 2048 WDT scaler for 128kHz Timer*/ ) ) );
        if(ret == ( ( ( BaseType_t ) 1 ) ))
        {
            //common resource
            //critical section
            lcd.print("Button is pressed");
            vTaskDelay(800/( (TickType_t) 1000 / ( (TickType_t)( (uint32_t)128000 >> (
# 48 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino" 3
                          0 
# 48 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino"
                          /* portUSE_WDTO to use the Watchdog Timer for xTaskIncrementTick*/ + 11) ) ) /* 2^11 = 2048 WDT scaler for 128kHz Timer*/ ));
        }
    }
}

void task2(void *pv)
{
    while(1)
    {
        if(digitalRead(0) == 0)
        {
            //give semaphore
            xQueueGenericSend( ( QueueHandle_t ) ( counting_semaphore ), 
# 60 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino" 3 4
           __null
# 60 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino"
           , ( ( TickType_t ) 0U ), ( ( BaseType_t ) 0 ) );
        }
        vTaskDelay(200/( (TickType_t) 1000 / ( (TickType_t)( (uint32_t)128000 >> (
# 62 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino" 3
                      0 
# 62 "f:\\Work\\Embedded\\Courses\\FreeRTOS\\Day3\\sketches\\main.ino"
                      /* portUSE_WDTO to use the Watchdog Timer for xTaskIncrementTick*/ + 11) ) ) /* 2^11 = 2048 WDT scaler for 128kHz Timer*/ ));
    }
}

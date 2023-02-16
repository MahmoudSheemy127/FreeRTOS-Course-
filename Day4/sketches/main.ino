#include <LiquidCrystal.h>
#include <Arduino_FreeRTOS.h>
#include <queue.h>

#define LED 0
#define NO_KEY 0

const byte rows = 4; //four rows
const byte cols = 3; //three columns
char keys[rows][cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'}
};
byte rowPins[rows] = {4,3,2,1}; //connect to the row pinouts of the keypad
byte colPins[cols] = {5,6,7}; //connect to the column pinouts of the keypad

void keypad_init();
char keypadPressed();
void turnOffAllRows();

LiquidCrystal lcd(13,12,11,10,9,8);

void task1(void *pv); //write on LCD
void task2(void *pv); //get input from keypad

TaskHandle_t taskone_handle;

QueueHandle_t queue;

void setup()
{
    keypad_init();
    pinMode(LED,INPUT_PULLUP);
    //keypad.begin(keys);
    lcd.begin(16,2);
    //keypad.setDebounceTime(200);
    queue =  xQueueCreate(10,sizeof(char));
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
    char x;
    while(1)
    {
        ret = xQueueReceive(queue,&x,200/portTICK_PERIOD_MS);
        if(ret == pdPASS)
        {
            //received character
            lcd.print(x);
        }
    }
}

void task2(void *pv)
{
    char x;
    int state = HIGH;
    int ret;
    while(1)
    {

        x = keypadPressed();
        if(x != NO_KEY)
        {
            xQueueSend(queue,&x,200/portTICK_PERIOD_MS);   
            vTaskDelay(300/portTICK_PERIOD_MS);
        }

    }
}

//get key received
char keypadPressed()
{
    for(int i=0; i<rows;i++)
    {
        //turn all off rows
        turnOffAllRows();
        //turn row i on
        digitalWrite(rowPins[i],LOW);
        for(int j=0; j<cols;j++)
        {
            if(digitalRead(colPins[j]) == LOW)
            {
                //return the char
                return keys[i][j];
            }
        }
    }
    return NO_KEY;
}

//turn off all rows
void turnOffAllRows()
{
    for(int i=0; i<rows;i++)
    {
        digitalWrite(rowPins[i],HIGH);
    }

}

//init keypad
void keypad_init()
{
    for(int i=0;i<rows;i++)
    {
        pinMode(rowPins[i],OUTPUT);
    }
    for(int i=0;i<cols;i++)
    {
        pinMode(colPins[i],INPUT_PULLUP);
    }

}
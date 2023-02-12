
//basic implementation of RTOS

#define MAX_NUM_OF_TASKS 10

//struct of task
typedef struct task{
  int periodicity;
  int priority;
  void (*fn)(void);
}task;


//Array of tasks
task Tasks[MAX_NUM_OF_TASKS];

//add new task function
void addNewTaskToScheduler(int periodicity, int priority, void (*fn)(void));

void task1(); //blink led for 100ms
void task2(); //blink led for 500 ms
void task3(); //blink led for 800 ms

void scheduler();

int LED1 = 4;
int LED2 = 5;
int LED3 = 6;
int LED1STATE = HIGH;
int LED2STATE = HIGH;
int LED3STATE = HIGH;
int num_of_current_tasks = 0;
int num_of_millis = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  //Serial.begin(9600);
  addNewTaskToScheduler(100,3,&task1);
  addNewTaskToScheduler(500,2,&task2);
  addNewTaskToScheduler(800,1,&task3);


}


void loop() {
  // put your main code here, to run repeatedly:  
  scheduler();
  num_of_millis = millis();
  delay(1);
}

//add new task in scheduler
void addNewTaskToScheduler(int periodicity, int priority, void (*fn)(void))
{
  if(num_of_current_tasks <= MAX_NUM_OF_TASKS)
  {
    task new_task;
    new_task.periodicity = periodicity;
    new_task.priority = priority;
    new_task.fn = fn;
    Tasks[num_of_current_tasks] = new_task; 
    num_of_current_tasks++;
  }
}

void scheduler()
{
  for(int i =0; i<num_of_current_tasks; i++)
  {
    if(num_of_millis % Tasks[i].periodicity == 0)
    {
      Tasks[i].fn(); //execute task
    }
  }
}

void task1()
{
  digitalWrite(LED1,LED1STATE);
  LED1STATE = !LED1STATE;  
}

void task2()
{
  digitalWrite(LED2,LED2STATE);
  LED2STATE = !LED2STATE;  
  
}

void task3()
{
  digitalWrite(LED3,LED3STATE);
  LED3STATE = !LED3STATE;    
}

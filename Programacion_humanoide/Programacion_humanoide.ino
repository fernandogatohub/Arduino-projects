#include <Servo.h>

Servo ServoR1;

const int pinServoR1 = 6;
const int pulsoMinR1 = 700;     
const int pulsoMaxR1 = 2300;

//Pines de conexión del driver
int Pin_Motor_Der_A = 2;
int Pin_Motor_Der_B = 3;
int Pin_Motor_Izq_A = 4;
int Pin_Motor_Izq_B = 5;

int tiempo=0;
int tiempo1;

void setup() {

  ServoR1.attach(pinServoR1, pulsoMinR1, pulsoMaxR1);
  // inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);
  // configuramos los pines como salida
  pinMode(Pin_Motor_Der_A, OUTPUT);
  pinMode(Pin_Motor_Der_B, OUTPUT);
  pinMode(Pin_Motor_Izq_A, OUTPUT);
  pinMode(Pin_Motor_Izq_B, OUTPUT);

}

void Mover_Adelante()
{
  digitalWrite (Pin_Motor_Der_A, HIGH);
  digitalWrite (Pin_Motor_Der_B, LOW);
  delay (5);
  digitalWrite (Pin_Motor_Izq_A, HIGH);
  digitalWrite (Pin_Motor_Izq_B, LOW);
}
void Mover_Retroceso()
{
  digitalWrite (Pin_Motor_Der_A,LOW );
  digitalWrite (Pin_Motor_Der_B,HIGH );
  delay (5);
  digitalWrite (Pin_Motor_Izq_A,LOW );
  digitalWrite (Pin_Motor_Izq_B,HIGH );
}
void Mover_Derecha()
{
  digitalWrite (Pin_Motor_Der_A,LOW );
  digitalWrite (Pin_Motor_Der_B,HIGH );
  delay (5);
  digitalWrite (Pin_Motor_Izq_A,HIGH);
  digitalWrite (Pin_Motor_Izq_B,LOW);
}
void Mover_Izquierda()
{
  digitalWrite (Pin_Motor_Der_A,HIGH);
  digitalWrite (Pin_Motor_Der_B,LOW);
  delay (5);
  digitalWrite (Pin_Motor_Izq_A,LOW );
  digitalWrite (Pin_Motor_Izq_B,HIGH );
}
void Mover_Stop()
{
  digitalWrite (Pin_Motor_Der_A, LOW);
  digitalWrite (Pin_Motor_Der_B, LOW);
  digitalWrite (Pin_Motor_Izq_A, LOW);
  digitalWrite (Pin_Motor_Izq_B, LOW);
} 

void loop() {

  if (Serial.available()) {
     char dato= Serial.read();
     if(dato=='a')
     {
        Mover_Adelante();
      tiempo=0;
     }
     else if(dato=='r')
     { 
        Mover_Retroceso();
      tiempo=0;
     }
     else if(dato=='d')
     { 
        Mover_Derecha();
        tiempo=0;
     }
     else if(dato=='i')
     { 
        Mover_Izquierda();
        tiempo=0;
     }
     else if(dato=='n')
     { 
        ServoR1.write(90);
       delay(20);
       return;
     }  
     else if(dato=='m')
     { 
        ServoR1.write(20);
       delay(20);
        return;
     }    
   
  }

  if(tiempo<250) // 100 cilcos de 1ms 
  {    
    tiempo=tiempo+1;
  }
  else   //ya transcurrió 100ms (100ciclos)
  {
    Mover_Stop();
  }
 
  delay(1); //pausa de 1ms por ciclo

    if(tiempo1<200000) // 100 cilcos de 1ms 
  {    
    tiempo=tiempo+1;
  }
  else   //ya transcurrió 100ms (100ciclos)
  {
    Mover_Stop();
  }
 
  delay(1); //pausa de 1ms por ciclo
  
}


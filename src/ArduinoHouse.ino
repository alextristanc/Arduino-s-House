// DIAGRAMA DE FLUJO DE PROYECTO FINAL ARDUINO
// Desarrolladores: 
// Tristán Contreras David Alejandro
// Zamora Martínez María Guadalupe
#include <Servo.h> //Abrimos librería para que funcione el servomotor
// C++ code
Servo servoMotor; //Definimos el servomotor como servoMotor
int CUENTA = 0; //Definimos cuenta en 0
void setup()
{
  servoMotor.attach(3); //El servo funcionará en el pin digital 3
  servoMotor.write(0); //El servo comenzará en 0 grados
  pinMode(13, INPUT); //El pin digital 13 mostrara señal
  Serial.begin(9600); //Frecuencia
  pinMode(12, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(2, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(8, OUTPUT);
  CUENTA = 1;  //Definimos cuenta en 0
}
//A1 >50  =60  <400
void loop()
{
  Serial.println(analogRead(A1)); //Mostrar en serial
  if (digitalRead(13) == 1 && CUENTA == 1) { //Si el pin digital del botón se presiona
    CUENTA = 0;
    delay(500); // Wait for 500 millisecond(s)
  }
  if (digitalRead(13) == 1 && CUENTA == 0) { //Si el pin digital del botón se vuelve a presionar
    CUENTA = 1;
    delay(500); // Wait for 500 millisecond(s)
  }
  if (CUENTA == 0) { //Si el pin digital del botón se presiona
    digitalWrite(12, HIGH); //Enciende el pin 12

    if (analogRead(A1) < 200) { //Leds izquierda
      digitalWrite(2, HIGH);
    } else {
      digitalWrite(2, LOW);
    }
    if (analogRead(A2) < 200) { //leds centro
      digitalWrite(4, HIGH);
      digitalWrite(7, HIGH);
    } else {
      digitalWrite(4, LOW);
      digitalWrite(7, LOW);
    }
    if (analogRead(A3) < 200) { //leds derecha
      digitalWrite(8, HIGH);
    } else {
      digitalWrite(8, LOW);
    }
      servoMotor.write(0); //Servo esta en 0 grados
      delay(1000);
      servoMotor.write(180); //servo avanza a 0 grados
      delay(1000);
  }
  if (CUENTA == 1) { //si el botón se vuelve a presionar todo se apaga
    digitalWrite(12, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(4, LOW);
    digitalWrite(2, LOW);
    servoMotor.write(0);   
  }
}
// Definición de variables y constantes relacionadas con el motor
const int IN1 = 13;  // Pin digital 13 para controlar el sentido de giro del motor
const int IN2 = 12;  // Pin digital 12 para controlar el sentido de giro del motor
 
// Definición de variable relacionada con el sensor IR
int lecturaSensor; // Almacena el valor de la lectura del sensor
const int sensorPin = A1; // El sensor IR irá conectado al pin analógico A1
 
void setup()
{
  // Se declaran todos los pines como salidas y entradas
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600); // Se inicia el puerto de comunicaciones en serie
}
 
void loop()
{
  lecturaSensorIR();
  
  if (lecturaSensor == 1)
  {
    robotAvance(); // El robot avanza
    Serial.println("robot avanza");
  }
  else
  {
    robotGiro(); // El robot realiza un giro
    Serial.println("robot gira");
  }
}

/*
  Función lecturaSensorIR: leerá el valor del sensor de infrarrojos TCRT5000
  y lo almacena en una variable. Dicho sensor retornará el valor 0 (LOW) si
  el sensor está en zona blanca y el valor 1 (HIGH) si el sensor está en zona
  negra.
*/
void lecturaSensorIR()
{
  lecturaSensor = digitalRead(sensorPin); // Almacena la lectura del sensor
  Serial.println("El valor del sensor es ");
  Serial.println(lecturaSensor);
}

/*
  Función robotAvance: esta función hará que el motor se active a máxima potencia,
  lo que hará que el robot avance hacia delante.
*/
void robotAvance()
{
  digitalWrite(IN1, HIGH); // Activar motor
  digitalWrite(IN2, LOW);  // Desactivar motor (sentido de giro)
}

/*
  Función robotGiro: esta función hará que el motor gire, lo que hará que el robot
  realice un giro (por ejemplo, a la derecha).
*/
void robotGiro()
{
  digitalWrite(IN1, LOW);  // Desactivar motor (sentido de giro)
  digitalWrite(IN2, LOW);  // Desactivar motor (sentido de giro)
}

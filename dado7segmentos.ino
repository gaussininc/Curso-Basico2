/* Programa creado por alemx1 para el Curso de robotica en 
Arduino Nivel basico 2 
A partir de un programa creado en programarfacil.com
*/

// Constantes pines 
#define PULSADOR 10 
// Array multidimensional para mostrar los números 
byte  numero[10][8] = 
{ 
  { 1, 1, 1, 1, 1, 1, 0, 0 }, // 0 
  { 0, 0, 0, 1, 1, 0, 0, 0 }, // 1 
  { 1, 0, 1, 1, 0, 1, 1, 0 }, // 2 
  { 0, 0, 1, 1, 1, 1, 1, 0 }, // 3 
  { 0, 1, 0, 1, 1, 0, 1, 0 }, // 4 
  { 0, 1, 1, 0, 1, 1, 1, 0 }, // 5 
  { 1, 1, 1, 0, 1, 1, 1, 0 }, // 6 
  { 0, 0, 1, 1, 1, 0, 0, 0 }, // 7 
  { 1, 1, 1, 1, 1, 1, 1, 0 }, // 8 
  { 0, 1, 1, 1, 1, 0, 1, 0 } // 9 
}; 
  
void setup() { 
  // Iniciamos el monitor serie 
  Serial.begin(9600); 
  
  // Ponemos los pines de los segmentos en modo OUTPUT (salida) 
  for (int i = 3; i < 10; i++) 
  { 
    pinMode(i, OUTPUT); 
  } 
  
  // Ponemos el pin del pulsador en modo INPUT (entradda) 
  pinMode(PULSADOR, INPUT); 
  
  //Establecemos la semilla fija 
  randomSeed(analogRead(A0)); 
} 
  
void loop() { 
  // Leemos el valor del pulsador 
  int valor = digitalRead(PULSADOR); 
  
  // Si está pulsado 
  if (valor == HIGH) 
  { 
  
    //Genera un numero aleatorio entre 1 y 6 
    int randomNumber = random(0, 10); 
  
    // Ponemos los pines en estado correcto para mostrar el número randomNumber 
    for (int e = 0; e < 9; e++) 
    { 
      digitalWrite(e + 3, numero[randomNumber][e]); 
    } 
  
    delay(500); 
  } 
}

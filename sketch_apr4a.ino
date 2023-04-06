#include <Servo.h>

Servo myservo;
int pos = 0;

String traduz_morse(char letra){
  switch (tolower(letra)) {
    case 'a':
      return ".- ";
    case 'b':
      return "-... ";
    case 'c':
      return "-.-. ";
    case 'd':
      return "-.. ";
    case 'e':
      return ". ";
    case 'f':
      return "..-. ";
    case 'g':
      return "--. ";
    case 'h':
      return ".... ";
    case 'i':
      return ".. ";
    case 'j':
      return ".--- ";
    case 'k':
      return "-.- ";
    case 'l':
      return ".-.. ";
    case 'm':
      return "-- ";
    case 'n':
      return "-. ";
    case 'o':
      return "--- ";
    case 'p':
      return ".--. ";
    case 'q':
      return "--.- ";
    case 'r':
      return ".-. ";
    case 's':
      return "... ";
    case 't':
      return "- ";
    case 'u':
      return "..- ";
    case 'v':
      return "...- ";
    case 'w':
      return ".-- ";
    case 'x':
      return "-..- ";
    case 'y':
      return "-.-- ";
    case 'z':
      return "--.. ";
    case '1':
      return ".---- ";
    case '2':
      return "..--- ";
    case '3':
      return "...-- ";
    case '4':
      return "....- ";
    case '5':
      return "..... ";
    case '6':
      return "-.... ";
    case '7':
      return "--... ";
    case '8':
      return "---.. ";
    case '9':
      return "----. ";
    case '0':
      return "----- ";
    case ' ':
      return "   ";
    default:
    return "";
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT); //LED
  myservo.attach(9);
  myservo.write(pos);
  Serial.println("Digite uma frase que ela será traduzida para código morse: ");
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available()){
    //LÊ A STRING DO TECLADO
    String frase = Serial.readString();
    Serial.print("\nFrase digitada: ");
    Serial.println(frase);
  
    //CONVERTE A FRASE PARA MORSE
    String frase_morse;
    for (int i=0; i<frase.length(); i++){
      frase_morse += traduz_morse(frase[i]);
    }
    Serial.println("Frase em código morse:");
    Serial.println(frase_morse);

    //ACENDE O LED E MOVE SERVO
    for (int i=0; i<frase_morse.length(); i++){
      if (frase_morse[i] == '.'){
        digitalWrite(2, HIGH);
        myservo.write(55);
        delay(300);
        digitalWrite(2, LOW);
        myservo.write(30);
      }else if (frase_morse[i] == '-'){
        digitalWrite(2, HIGH);
        myservo.write(55);
        delay(900);
        digitalWrite(2, LOW);
        myservo.write(30);
      }else if (frase_morse[i] == ' '){
        delay(900);
      }else{
        Serial.println("Erro");
      }
      delay(300);
    }
  }
}
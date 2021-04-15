/*
  Program created by Oscar Calero
  Sound from Star Wars film of George Lucas (distributed by Disney Company)
  Thanks to Marcelo Larios for R2D2 sound

  Main_Title_and_Rebel_Blockade_Runner (234 bytes)
  song1 T100 3l832 3l88 3l88 3l88
  T280 3l88 T100 3F88 4r88
  T120 4F88 T75 4r88 T95
  3l88 3l88 3F88 4r88 4F88
  4r88 T135 3l64 T95 3F88
  3r88 T100 3F88 T145 3s964
  T110 3F96 3F108 3F108 T95
  4l1044 5F1004 5r100 T80
  5R116 5D112 T50 5l1080
  T100 5F470 T85 5r111
  5R116 5D112 T50 5l1081
  5F513 T80 5r111 5R112 5r107
  T295 5D1128 T35 4F25 T50
  4F68 T70 4F22 T100 4l1031
  5F1037 T75 5r117 5R116
  5D109 T50 5l1083 T100
  5F467 T80 5r108 5R109 5D108
  T50 5l1082 5F514 T80
  5r107 5R112 5r111 T5 5D1125
  T195 4F231 T80 4F64 T50
  4S796 T5 4S278 5r278 5R278
  5D282 T70 4l218 T5 4l181
  5D185 5R185 T95 5D327 T5
  4S141 4L559 T100 4F323 T5
  4F138 T55 4S890 T5 4S88
  5r92 5r276 5R281 5D277 4l279
  5F562 T200 5D1219 T10 4F274
  T55 4S793 T10 4S274 5r274
  5R274 5D274 T50 4l227 4l188
  T5 5D198 5R179 5D377 T50
  4S137 T100 4L467 4F278 T50
  4F137 4l330 4s132 4f330 4F132
  4r330 4d132 4D330 3l132 4F1698 end

  Melodia del Imperio (130 bytes)
  song2 T50 4L500 4L500 4L500 4F350
  5D150 4L500 4F350 5D150 T550
  4L650 T50 5M500 5M500 5M500
  5F350 5D150 4s500 4F350 5D150
  T550 4L650 T50 5L500 4L300
  4L150 5L500 5s325 5S175 5f125
  5F125 T375 5f250 T50 4l250
  5r500 5R325 5d175 5D125 4l125
  T400 5D250 T50 4F250 4s500
  4F350 4L125 5D500 4L375 5D125
  T550 5M650 T50 5L500 4L300 4L150
  5L500 5s325 5S175 5f125 5F125
  T375  5f250 T50 4l250 5r500
  5R325 5d175 5D125 4l125 T400
  5D250 T50 4F250 4s500 4F375
  5D125 4L500 4F375 5D125 T550
  4L650 end


  Cantina_Band (117 bytes)
  song3 T30 4I289 5M289 4I289
  5M289 4I96 5M289 T116 4I96
  T10 4l96 4I96 4I96 4l96
  4I96 T116 4L96 T10 4s96
  4L96 4S96 4S192 T64 4M578
  T32 4I289 5M289 4I289 5M289
  4l96 4I96 T32 4L289 4L289
  4s96 4L289 5R96 5D289 4I289
  4L289 4I289 5M289 4I289 5M289
  T10 4I96 T32 5M289 T116
  4I96 T10 4l96 4I96 5R192
  T32 5R289 4I96 4L289 4S289
  T64 4M578 T42 4M385 4S385
  4I385 5R385 T32 5F289 5M289
  T10 4l96 4l96 4I192 4S192 end

*/

// *************** Tonos de musica
#define frecuenciaNotaDo_ 16.3516
#define frecuenciaNotaDo2 17.3239
#define frecuenciaNotaRe_ 18.3540
#define frecuenciaNotaRe2 19.4454
#define frecuenciaNotaMi_ 20.6017
#define frecuenciaNotaFa_ 21.8267
#define frecuenciaNotaFa2 23.1246
#define frecuenciaNotaSol_ 24.4997
#define frecuenciaNotaSol2 25.9565
#define frecuenciaNotaLa_ 27.5
#define frecuenciaNotaLa2 29.1352
#define frecuenciaNotaSi_ 30.8676

const float frecuenciaArray[12] = {frecuenciaNotaDo_, frecuenciaNotaDo2, frecuenciaNotaRe_, frecuenciaNotaRe2,
                                   frecuenciaNotaMi_, frecuenciaNotaFa_, frecuenciaNotaFa2, frecuenciaNotaSol_,
                                   frecuenciaNotaSol2, frecuenciaNotaLa_, frecuenciaNotaLa2, frecuenciaNotaSi_
                                  };

// ********* RF CODES
#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();

// ********* MOTOR
const byte izqPin = 5; // Activa motor izquierdo
const byte derPin = 6; // Activa motor derecho
const byte mS_PulseI = 100; // mS de accionamiento motor cada pulso de mando
const byte mS_PulseD = 60; // mS de accionamiento motor cada pulso de mando

// ********** Speaker
#include <EEPROM.h>
#define speakerPin 10
int punteroEEPPROM = 0 ;
String inByte ;
byte nota ;
int tempoNota ;
int tempoPausa ;
byte octava = 10 ;  // octava es de 0 - 9

#define punteroEE_RF_R1 0  // rf0 - Sonido R2D2
#define punteroEE_RF_I1 4  // rf1 - Rueda Izquierda
#define punteroEE_RF_D1 8  // rf2 - Rueda derecha
#define punteroEE_RF_A1 12 // rf3 - Ambas ruedas
#define punteroEE_RF_M11 16 // rf4 - Melodia 1
#define punteroEE_RF_M21 20 // rf5 - Melodia 2
#define punteroEE_RF_M31 24 // rf6 - Melodia 3

// 484 byte para melodias
const byte punteroEE_M1 = 28; // direccion melodia 1 (234 bytes)
const int punteroEE_M2 = 262; // direccion melodia 2 (130 bytes)
const int punteroEE_M3 = 392; // direccion melodia 3 (120 bytes)

const byte punteroEEArray[7] = {punteroEE_RF_R1, punteroEE_RF_I1, punteroEE_RF_D1, punteroEE_RF_A1,
                                punteroEE_RF_M11, punteroEE_RF_M21, punteroEE_RF_M31
                               };

const String entrada_X[4] = {"song", "rf", "end", "play"};

// *** LED
const byte ledPin1 = 13;
const byte ledPin2 = 8;

// *** SERVO G90
#include <Servo.h>
Servo myservo;  
int posServo;
int pos = 0;
int incremento;
int parpadeo;
boolean direccion = true;
const byte ceroServo = 90;
const byte pinServo = 9;
const byte incrementoServo = 11; // entre 1 y 11... 6 = 96º  max. y 11 = 176º max.

// ****************************************** SETUP ****************************************
void setup() {

  // RF & Serial
  Serial.begin(115200);
  Serial.println("OK");
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2

  // Sound
  pinMode(speakerPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  randomSeed(analogRead(0)); // Inicia el generador de números aleatorios con el valor de la entrada en 0

  // Motor
  pinMode(izqPin, OUTPUT);
  pinMode(derPin, OUTPUT);

  // Servo SG90
  myservo.attach(pinServo); 
  myservo.detach();

}

// ****************************************** LOOP ****************************************
void loop() {

  if (mySwitch.available()) {  // input from RF433Mhz
    lecturaRF( mySwitch.getReceivedValue() );
    mySwitch.resetAvailable();
  }

  if (Serial.available() > 0) { // input from Serial
    lecturaPuertoSerie();
  }

}
// ****************************************** END LOOP ****************************************


// ****** Interprete Mensaje entrada Puerto Serie ********
void lecturaPuertoSerie() {
  inByte = Serial.readStringUntil('\n') + " " ;
  byte valorByte;

  do {
    valorByte =  (byte) inByte[0] ;

    int i_ = 10;
    for (byte i = 0; i < 4; i++) {
      if (inByte.substring(0, entrada_X[i].length() ) == entrada_X[i]) {
        i_ = i;
        break;
      }
    }

    int puntero_ ;
    int punteroEE_RF;
    switch ( i_ ) {
      case 0: //song
        punteroEEPPROM = direccionEEPROM ( extractNumber( 4 ) ) ;
        nota = 13;
        break;
      case 1:  // rf
        puntero_ = extractNumber( 2 );
        punteroEE_RF = punteroEEArray[puntero_];
        EEPROMWritelong( punteroEE_RF , extractNumber( 1 ) ) ;
        break;
      case 2: // end
        inByte = "" ;
        grabar_EEPROM(255) ;
        break;
      case 3: // play
        punteroEEPPROM = direccionEEPROM ( extractNumber( 4 ) ) ;
        inByte = "" ;
        play_EEPROM() ;
        break;
    }

    if ( i_ == 10  ) {
      if ( valorByte > 47 && valorByte < 58 ) {      // es un numero del 0 al 9 e indica OCTAVA
        if ( octava != (byte) inByte[0] - 48) {  // diferente al actual
          octava = (byte) inByte[0] - 48 ;
          nota = 240 + octava ;  // byte de octava es 24X  donde X = octava de 0-9
          grabar_EEPROM(nota);
        }
        inByte = inByte.substring(1, inByte.length());
      }

      else if (valorByte > 67 && valorByte < 116  ) { // es una letra e indica NOTA, pausa u otra instrucción
        nota = numeroNota( valorByte ) ;
        int tempoValor_ = extractNumber( 1 );
        if ( nota == 250 ) {    // ********** es 'tempo' de silencio
          grabar_EEPROM( 250 ) ;  // especifica Pause in EEPROM
          grabar_EEPROM( codetempoPausa( tempoValor_ ) ) ;
        } else {  // es un Tempo de Nota
          grabar_EEPROM( codeTempoNota( tempoValor_ , nota ) ) ;
        }

      } else {
        inByte = inByte.substring(1, inByte.length()) ;
      }
    }

  } while (inByte.length() > 0) ;
}

// ************* extractNumber  *********
long extractNumber( byte recorte_ ) {
  byte valorByte_ ;
  int inByte_length ;
  inByte_length = inByte.length();
  inByte = inByte.substring( recorte_ , inByte_length ) ;
  valorByte_ =  (byte) inByte[0] ;
  while ( valorByte_ == 32 ) { 
    inByte_length = inByte.length();
    inByte = inByte.substring(1, inByte_length);
    valorByte_ =  (byte) inByte[0] ;
  }
  long codigoRF_ = 0 ;
  if (valorByte_ > 47 && valorByte_ < 58) {
    do {
      codigoRF_ = codigoRF_ * 10 + (valorByte_ - 48) ;
      inByte_length = inByte.length();
      inByte = inByte.substring(1, inByte_length) ;
      valorByte_ = (byte) inByte[0] ;
    } while (valorByte_ > 47 && valorByte_ < 58) ;

  }
  return codigoRF_ ;
}

// ************* direccionEEPROM  *********
int direccionEEPROM ( int valor_ ) {
  int punteroEEPPROM_ ;
  switch ( valor_ ) {
    case 1:
      punteroEEPPROM_ = punteroEE_M1 ;
      break ;
    case 2:
      punteroEEPPROM_ = punteroEE_M2 ;
      break ;
    case 3:
      punteroEEPPROM_ = punteroEE_M3 ;
      break ;
  }
  return punteroEEPPROM_ ;
}

// ************* Codificar Nota ****************
byte numeroNota( byte valorByte_ ) {
  byte nota_ ;
  switch ( valorByte_ ) {
    case 68:  // D = Do
      nota_ = 0 ;
      break ;
    case 100: // d = Do sostenido
      nota_ = 1 ;
      break ;
    case 82: // R = Re
      nota_ = 2 ;
      break ;
    case 114: // r = Re sostenido
      nota_ = 3 ;
      break ;
    case 77: // M = Mi
      nota_ = 4 ;
      break ;
    case 70: // F = Fa
      nota_ = 5 ;
      break ;
    case 102: // f = Fa sostenido
      nota_ = 6 ;
      break ;
    case 83: // S = Sol
      nota_ = 7 ;
      break ;
    case 115:  // s = Sol sostenido
      nota_ = 8 ;
      break ;
    case 76:  // L = La
      nota_ = 9 ;
      break ;
    case 108:  // l = La sostenido
      nota_ = 10 ;
      break ;
    case 73: // I = Si
      nota_ = 11 ;
      break ;
    case 84:  // T = Pause
      nota_ = 250 ;
      break ;
  }
  return nota_ ;
}

// ************* codeTempoNota Codificar Tempo de Nota para EEPROM ************
int codeTempoNota(int tempoNota_ , int nota_ ) {
  float tempoFloat_ = tempoNota_ / 49.6;    // Reducimos la nota y el tempo a 1 byte ( 12 notas con 20 tempos redondeados exponenciales a 1.26). 49.6 mS es una constante de inicio
  for (int i = 0; i <= 20; i++) {
    if (tempoFloat_ < 1.1) { // Cada iteración multiplica por 1.26 (la media es 1.1)
      if (i < 10) {    //  El byte XXY -> XX = 0-11 para 'nota' 0-11 , Y = tempo 0-9
        nota_ = nota_ * 10 ;
        tempoNota_ = nota_ + i ;
      }
      else {     //  El byte XXY -> XX = 12-23 para 'nota' 0-11 , Y = tempo 0-9
        nota_ = 120 + nota_ * 10 ;
        tempoNota_ = nota_ + i - 10 ;
      }
        if (octava == 10) { //seguridad por si NO se declara octava, en arranque octava = 10
         octava = 4 ;
         grabar_EEPROM(244) ;
       }
      return tempoNota_ ;
    } else {
      tempoFloat_ = tempoFloat_ / 1.26 ;
    }
  }
}

// ************* codetempoPausa Codificar Tempo de Pausa para EEPROM ************
int codetempoPausa( int tempoNota_ ) {

  if ( tempoNota_ <= 5500 ) {
    float tempoFloat;
    if ( tempoNota_ > 2750 ) {
      tempoFloat = 200 + (tempoNota_ - 2750) / 55 ;
    }
    else if ( tempoNota_ > 1500 ) {
      tempoFloat = 150 + (tempoNota_ - 1500) / 25 ;
    }
    else if ( tempoNota_ > 750 ) {
      tempoFloat = 100 + (tempoNota_ - 750) / 15 ;
    }
    else if ( tempoNota_ > 250 ) {
      tempoFloat = 50 + (tempoNota_ - 250) / 10 ;
    }
    else {
      tempoFloat = tempoNota_ / 5 ;
    }
    tempoNota_ = tempoFloat ;
    return tempoNota_ ;
  }
}

// ***** EEPROMWritelong *************
void EEPROMWritelong(int address, long value) {
  byte four = (value & 0xFF);
  byte three = ((value >> 8) & 0xFF);
  byte two = ((value >> 16) & 0xFF);
  byte one = ((value >> 24) & 0xFF);
  EEPROM.write(address, four);
  EEPROM.write(address + 1, three);
  EEPROM.write(address + 2, two);
  EEPROM.write(address + 3, one);
}

// ***** EEPROMReadlong *************
long EEPROMReadlong(long address) {
  long four = EEPROM.read(address);
  long three = EEPROM.read(address + 1);
  long two = EEPROM.read(address + 2);
  long one = EEPROM.read(address + 3);
  return ((four << 0) & 0xFF) + ((three << 8) & 0xFFFF) + ((two << 16) & 0xFFFFFF) + ((one << 24) & 0xFFFFFFFF);
}

// ***** lecturaRF *************
void lecturaRF( long value ) {

  if (value == 0) {
    return;
  }
  Serial.print("RF>");
  Serial.println( value );
  int valor_ = 10;
  for ( byte i = 0; i < 7; i++ ) {
    if ( value == EEPROMReadlong( punteroEEArray[ i] ) ) {
      valor_ = i;
      break;
    }
  }

  switch ( valor_ ) {
    case 0:
      R2D2Tone();
      R2D2Tone();
      break;
    case 1:
      ruedaIzquierda();
      break;
    case 2:
      ruedaDerecha();
      break;
    case 3:
      movimientoRecto();
      break;
    case 4:
      punteroEEPPROM = punteroEE_M1 ;
      play_EEPROM() ;
      break;
    case 5:
      punteroEEPPROM = punteroEE_M2 ;
      play_EEPROM() ;
      break;
    case 6:
      punteroEEPPROM = punteroEE_M3 ;
      play_EEPROM() ;
      break;
  }
}



// ************* grabar_EEPROM ****************
void grabar_EEPROM( byte valorEEPROM ) {
  EEPROM.write(punteroEEPPROM, valorEEPROM) ;
  punteroEEPPROM++ ;
}


// ***************** play_EEPROM ******************
void play_EEPROM() {
  int valorEEPROM_ ;
  for ( int punteroEE_ = punteroEEPPROM ; punteroEE_ < 512 ; punteroEE_++ ) {
    valorEEPROM_ = EEPROM.read( punteroEE_ ) ;
    if ( valorEEPROM_ == 255 ) {  // Fin de melodia
      break;
    }
    else if ( valorEEPROM_ == 250 ) { // Definicion de mS de pausa
      punteroEE_++ ;
      valorEEPROM_ = EEPROM.read( punteroEE_ ) ;
      tempoPausa = play_Pause( valorEEPROM_ ) ;
    }
    else if ( valorEEPROM_ > 239 && valorEEPROM_ < 250 ) {  // octava
      octava = valorEEPROM_ - 240 ;
     }
    else if ( valorEEPROM_ < 240 ) {   // Nota y tempo
      play_nota( valorEEPROM_ ) ;
    }
  }
}

// ***************** play_nota ******************
void play_nota( int valorEEPROM_  ) {

  int tempoNota_ ;
  int nota_ ;

  if ( valorEEPROM_ < 120 ) {
    nota_ =  valorEEPROM_ / 10 ;
    tempoNota_ = valorEEPROM_ - nota_ * 10 ;
  } else {
    nota_ = ( valorEEPROM_ - 120 ) / 10 ;
    tempoNota_ = 10 + ( valorEEPROM_ - 120 ) - nota_ * 10 ;
  }
  float frecuenciaNota ;
  frecuenciaNota = frecuenciaArray[nota_] * pow(2, octava) ;
  tempoNota = decodeTempoNota( tempoNota_ ) ;
  if ( octava > 4 ) {
    digitalWrite(ledPin1, HIGH);
  }
  else {
    digitalWrite(ledPin2, HIGH);
  }
  tone( speakerPin, frecuenciaNota, tempoNota ) ;
  delay( tempoNota ) ;
  ledOFF();
  noTone( speakerPin ) ;
  delay( tempoPausa ) ;
}

// ***************** decodeTempoNota ******************
int decodeTempoNota ( byte tempo_ ) {
  float decodeTempoNota_ =  49.6 * pow( 1.26 , tempo_ ) ;
  return decodeTempoNota_ ;
}

// ***************** play_Pause ******************
int play_Pause( byte valorPause_ ) {
  int valor_ ;
  if ( valorPause_ > 200 ) {
    valor_ = 2750 + ( valorPause_ - 200 ) * 50 ;
  }
  else if ( valorPause_ > 150 ) {
    valor_ = 1500 + ( valorPause_ - 150 ) * 25 ;
  }
  else if ( valorPause_ > 100 ) {
    valor_ = 750 + ( valorPause_ - 100 ) * 15 ;
  }
  else if ( valorPause_ > 50 ) {
    valor_ = 250 + ( valorPause_ - 50 ) * 10 ;
  }
  else  {
    valor_ =  valorPause_ * 5 ;
  }
  return valor_ ;
}

// ***************** SONIDO R2D2 ******************
void phrase1() {
  int k = random(1000, 2000);
  ledON();
  for (int i = 0; i <=  random(100, 2000); i++) {
    tone(speakerPin, k + (-i * 2));
    delay(random(.9, 2));
  }
  ledOFF();
  for (int i = 0; i <= random(100, 1000); i++) {
    tone(speakerPin, k + (i * 10));
    delay(random(.9, 2));
  }
}

// ***************** phrase2 ******************
void phrase2() {
  int k = random(1000, 2000);
  ledON();
  for (int i = 0; i <= random(100, 2000); i++) {
    tone(speakerPin, k + (i * 2));
    delay(random(.9, 2));
  }
  ledOFF();
  for (int i = 0; i <= random(100, 1000); i++) {
    tone(speakerPin, k + (-i * 10));
    delay(random(.9, 2));
  }
}

// ***************** R2D2Tone ******************
void R2D2Tone() {
  myservo.attach(pinServo);
  if ( direccion == true ) {
    direccion = false;
  } else {
    direccion = true;
  }
  int K = 2000;
  switch (random(1, 7)) {
    case 1: phrase1(); break;
    case 2: phrase2(); break;
    case 3: phrase1(); phrase2(); break;
    case 4: phrase1(); phrase2(); phrase1(); break;
    case 5: phrase1(); phrase2(); phrase1(); phrase2(); phrase1(); break;
    case 6: phrase2(); phrase1(); phrase2(); break;
  }
  for (int i = 0; i <= random(3, 9); i++) {

    ledON();
    tone(speakerPin, K + random(-1700, 2000));
    if ( direccion == true && posServo < (i * incrementoServo + ceroServo) ) {
      myservo.write(i * incrementoServo + ceroServo);
      posServo = i * incrementoServo + ceroServo ;
    }
    if ( direccion == false && posServo > (ceroServo - i * incrementoServo) ) {
      myservo.write(ceroServo - i * incrementoServo);
      posServo = ceroServo - i * incrementoServo ;
    }

    delay(random(70, 170));
    ledOFF();
    noTone(speakerPin);
    delay(random(0, 30));
  }
  noTone(speakerPin);

  if ( direccion == false ) {
    incremento = ceroServo - posServo;
    incremento = 2000 / incremento;
    for (pos = posServo; pos <= ceroServo; pos += 1)
    {
      myservo.write(pos);
      parpadeo = random(10);
      if (parpadeo > 2) {
        ledON();
      } else {
        ledOFF();
      }
      delay(incremento);
    }
  }
  if ( direccion == true ) {
    incremento = posServo - ceroServo;
    incremento = 2000 / incremento;
    for (pos = posServo; pos >= ceroServo; pos -= 1)
    {
      myservo.write(pos);
      parpadeo = random(10);
      if (parpadeo > 2) {
        ledON();
      } else {
        ledOFF();
      }
      delay(incremento);
    }
  }
  ledOFF();
  delay(random(1000));
  myservo.detach();
}

// ************* ruedaIzquierda****************
void ruedaIzquierda() {
  digitalWrite(izqPin, HIGH);
  delay(mS_PulseI);
  digitalWrite(izqPin, LOW);
}

// ************* ruedaDerecha ****************
void ruedaDerecha() {
  digitalWrite(derPin, HIGH);
  delay(mS_PulseD);
  digitalWrite(derPin, LOW);
}

// ************* movimientoRecto ****************
void movimientoRecto() {
  digitalWrite(izqPin, HIGH);
  digitalWrite(derPin, HIGH);
  if (mS_PulseI > mS_PulseD) {
    delay(mS_PulseD);
    digitalWrite(derPin, LOW);
    delay(mS_PulseI - mS_PulseD);
    digitalWrite(izqPin, LOW);
  } else {
    delay(mS_PulseI);
    digitalWrite(izqPin, LOW);
    if (mS_PulseD > mS_PulseI) {
      delay(mS_PulseD - mS_PulseI);
    }
    digitalWrite(derPin, LOW);
  }
}

// ************* ledON ****************
void ledON() {
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
}

// ************* ledOFF ****************
void ledOFF() {
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
}

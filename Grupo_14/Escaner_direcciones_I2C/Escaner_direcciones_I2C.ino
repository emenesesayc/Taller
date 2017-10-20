/*  TITULO: Escaner de direcciones I2C

    AUTOR:
    
    MARIANO DEL CAMPO GARCÍA (@2016) --> INGENIERO TÉCNICO INDUSTRIAL ESPECIALIDAD ELECTRÓNICA
    - FACEBOOK: https://www.facebook.com/mariano.delcampogarcia
    - TWITTER: https://twitter.com/MarianoCampoGa
    - CORREO: marianodc83@gmail.com
    
    
    DESCRIPCIÓN DEL PROGRAMA
    
    Este programa sirve para buscar la dirección de comunicación I2C, en dispositivos conectados a nuestro
    Arduino mediante este protocolo de comunicación. El programa nos envía todas las direcciones de los 
    dispositivos I2C que tengamos conectados en un determinado instante a través del monitor serie del IDE
    de Arduino. En este caso vamos a utilizar el escaner I2C para encontrar la dirección de un display LCD
    1602 conectado a través de este protocolo de comunicación. 
  
 
    ESQUEMA DE CONEXION
    
                                      +-----+
         +----[PWR]-------------------| USB |--+
         |                            +-----+  |
         |         GND/RST2  [ ][ ]            |
         |       MOSI2/SCK2  [ ][ ]  A5/SCL[ ] |   SCL del módulo I2C conectado al LCD 1602
         |          5V/MISO2 [ ][ ]  A4/SDA[ ] |   SDA del módulo I2C conectado al LCD 1602
         |                             AREF[ ] |
         |                              GND[ ] |
         | [ ]N/C                    SCK/13[ ] |   
         | [ ]IOREF                 MISO/12[ ] |   
         | [ ]RST                   MOSI/11[ ]~|   
         | [ ]3V3    +---+               10[ ]~|   
         | [ ]5v    -| A |-               9[ ]~|   
         | [ ]GND   -| R |-               8[ ] |   
         | [ ]GND   -| D |-                    |
         | [ ]Vin   -| U |-               7[ ] |   
         |          -| I |-               6[ ]~|   
         | [ ]A0    -| N |-               5[ ]~|   
         | [ ]A1    -| O |-               4[ ] |   
         | [ ]A2     +---+           INT1/3[ ]~|  
         | [ ]A3                     INT0/2[ ] |   
         | [ ]A4/SDA  RST SCK MISO     TX>1[ ] |   
         | [ ]A5/SCL  [ ] [ ] [ ]      RX<0[ ] |   
         |            [ ] [ ] [ ]              |
         |  UNO_R3    GND MOSI 5V  ____________/
          \_______________________/

  NOTAS:
   - La alimentación y la masa del módulo LCM 1602 I2C V1 instalado en el LCD 1602, van directamente conectadas
     a VCC (+5V) y GND respectivamente.  
*/

// Librería necesaria para comunicación I2C
#include <Wire.h>


void setup()
{
  Wire.begin(); // Iniciamos la comunicación I2C

  Serial.begin(9600); // Iniciamos la comunicación con el monitor serie
  //while (!Serial);             // Leonardo: wait for serial monitor
  Serial.println("\nEscaner de direcciones I2C");
}


void loop()
{
  byte error, address;
  int nDevices;

  Serial.println("Escaneando...");

  nDevices = 0;
  for(address = 1; address < 127; address++ ) 
  {
    // Se utiliza el valor de retorno de Write.endTransmisstion() para ver si se ha reconocido
    // o no la dirección I2C de un dispositivo
   
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("Dispositivo I2C encontrado en la direccion 0x");
      if (address<16) 
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("!");

      nDevices++;
    }
    else if (error == 4) 
    {
      Serial.print("Error desconocido en la direccion 0x");
      if (address<16) 
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No se han encontrado direcciones I2C de ningun dispositivo \n");
  else
    Serial.println("Hecho\n");

  delay(5000);           // Espera 5 segundos hasta el siguiente escaneo
}


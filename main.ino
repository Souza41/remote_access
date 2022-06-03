char selection, incomingByte = 0;
int tact[] = {42, 40, 38, 36, 30, 28, 24, 22};
int encoderPositions[] = {46, 48, 50, 52};
int powerRecicleTime = 5000;
int posicaoAtual = 1;
bool ligar = 0, powerSupply = 0, lid = 1, onOff = 0;
bool desligar = 1;
void mudaEncoder(int posicao);
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(tact[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(encoderPositions[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++) {
    digitalWrite(encoderPositions[i], LOW);
  }
  for (int i = 0; i < 8; i++) {
    digitalWrite(tact[i], desligar);
  }
  rotateEncoder(posicaoAtual, posicaoAtual, 10);
}

void mudaEncoder(int posicao) {

  if (posicao == 1) {
    digitalWrite(encoderPositions[0], LOW);
    digitalWrite(encoderPositions[1], LOW);
    digitalWrite(encoderPositions[2], HIGH);
    digitalWrite(encoderPositions[3], LOW);
  }
  else if (posicao == 2) {
    digitalWrite(encoderPositions[0], LOW);
    digitalWrite(encoderPositions[1], HIGH);
    digitalWrite(encoderPositions[2], HIGH);
    digitalWrite(encoderPositions[3], LOW);
  }
  else if (posicao == 3) {
    digitalWrite(encoderPositions[0], LOW);
    digitalWrite(encoderPositions[1], HIGH);
    digitalWrite(encoderPositions[2], HIGH);
    digitalWrite(encoderPositions[3], HIGH);
  }
  else if (posicao == 4) {
    digitalWrite(encoderPositions[0], HIGH);
    digitalWrite(encoderPositions[1], HIGH);
    digitalWrite(encoderPositions[2], HIGH);
    digitalWrite(encoderPositions[3], HIGH);
  }
  else if (posicao == 5) {
    digitalWrite(encoderPositions[0], HIGH);
    digitalWrite(encoderPositions[1], HIGH);
    digitalWrite(encoderPositions[2], HIGH);
    digitalWrite(encoderPositions[3], LOW);
  }
  else if (posicao == 6) {
    digitalWrite(encoderPositions[0], HIGH);
    digitalWrite(encoderPositions[1], HIGH);
    digitalWrite(encoderPositions[2], LOW);
    digitalWrite(encoderPositions[3], LOW);
  }
  else if (posicao == 7) {
    digitalWrite(encoderPositions[0], HIGH);
    digitalWrite(encoderPositions[1], HIGH);
    digitalWrite(encoderPositions[2], LOW);
    digitalWrite(encoderPositions[3], HIGH);
  }
  else if (posicao == 8) {
    digitalWrite(encoderPositions[0], HIGH);
    digitalWrite(encoderPositions[1], LOW);
    digitalWrite(encoderPositions[2], LOW);
    digitalWrite(encoderPositions[3], HIGH);
  }
  else if (posicao == 9) {
    digitalWrite(encoderPositions[0], HIGH);
    digitalWrite(encoderPositions[1], LOW);
    digitalWrite(encoderPositions[2], LOW);
    digitalWrite(encoderPositions[3], LOW);
  }
  else if (posicao == 10) {
    digitalWrite(encoderPositions[0], HIGH);
    digitalWrite(encoderPositions[1], LOW);
    digitalWrite(encoderPositions[2], HIGH);
    digitalWrite(encoderPositions[3], LOW);
  }
  else if (posicao == 11) {
    digitalWrite(encoderPositions[0], HIGH);
    digitalWrite(encoderPositions[1], LOW);
    digitalWrite(encoderPositions[2], HIGH);
    digitalWrite(encoderPositions[3], HIGH);
  }
  else if (posicao == 12) {
    digitalWrite(encoderPositions[0], LOW);
    digitalWrite(encoderPositions[1], LOW);
    digitalWrite(encoderPositions[2], HIGH);
    digitalWrite(encoderPositions[3], HIGH);
  }
}
void rotateEncoder(int start, int endc, int rotationTime) {
  posicaoAtual = start;
  while (true) {
    mudaEncoder(posicaoAtual);
    if (posicaoAtual == endc) break;
    delay(rotationTime);
    if (posicaoAtual < 12) posicaoAtual++;
    else posicaoAtual = 1;
  }
  status(powerSupply, lid, posicaoAtual);
}
void status(bool powerSupply, bool lid, int cycle) {
  Serial.println("\t\t\t\t    Tacts");
  Serial.println("(0)ON/OFF");
  Serial.println("(1)Start/Pause");
  Serial.println("(2)Double Basket");
  Serial.println("(3)Options");
  Serial.println("(4)Water Level");
  Serial.println("(5)Skip Phase");
  Serial.println("(6)Open Lid");
  Serial.println("(7)Close Lid");
  Serial.println("(8)Power On");
  Serial.println("(9)Power Off");
  Serial.println("\t\t\t\t    Routines");
  Serial.println("(a)Power Failure");
  Serial.println("(b)End Line");
  Serial.println("(c)Top Lid");
  Serial.println("(d)rotate");

  if (lid == 1)
    Serial.println("\n Lid Closed");
  else
    Serial.println("\n Lid Open");

  if (powerSupply == 1)
    Serial.println("\n Power Supply On");
  else
    Serial.println("\n Power Supply Off");

  Serial.print("\n Cycle: ");
  Serial.println(cycle);
  for (int i = 0; i < 19; i++) Serial.println("  ");
}
void powerFailure() {
  digitalWrite(tact[7], desligar);
  delay(powerRecicleTime);
  digitalWrite(tact[7], ligar);
}

int menu() {

  if (Serial.available() > 0) {
    selection = Serial.read();
    switch (selection) {
      case '0':
        digitalWrite(tact[0], ligar);
        delay(200);
        digitalWrite(tact[0], desligar);
        if (onOff == 0)onOff = 1;
        else onOff = 0;
        break;
      case '1':
        digitalWrite(tact[1], ligar);
        delay(200);
        digitalWrite(tact[1], desligar);
        break;
      case '2':
        digitalWrite(tact[2], ligar);
        delay(200);
        digitalWrite(tact[2], desligar);
        break;
      case '3':
        digitalWrite(tact[3], ligar);
        delay(200);
        digitalWrite(tact[3], desligar);
        break;
      case '4':
        digitalWrite(tact[4], ligar);
        delay(200);
        digitalWrite(tact[4], desligar);
        break;
      case '5':
        digitalWrite(tact[5], ligar);
        delay(200);
        digitalWrite(tact[5], desligar);
        break;

      case '6':
        digitalWrite(tact[6], ligar);
        lid = 0;
        status(powerSupply, lid, posicaoAtual);
        break;

      case '7':
        digitalWrite(tact[6], desligar);
        lid = 1;
        status(powerSupply, lid, posicaoAtual);
        break;

      case '8':
        digitalWrite(tact[7], ligar);
        powerSupply = 1;
        status(powerSupply, lid, posicaoAtual);
        break;
      case '9':
        digitalWrite(tact[7], desligar);
        powerSupply = 0;
        status(powerSupply, lid, posicaoAtual);
        break;
      case 'a':
        powerFailure();
        break;

      case 'b':
        //end line, precisa do encoder
        if (onOff == 1) {
          digitalWrite(tact[0], ligar);
          delay(200);
          digitalWrite(tact[0], desligar);
          onOff = 0;
          delay(5000);
        }
        powerFailure();
        digitalWrite(tact[6], desligar);
        lid = 1;
        status(powerSupply, lid, posicaoAtual);
        delay(12000);
        digitalWrite(tact[3], ligar);
        digitalWrite(tact[4], ligar);
        delay(500);
        digitalWrite(tact[3], desligar);
        digitalWrite(tact[4], desligar);
        delay(500);
        digitalWrite(tact[6], ligar);
        delay(1000);
        digitalWrite(tact[6], desligar);

        break;
      case 'c':
        if (onOff == 1) {
          digitalWrite(tact[0], ligar);
          delay(200);
          digitalWrite(tact[0], desligar);
          onOff = 0;
          delay(5000);
        }
        powerFailure();
        digitalWrite(tact[6], desligar);
        lid = 1;
        status(powerSupply, lid, posicaoAtual);
        delay(12000);
        digitalWrite(tact[2], ligar);
        digitalWrite(tact[4], ligar);
        delay(500);
        digitalWrite(tact[2], desligar);
        digitalWrite(tact[4], desligar);
        break;

      case 'd':
        for (int i = 0; i < 21; i++) Serial.println("  ");
        Serial.println("Type the initial cycle number");
        for (int i = 0; i < 40; i++) Serial.println("  ");
        int start = Serial.read();
        while (true) {
          if (Serial.available() > 0) {
            start = Serial.parseInt();
            break;
          }
        }
        Serial.println("Type the end cycle number");
        for (int i = 0; i < 40; i++) Serial.println("  ");
        int endc = Serial.read();
        while (true) {
          if (Serial.available() > 0) {
            endc = Serial.parseInt();
            break;
          }
        }
        Serial.println("Type the rotation time in ms");
        for (int i = 0; i < 40; i++) Serial.println("  ");
        int rotationTime = Serial.read();
        while (true) {
          if (Serial.available() > 0) {
            rotationTime = Serial.parseInt();
            break;
          }
        }

        rotateEncoder(start, endc, rotationTime);
        break;
    }
  }
}

void loop() {
  menu();
}

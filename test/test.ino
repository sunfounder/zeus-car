
char testString[] = "3;5;10,30;forward;false;true;4;-100;40.4;50,60;-45.5;backward;50564,33630,333";
char testString2[200] = ";;;;;;;;;;;;;;;;;;;;;;;;;";

void getStrOf(char* str, uint8_t index, char* result, char divider=';') {
  uint8_t start, end;
  uint8_t length = strlen(str);
  uint8_t i, j;
  // Get start index
  if (index == 0) {
    start = 0;
  } else {
    for (start = 0, j = 1; start < length; start++) {
      if (str[start] == divider) {
        if (index == j) {
          start++;
          break;
        }
        j++;
      }
    }
  }
  // Get end index
  for (end = start, j = 0; end < length; end++) {
    // Serial.println((int)str[end]);
    if (str[end] == divider) {
      break;
    }
  }
  // Copy result
  for (i = start, j = 0; i < end; i++, j++) {
    result[j] = str[i];
  }
  result[j] = '\0';
}

void setStrOf(char* str, uint8_t index, String value, char divider) {
  uint8_t start, end;
  uint8_t length = strlen(str);
  uint8_t i, j;
  // Get start index
  if (index == 0) {
    start = 0;
  } else {
    for (start = 0, j = 1; start < length; start++) {
      if (str[start] == divider) {
        if (index == j) {
          start++;
          break;
        }
        j++;
      }
    }
  }
  // Get end index
  for (end = start, j = 0; end < length; end++) {
    // Serial.println((int)str[end]);
    if (str[end] == divider) {
      break;
    }
  }
  // Set value result
  String strValue = String(str).substring(0, start) + value + String(str).substring(end);
  strcpy(str, strValue.c_str());
  Serial.println(str);
}

int16_t getIntOf(char* str, uint8_t index) {
  int16_t result;
  char strResult[20];
  getStrOf(str, index, strResult);
  result = String(strResult).toInt();
  return result;
}

bool getBoolOf(char* str, uint8_t index) {
  char strResult[20];
  getStrOf(str, index, strResult);
  return String(strResult) == "true";
}

double getDoubleOf(char* str, uint8_t index) {
  double result;
  char strResult[20];
  getStrOf(str, index, strResult);
  result = String(strResult).toDouble();
  return result;
}


void setup() {
  Serial.begin(115200);

  Serial.println("Start!");

  // setStrOf(testString2, 0, "3", ';');
  // setStrOf(testString2, 1, "5", ';');
  // setStrOf(testString2, 2, "10,30", ';');
  // setStrOf(testString2, 3, "forward", ';');
  // setStrOf(testString2, 4, "false", ';');
  // setStrOf(testString2, 5, "true", ';');
  // setStrOf(testString2, 6, "4", ';');
  // setStrOf(testString2, 7, "-100", ';');
  // setStrOf(testString2, 8, "40.4", ';');
  // setStrOf(testString2, 9, "50,60", ';');
  // setStrOf(testString2, 10, "-45.5", ';');
  // setStrOf(testString2, 11, "backward", ';');
  setStrOf(testString2, 12, "50564,33630,333", ';');

  int16_t resultA;
  int16_t resultB;
  char resultC[10];
  char resultD[10];
  bool resultE;
  bool resultF;
  int16_t resultG;
  int16_t resultH;
  double resultI;
  char resultJ[10];
  double resultK;
  char resultL[10];
  char resultM[10];
  char resultN[10];
  char resultO[10];
  char resultP[10];
  char resultQ[10];
  resultA = getIntOf(testString2, 0);
  resultB = getIntOf(testString2, 1);
  getStrOf(testString2, 2, resultC);
  getStrOf(testString2, 3, resultD);
  resultE = getBoolOf(testString2, 4);
  resultF = getBoolOf(testString2, 5);
  resultG = getIntOf(testString2, 6);
  resultH = getIntOf(testString2, 7);
  resultI = getDoubleOf(testString2, 8);
  getStrOf(testString2, 9, resultJ);
  resultK = getDoubleOf(testString2, 10);
  getStrOf(testString2, 11, resultL);
  getStrOf(testString2, 12, resultM);
  getStrOf(testString2, 13, resultN);
  getStrOf(testString2, 14, resultO);
  getStrOf(testString2, 15, resultP);
  getStrOf(testString2, 16, resultQ);
  Serial.print("A: ");
  Serial.println(resultA);
  Serial.print("B: ");
  Serial.println(resultB);
  Serial.print("C: ");
  Serial.println(resultC);
  Serial.print("D: ");
  Serial.println(resultD);
  Serial.print("E: ");
  Serial.println(resultE);
  Serial.print("F: ");
  Serial.println(resultF);
  Serial.print("G: ");
  Serial.println(resultG);
  Serial.print("H: ");
  Serial.println(resultH);
  Serial.print("I: ");
  Serial.println(resultI);
  Serial.print("J: ");
  Serial.println(resultJ);
  Serial.print("K: ");
  Serial.println(resultK);
  Serial.print("L: ");
  Serial.println(resultL);
  Serial.print("M: ");
  Serial.println(resultM);
  Serial.print("N: ");
  Serial.println(resultN);
  Serial.print("O: ");
  Serial.println(resultO);
  Serial.print("P: ");
  Serial.println(resultP);
  Serial.print("Q: ");
  Serial.println(resultQ);
}

void loop() {}
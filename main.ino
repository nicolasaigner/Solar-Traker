// Variáveis dos sensores LDR;
//Conecte o sensor LDR que vai ficar para direita na porta Analógica A0 e o LDR para a esquerda na porta analógica A1;
int right = A0;
int left = A1;
//Variáveis para armazenamento dos valores dos LDR's instanciadas em 0 para limpar qualquer tipo de cache;
int valueRight = 0;
int valueLeft = 0;
//Variável para armazenamento do total da subtração dos valores do sensores LDR instanciada em 0 para limpar o cache;
int total = 0;
//Variáveis para portas de saída;
//Conecte a saída para ativar a direita na porta 3 e a saída para a esquerda na porta 4;
int outputRight = 3;
int outputLeft = 4;

void setup() {
  //Ativação das portas de saída;
  pinMode(outputRight, OUTPUT);
  pinMode(outputLeft, OUTPUT);

  //Entradas das portas dos LDR's
  pinMode(right, INPUT);
  pinMode(left, INPUT);
  Serial.begin(9600);
}
 
void loop() {
  //Mantendo inativa as portas de saída;
  digitalWrite(outputRight, LOW);
  digitalWrite(outputLeft, LOW);

  //Captura dos dados das portas analógicas onde estão conectadas os LDR's;
  valueRight = analogRead(right);
  valueLeft = analogRead(left);

  //Subtração para o valor de controle;
  total = valueRight - valueLeft;

  //Condição para o caso do LDR da direita receber mais luz, ativar a porta da esquerda;
  if (total > 100) {
    Serial.print ("Right: ");
    Serial.print (valueRight);
    Serial.print (" | Left: ");
    Serial.println(valueLeft);
    digitalWrite(outputLeft, HIGH);
  }

  //Condição para o caso do LDR da esquerda receber mais luz, ativar a porta da direita;
  if (total < -100) {
    Serial.print ("Right: ");
    Serial.print (valueRight);
    Serial.print (" | Left: ");
    Serial.println(valueLeft);
    digitalWrite(outputRight, HIGH);
  } 

  //Condição para o caso do LDR da direita e da esquerda estiverem com a mesma faixa de luz;
  if (total < 100 && total > -100) {
    digitalWrite(outputRight, LOW);
    digitalWrite(outputLeft, LOW);
    Serial.print ("Right: ");
    Serial.print (valueRight);
    Serial.print (" | Left: ");
    Serial.println(valueLeft);
    Serial.println (" = Off");
  }

  //Repetição a cada 1 segundo (1000 milisegundos);
  delay(1000);
}

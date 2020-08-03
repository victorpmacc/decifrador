/* Tarefa de decifrar uma cifra
 *
 * Dica: veja em referencia/cifrador.c o codigo-fonte do programa
 * que gerou as cifras que voce precisa decifrar!
 */

#include <stdio.h>

#define TAM_BUFFER 55
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];

const char senha[] = "SENHASECRETA";

int modulo(int a, int b){
 int resto = a%b;
 return resto < 0 ? resto + b : resto;
}
char decrypt(char letter, char key){
  char letter0, key0, result;
  if ((letter >= 'A') && (letter <= 'Z')){
    letter0 = letter - 'A';
    key0 = key - 'A';
    result = 'A' + modulo(letter0 - key0, 26); // A função para decifrar foi extraída da formulação algébrica de decrifagem da cifa de Vigenère
    return result;
  } else return letter;
}
int main() {
  /* Leitura da entrada */
  fgets(buffer_entrada, TAM_BUFFER, stdin);
  
  int i = 0;
  int j = 0;
  for(i = 0; (i<TAM_BUFFER) && (buffer_entrada[i] != '\0') && (buffer_entrada[i] != '\n'); i++){
    buffer_saida[i] = decrypt(buffer_entrada[i], senha[j]);
    j++;
    if (senha[j] == '\0') j=0;
  }
  buffer_saida[i] = '\0';
  
  /* Escrever saida na tela */
  printf("%s\n", buffer_saida);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char password[] = "";
const short int DEFAULT_LENGTH = 100;

int generateNumber(int maxNumber){
    short int number = rand() % maxNumber + 1;
    return number;
}
char generateLetter(int letterType){
    // letterType = 0 - Default, 1 - lowecase only, 2 - uppercase only
    int letterID = rand() % 26 + 1;
    char letter;
    char letterList[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    letter = letterList[letterID];
    return letter;
}
int changeTypeDecider(int maxTypeNum){
    return rand() % 2 + 1;
}

int main(int argc, char* argv[]){
    srand(time(0));
    int stepTypeDecider; // Used to determine what symbol to generate next
    const short int NUM_OF_STEP_TYPES = 2;
    int passwordLength = strlen(password);

    // Buffer
    int bufferNumber;
    char bufferLetter;

    for(int i = 0; i < DEFAULT_LENGTH; i++){
        stepTypeDecider = changeTypeDecider(NUM_OF_STEP_TYPES);
        passwordLength = strlen(password);
        switch(stepTypeDecider){
            case 1:
                bufferNumber = generateNumber(9);
                char temp[8];
                sprintf(temp, "%d", bufferNumber);
                strcat(password, temp);
                break;
            case 2:
                bufferLetter = generateLetter(0);
                password[passwordLength] = bufferLetter;
                break;
            default:
                printf("Error, unexpected step type");
                break;
        }
    }
    printf("%s", password);
    
    return 0;
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void passone(){
    int locctr=0, start=0, length=0;
    FILE *fp1, *fp2, *fp3, *fp4, *fp5;
    char label[20], opcode[20], operand[20], code[20], mnemonic[20];


    fp1 = fopen("input.txt", "r");
    fp2 = fopen("optab.txt", "r");
    fp3 = fopen("symtab.txt", "w");
    fp4 = fopen("intermediate.txt", "w");
    fp5 = fopen("length.txt", "w");
    
    if (!fp1 || !fp2 || !fp3 || !fp4 || !fp5){
        printf("Error opening files!!");
        return;
        
    }
    if(fscanf(fp1, "%s\t%s\t%s", label, opcode, operand)!=3){
                printf("cannot opening inoput.txt!!");
                return;
                

    }
    
    if(strcmp(opcode, "START")==0){
        start= (int) strtol(operand, NULL, 16);
        locctr=start;
        fprintf(fp4, "\t%s\t%s\t%s\n", label, opcode, operand);
        
        
    }
    else{
        locctr=0;
        
    }
    while(fscanf(fp1, "%s\t%s\t%s", label, opcode, operand)==3){
        if(strcmp(opcode,"END")==0){
            break;
        }
        fprintf(fp4, "%04X\t%s\t%s\t%s\n",locctr, label, opcode, operand);
        
        if(strcmp(label,"**")!=0){
            fprintf(fp3, "%s\t%04X\n",label, locctr);
        }
        rewind(fp2);
        int found = 0;
        
        while(fscanf(fp2, "%s\t%s", code, mnemonic)==2){
            if(strcmp(opcode, code) == 0){
            locctr+=3;
            found=1;
            break;
            }
        }
        
        if(!found){
            if(strcmp(opcode,"WORD")==0)
                locctr+=3;
            else if(strcmp(opcode,"RESW")==0){
                locctr+=3*(atoi(operand));
                
            }
            else if(strcmp(opcode,"RESB")==0){
                locctr+=(atoi(operand));
                
            }
            else if(strcmp(opcode,"BYTE")==0){
                if(operand[0]=='C'){
                    locctr+=strlen(operand)-3;
                }
                else if(operand[0]=='X'){
                    locctr+=(strlen(operand)-3)/2;
                }
                else locctr+=1;
            }
        }
    }
    fprintf(fp4, "%04X\t%s\t%s\t%s\n",locctr, label, opcode, operand);
    
    length=locctr-start;
    fprintf(fp5, "%d", length);
    printf("\nThe length of the code: %X\n", length);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
    
    
}


int main(){
   passone();
    return 0;
}




-----------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PASS1() {
    char label[20], opcode[20], operand[20], code[20], mnemonic[20];
    int locctr = 0, start = 0, length = 0;
    FILE *fp1, *fp2, *fp3, *fp4, *fp5;

    // Open files
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("optab.txt", "r");
    fp3 = fopen("symtab.txt", "w");
    fp4 = fopen("intermediate.txt", "w");
    fp5 = fopen("length.txt", "w");

    if (!fp1 || !fp2 || !fp3 || !fp4 || !fp5) {
        printf("Error opening one or more files.\n");
        return;
    }

    // Read first line from input.txt
    if (fscanf(fp1, "%s %s %s", label, opcode, operand) != 3) {
        printf("Error reading input file.\n");
        return;
    }

    // Handle START directive
    if (strcmp(opcode, "START") == 0) {
        start = (int)strtol(operand, NULL, 16); // supports hex
        locctr = start;
        fprintf(fp4, "\t%s\t%s\t%s\n", label, opcode, operand); 
    } else {
        locctr = 0;
    }

    // Process until END
    while (fscanf(fp1, "%s %s %s", label, opcode, operand) == 3) {
        if (strcmp(opcode, "END") == 0)
            break;

        fprintf(fp4, "%04X\t%s\t%s\t%s\n", locctr, label, opcode, operand);

        // Add label to SYMTAB if not "**"
        if (strcmp(label, "**") != 0)
            fprintf(fp3, "%s\t%04X\n", label, locctr);

        // Search OPTAB
        rewind(fp2);
        int found = 0;
        while (fscanf(fp2, "%s %s", code, mnemonic) == 2) {
            if (strcmp(opcode, code) == 0) {
                locctr += 3;
                found = 1;
                break;
            }
        }

        // Not found → must be directive
        if (!found) {
            if (strcmp(opcode, "WORD") == 0)
                locctr += 3;
            else if (strcmp(opcode, "RESW") == 0)
                locctr += 3 * atoi(operand);
            else if (strcmp(opcode, "RESB") == 0)
                locctr += atoi(operand);
            else if (strcmp(opcode, "BYTE") == 0) {
                if (operand[0] == 'C')
                    locctr += strlen(operand) - 3;
                else if (operand[0] == 'X')
                    locctr += (strlen(operand) - 3) / 2;
                else
                    locctr += 1;
            }
        }
    }

    // Write END line
    fprintf(fp4, "%04X\t%s\t%s\t%s\n", locctr, label, opcode, operand);

    // Compute and write program length
    length = locctr - start;
    fprintf(fp5, "%d", length);
    printf("\nThe length of the code: %X\n", length);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
}

int main() {
    PASS1();
    return 0;
}

----------------------------------------

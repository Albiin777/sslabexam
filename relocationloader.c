#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int main(){
    int i, first=1;
    unsigned int start_addr,file_addr, reloc_addr;
    char line[200];
    FILE *fp;
    
    fp=fopen("input.txt","r");
    
    if(!fp){
        printf("Cannot open file!!");
        return 1;
        
    }
    
    printf("Enter relocation address: ");
    scanf("%x", &start_addr);
    
        printf(" RELOCATING Loader\n");
        printf("LOCATION \t CODE \n");

    while(fgets(line, sizeof(line), fp)){
        if(line[0]!='T')continue;
        
        
        sscanf(&line[2], "%6x", &file_addr);
       
        
        if(first){
             reloc_addr=start_addr-file_addr;
            printf("Relocating factor= %X - %X = %X\n\n", start_addr, file_addr, reloc_addr);
            first=0;
        }
        
        for(i=12;line[i]!='\0';){
            if(line[i] =='^' || !isxdigit(line[i])){i++; continue;}
            if(!isxdigit(line[i+1]))break;
            
            printf("%06X\t\t%c%c\n", file_addr++ + reloc_addr , line[i],line[i+1]);
            i+=2;
        }
    }
    fclose(fp);
    return 0;
}

--------------------------------
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char line[200];
    unsigned int start_addr, file_addr, relocation_factor;
    int i, first = 1;

    printf("Enter relocation start address (hex): ");
    scanf("%x", &start_addr);

    fp = fopen("input.txt", "r");
    if (!fp) {
        printf("Error opening input.txt\n");
        return 1;
    }

    printf("\nRELOCATING LOADER OUTPUT\n");
    printf("Location\t\tCode\n");

    while (fgets(line, sizeof(line), fp)) {
        if (line[0] != 'T') continue;

        sscanf(&line[2], "%6x", &file_addr);

        if (first) {
            relocation_factor = start_addr - file_addr;
            printf("\nRelocation factor = %X - %X = %X\n\n",
                   start_addr, file_addr, relocation_factor);
            first = 0;
        }

        // ✅ Start from after 12th character where actual object codes begin
        for (i = 12; line[i] != '\0'; i++) {
            if (line[i] == '^' || line[i] == '\n') continue;  // skip separators/newlines

            // ✅ Ensure there are two hex digits
            if (isxdigit(line[i]) && isxdigit(line[i+1])) {
                printf("%06X\t\t%c%c\n", file_addr++ + relocation_factor, line[i], line[i+1]);
                i++; // move to next pair
            }
        }
    }

    fclose(fp);
    return 0;
}


----------------------------------

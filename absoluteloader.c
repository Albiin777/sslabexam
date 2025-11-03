#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int main(){
    int i;
    unsigned int addr;
    char line[200];
    FILE *fp;
    
    fp=fopen("input.txt","r");
    
    if(!fp){
        printf("Cannot open file!!");
        return 1;
        
    }
        printf(" ABS Loader\n");
        printf("LOCATION \t CODE \n");

    while(fgets(line, sizeof(line), fp)){
        if(line[0]!='T')continue;
        
        
        sscanf(&line[2], "%6x", &addr);
        
        int cc=0;
        for(i=0; line[i]!='\0';i++)
        {
            if(line[i]=='^')cc++;
            if(cc==3) {i++; break;}
            
        }
        for(;line[i]!='\0';){
            if(line[i] =='^' || !isxdigit(line[i])){i++; continue;}
            if(!isxdigit(line[i+1]))break;
            
            printf("%06X\t\t%c%c\n", addr++, line[i],line[i+1]);
            i+=2;
        }
    }
    fclose(fp);
    return 0;
}


----------------------------------------------
  #include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char line[200];
    unsigned int addr;
    int i;

    fp = fopen("input.txt", "r");
    if (!fp) {
        printf("Error opening input1.txt\n");
        return 1;
    }

    printf("\nABSOLUTE LOADER OUTPUT\n");
    printf("Location\tCode\n");

    while (fgets(line, sizeof(line), fp)) {
        if (line[0] != 'T') continue;  // process only text records

        // Read the starting address (6 hex digits after 'T^')
        sscanf(&line[2], "%6x", &addr);

        // Find start of object codes (after 3rd '^')
        int caret_count = 0;
        for (i = 0; line[i] != '\0'; i++) {
            if (line[i] == '^') caret_count++;
            if (caret_count == 3) { i++; break; }
        }

        // Print object code bytes
        for (; line[i] != '\0'; ) {
            if (line[i] == '^' || !isxdigit(line[i])) { i++; continue; }
            if (!isxdigit(line[i+1])) break;
            printf("%06X\t\t%c%c\n", addr++, line[i], line[i+1]);
            i += 2;
        }
    }

    fclose(fp);
    return 0;
}

----------------------------------------

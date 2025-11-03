data segment
msg1 db 0ah, 0dh, "Enter how many numbers (max 10): $"
msg2 db 0ah, 0dh, "Enter numbers(press enter after each number): $"
msg3 db 0ah, 0dh, "Sorted array: $"
n db ?
arr db 10 dup(?)
data ends

code segment
assume cs:code, ds:data
start: 
mov ax, data
mov ds, ax

lea dx, msg1
mov ah, 09h
int 21h


read_n:
	mov ah, 01h
	int 21h
	cmp al, 0dh
	je read_n
	sub al, 30h
	mov n, al
	
lea dx, msg2
mov ah, 09h
int 21h

mov cl, n
mov si, 0

read_loop:
read_element:
	mov ah, 01h
	int 21h
	cmp al, 0dh 
	je read_element
	sub al, 30h
	mov arr[si], al
	inc si
	loop read_loop

mov cl, n
dec cl
outer_loop:
	mov si, 0
	mov dl, cl
	inner_loop:
		mov al, arr[si]
		mov bl, arr[si+1]
		cmp al, bl
		jbe no_swap
		mov arr[si], bl
		mov arr[si+1], al
		
		no_swap:
			inc si
			dec dl
			jnz inner_loop
			dec cl
			jnz outer_loop

lea dx, msg3
mov ah, 09h
int 21h

mov cl, n
mov si, 0

display:
	mov dl, arr[si]
	add dl,30h
	mov ah, 02h
	int 21h
	mov dl, ' '
	int 21h
	inc si
	
	loop display

mov ah, 4ch
int 21h
code ends
end start

-----------------------------------

DATA SEGMENT
    MSG1 DB 10,13,'Enter number of elements (max 10): $'
    MSG2 DB 10,13,'Enter each element (press ENTER after each): $'
    MSG3 DB 10,13,'Sorted elements are: $'
    N DB ?
    ARR DB 10 DUP(?)
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA

START:
    MOV AX, DATA
    MOV DS, AX

    ; Ask for number of elements
    LEA DX, MSG1
    MOV AH, 09h
    INT 21H

READ_N:
    MOV AH, 1
    INT 21H
    CMP AL, 0dh
    JE READ_N
    SUB AL, 30H
    MOV N, AL

    ; Ask for array elements
    LEA DX, MSG2
    MOV AH, 09h
    INT 21H

    MOV CL, N
    MOV SI, 0
READ_LOOP:
READ_ELEMENT:
    MOV AH, 01h
    INT 21H
    CMP AL, 0dh
    JE READ_ELEMENT
    SUB AL, 30H
    MOV ARR[SI], AL
    INC SI
    LOOP READ_LOOP

    ; Bubble Sort
    MOV CL, N
    DEC CL
OUTER_LOOP:
    MOV SI, 0
    MOV DL, CL
INNER_LOOP:
    MOV AL, ARR[SI]
    MOV BL, ARR[SI+1]
    CMP AL, BL
    JBE NO_SWAP
    MOV ARR[SI], BL
    MOV ARR[SI+1], AL
NO_SWAP:
    INC SI
    DEC DL
    JNZ INNER_LOOP
    DEC CL
    JNZ OUTER_LOOP

    ; Display sorted array
    LEA DX, MSG3
    MOV AH, 9
    INT 21H

    MOV CL, N
    MOV SI, 0
DISPLAY_LOOP:
    MOV DL, ARR[SI]
    ADD DL, 30H
    MOV AH, 2
    INT 21H
    MOV DL, ' '
    INT 21H
    INC SI
    LOOP DISPLAY_LOOP

    MOV AH, 4CH
    INT 21H

CODE ENDS
END START

--------------------------




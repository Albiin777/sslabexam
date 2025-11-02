data segment
msg1 db 13,10,"Enter first number: $"
msg2 db 13,10,"Enter second number: $"
msg3 db 13,10,"Result: $"

n1 db 4 dup(?)
n2 db 4 dup(?)
data ends


code segment

assume cs: code, ds: data

start:
mov ax, data
mov ds, ax

lea dx, msg1
mov ah,09h
int 21h

mov si, offset n1
mov di, offset n2

mov cl, 04h

first: 
mov ah, 01h
int 21h
sub al, 30h
mov [si], al
inc si
dec cl
jnz first

lea dx, msg2
mov ah, 09h
int 21h

mov cl, 04h

second: 
mov ah, 01h
int 21h
sub al, 30h
mov [di], al
inc di
dec cl
jnz second



clc
mov cl, 04h

addition:
dec si
dec di
mov al,[si]
mov bl,[di]
adc al, bl
aaa
mov [di], al
dec cl
jnz addition

lea dx, msg3
mov ah, 09h
int 21h

mov dl, 30h
adc dl, 0
cmp dl, 30h
je skip
mov ah, 02h
int 21h

skip:
mov cl,04h
mov ah,02h


print:
mov dl, [di]
add dl,30h
int 21h
inc di
dec cl
jnz print

mov ah,4ch
int 21h

code ends
end start



-------------------------------------------------
data segment
msg1 db 13,10,"Enter first number: $"
msg2 db 13,10,"Enter second number: $"
msg3 db 13,10,"Result: $"
n1 db 4 dup(?)
n2 db 4 dup(?)
data ends

code segment
assume cs:code, ds:data
start:
    mov ax, data
    mov ds, ax

    lea dx, msg1
    mov ah, 09h
    int 21h

    mov si, offset n1
    mov cl, 4
first:
    mov ah, 01h
    int 21h
    sub al, 30h
    mov [si], al
    inc si
    dec cl
    jnz first

    lea dx, msg2
    mov ah, 09h
    int 21h

    mov di, offset n2
    mov cl, 4
second:
    mov ah, 01h
    int 21h
    sub al, 30h
    mov [di], al
    inc di
    dec cl
    jnz second

    clc
    mov cl, 4
addition:
    dec si
    dec di
    mov al, [si]
    mov bl, [di]
    adc al, bl
    aaa
    mov [di], al
    dec cl
    jnz addition

    lea dx, msg3
    mov ah, 09h
    int 21h

    mov dl, 30h
    adc dl, 0
    cmp dl, 30h
    je skip
    mov ah, 02h
    int 21h

skip:
    mov cl, 4
    mov ah, 02h
print:
    mov dl, [di]
    add dl, 30h
    int 21h
    inc di
    dec cl
    jnz print

    mov ah, 4Ch
    int 21h
code ends
end start
------------------------------

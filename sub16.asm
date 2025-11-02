data segment
msg1 db 0ah,0dh,"Enter first 4-digit number: $"
msg2 db 0ah,0dh,"Enter second 4-digit number: $"
msg3 db 0ah,0dh,"The result is: $"
sign db 0
n1 db 4 dup(?)
n2 db 4 dup(?)
res db 4 dup(?)
data ends

code segment
assume cs:code, ds:data

start:
    mov ax, data
    mov ds, ax

mov si, offset n1
mov di, offset n2

mov cl, 04h

lea dx, msg1
mov ah, 09h
int 21h
first:
	mov ah, 01h
	int 21h
	sub al, 30h
	mov [si], al
	inc si
	dec cl
	jnz first

mov cl, 04h

lea dx, msg2
mov ah, 09h
int 21h
second:
	mov ah, 01h
	int 21h
	sub al, 30h
	mov [di], al
	inc di
	dec cl
	jnz second

lea si, n1
lea di, n2
mov cl, 04h

compd:
mov al,[si]
cmp al, [di]
jne decide
inc si
inc di
loop compd
jmp subtract

decide:
jb nega
jmp subtract

nega:
mov sign, 1
lea si, n1
lea di, n2
mov cl, 04h

swap:
mov al, [si]
xchg al, [di]
mov [si], al
inc si
inc di
loop swap

subtract:
lea si, n1+3
lea di, n2+3
lea bx, res+3

mov cl, 04h
clc

sloop:
mov al, [si]
sbb al, [di]
jc fix
jmp store

fix:
add al, 10
stc

store:
mov [bx], al
dec si
dec di
dec bx
loop sloop

lea dx, msg3
mov ah,09h
int 21h
cmp sign, 1
jne show
mov dl, '-'
mov ah,02h
int 21h

show:
lea bx, res
mov cl, 04h

disp:
mov dl,[bx]
add dl,30h
mov ah,02h
int 21h
inc bx
loop disp

mov ah,4ch
int 21h

code ends
end start

------------------------------------------
data segment
msg1 db 0ah,0dh,"Enter first 4-digit number: $"
msg2 db 0ah,0dh,"Enter second 4-digit number: $"
msg3 db 0ah,0dh,"The result is: $"
sign db 0
n1 db 4 dup(?)
n2 db 4 dup(?)
res db 4 dup(?)
data ends

code segment
assume cs:code, ds:data

start:
    mov ax, data
    mov ds, ax

; ===== Input first number =====
    lea dx, msg1
    mov ah, 09h
    int 21h
    lea si, n1
    mov cl, 4
r1: mov ah, 01h
    int 21h
    sub al,30h
    mov [si],al
    inc si
    loop r1

; ===== Input second number =====
    lea dx, msg2
    mov ah,9
    int 21h
    lea si, n2
    mov cl,4
r2: mov ah,1
    int 21h
    sub al,30h
    mov [si],al
    inc si
    loop r2

; ===== Compare numbers to set sign =====
    lea si,n1
    lea di,n2
    mov cl,4
cmpd: mov al,[si]
      cmp al,[di]
      jne decide
      inc si
      inc di
      loop cmpd
      jmp subtract
decide:
      jb neg
      jmp subtract

; ===== If n1<n2 → swap & mark negative =====
neg:  mov sign, 1
      lea si, n1
      lea di, n2
      mov cl, 4
swap: mov al, [si]
      xchg al, [di]
      mov [si], al
      inc si
      inc di
      loop swap 

; ===== Subtraction =====
subtract:
    lea si, n1+3
    lea di, n2+3
    lea bx, res+3
    mov cl, 4
    clc
sloop:
    mov al, [si]
    sbb al, [di]
    jc fix
    jmp store
fix: add al,10
     stc
store:
    mov [bx], al
    dec si
    dec di
    dec bx
    loop sloop

; ===== Display result =====
    lea dx, msg3
    mov ah,9
    int 21h
    cmp sign,1
    jne show
    mov dl,'-'
    mov ah,2
    int 21h
show:
    lea bx,res
    mov cl,4
disp: mov dl,[bx]
      add dl,30h
      mov ah,2
      int 21h
      inc bx
      loop disp

    mov ah,4Ch
    int 21h

code ends
end start

---------------------------------



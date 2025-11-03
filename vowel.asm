data segment
msg1 db 0ah,0dh, "Enter the String: $"
msg2 db 0ah,0dh, "Number of Vowels: $"
count dw 0
data ends

code segment
Assume cs:code, ds:data

start :
	mov ax,data
	mov ds,ax

	lea dx,msg1
	mov ah,09h
	int 21h

mov count, 0

input_loop:
	mov ah,01h
	int 21h
	cmp al,0dh
	je done_input
cmp al,'A'
je inc_count

cmp al,'E'
je inc_count

cmp al,'I'
je inc_count

cmp al,'O'
je inc_count

cmp al,'U'
je inc_count

cmp al,'a'
je inc_count

cmp al,'e'
je inc_count

cmp al,'i'
je inc_count

cmp al,'o'
je inc_count

cmp al,'u'
je inc_count

jmp read_char

inc_count :
inc count

read_char:
jmp input_loop

done_input:
lea dx,msg2
mov ah,09h
int 21h

mov ax,count
add al,30h
mov dl,al
mov ah,02h
int 21h

mov ah,4ch
int 21h
code ends
end start

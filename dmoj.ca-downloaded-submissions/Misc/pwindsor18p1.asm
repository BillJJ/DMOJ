section .text
global _start

; int readint()
; byte _read_buf()

; void printint(int num) --> edi
; void newline()
; void printspace()
; void write_out(char *buf, int count) --> rdi, esi
; void _write_buf(char *buf, int count) --> rdi, esi
; void flush_obuf()

; rax caller-save function return value
; rbx callee-save
; rcx caller-save arg4
; rdx caller-save arg3
; rsi caller-save arg2
; rdi caller-save arg1
; r8  caller-save arg5
; r9  caller-save arg6
; r10 caller-save
; r11 caller-save
; r12 callee-save
; r13 callee-save
; r14 callee-save
; r15 callee-save


_start:
    push rbp                    ; save base pointer
    mov rbp, rsp                ; place base pointer on stack
    
    ; change 16 bytes to however many bytes you need to allocate
    sub rsp, 16                 ; align stack to keep 16 bytes for buffering
    
    ; your code here
    xor eax, eax
    xor edi, edi
    lea rsi, [rel input_buf]
    mov rdx, 8192
    syscall
    xor ebx, ebx ; buf_start
    sub eax, 4 ; buf_end-4
    lea rsi, [rel input_buf]
    jmp lc
l:
    cmp dword[rsi+rbx], 0x6176616a
    je found
    inc ebx
lc:
    cmp ebx, eax
    jl l
    lea edi, [eax+3]
    call printint
end:
    call flush_obuf             ; flush output buffer very important
    mov eax, 60                 ; rax = 60 for sys_exit
    xor edi, edi                ; exit code = 0
    syscall
found:
    mov edi, ebx
    call printint
    jmp end

printint:
    push rbp
    mov rbp, rsp
    sub rsp, 20
    cmp edi, 0
    je _printint_zero
    mov qword [rsp+8], 0
    mov dword [rsp+16], 0
    mov r8, rsp
    add r8, 20
    cmp edi, 0
    jmp _printint_loop_cond
_printint_loop:
    mov edx, edi
    movsxd rax, edx
    imul rax, rax, 1717986919
    shr rax, 34
    mov ecx, edx
    shr ecx, 31
    sub eax, ecx
    mov edi, eax
    shl eax, 2
    add eax, edi
    add eax, eax
    sub edx, eax
    add dl, 48
    mov byte [r8], dl
    dec r8
_printint_loop_cond:
    cmp edi, 0
    jne _printint_loop
_printint_done:
    lea rsi, [rsp+20]
    lea rdi, [r8+1]
    sub rsi, r8
    call _write_buf
    mov rsp, rbp
    pop rbp
    ret
_printint_zero:
    mov byte [rsp+2], 48
    mov rsi, 1
    lea rdi, [rsp+2]
    call _write_buf
    mov rsp, rbp
    pop rbp
    ret
_write_buf:
    push rbp
    mov rbp, rsp
    sub rsp, 8
    mov ecx, dword [rel obuf_start]
    add ecx, esi
    mov r8, rdi
    xor r9d, r9d
    mov r9d, esi
    cmp ecx, 8192
    jl _write_buf_l2_init
    call flush_obuf
_write_buf_l2_init:
    xor ecx, ecx
    lea rax, [rel output_buf]
    xor r11d, r11d
    mov r11d, dword [rel obuf_start]
    add rax, r11
    jmp _write_buf_l2_cond
_write_buf_l2:
    mov r11b, byte [r8]
    mov byte [rax], r11b
    inc ecx
    inc rax
    inc r8
_write_buf_l2_cond:
    cmp ecx, r9d
    jne _write_buf_l2
_write_buf_done:
    add dword [obuf_start], r9d
    mov rsp, rbp
    pop rbp
    ret
flush_obuf:
    mov rax, 1
    mov rdi, 1
    lea rsi, [rel output_buf]
    xor edx, edx
    mov edx, dword [rel obuf_start]
    syscall
    mov dword [rel obuf_start], 0
    ret


section .bss
input_buf:     resb 8192
output_buf:    resb 8192

section .data
ibuf_start:    dd 8192
ibuf_end:      dd 8192
obuf_start:    dd 0
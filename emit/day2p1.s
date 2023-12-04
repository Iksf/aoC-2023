part_1:
  push r15
  push r14
  xor r14d, r14d
  push r13
  push r12
  push rbp
  push rbx
  mov rbx, rdi
  sub rsp, 56
  lea r12, [rsp+28]
  lea r13, [rsp+31]
.L2:
  mov esi, 58
  mov rdi, rbx
  call strchr
  xor ecx, ecx
  xor esi, esi
  mov r8, rax
  lea rdx, [rax+2]
  mov QWORD PTR [rsp+36], rcx
  mov DWORD PTR [rsp+44], esi
.L3:
  mov rdi, rdx
  mov esi, 32
  mov QWORD PTR [rsp+8], r8
  mov QWORD PTR [rsp], rdx
  mov WORD PTR [r12], 0
  mov BYTE PTR [r12+2], 0
  call strchr
  mov rdx, QWORD PTR [rsp]
  mov rdi, r12
  mov rcx, rax
  mov r15, rax
  sub rcx, rdx
  mov rsi, rdx
  rep movsb
  mov rdi, r12
  call atoi
  mov dl, BYTE PTR [r15+1]
  mov r8, QWORD PTR [rsp+8]
  cmp dl, 103
  je .L4
  cmp dl, 114
  je .L5
  cmp dl, 98
  je .L6
  jmp .L7
.L5:
  cmp DWORD PTR [rsp+36], eax
  jge .L8
  mov DWORD PTR [rsp+36], eax
.L8:
  lea rbp, [r15+4]
  jmp .L7
.L4:
  cmp DWORD PTR [rsp+40], eax
  jge .L9
  mov DWORD PTR [rsp+40], eax
.L9:
  lea rbp, [r15+6]
  jmp .L7
.L6:
  cmp DWORD PTR [rsp+44], eax
  jge .L10
  mov DWORD PTR [rsp+44], eax
.L10:
  lea rbp, [r15+5]
.L7:
  mov r15b, BYTE PTR [rbp+0]
  cmp r15b, 10
  je .L11
  jg .L12
  xor r15d, r15d
.L11:
  cmp DWORD PTR [rsp+36], 12
  jg .L13
  cmp DWORD PTR [rsp+40], 13
  jg .L13
  cmp DWORD PTR [rsp+44], 14
  jg .L13
  lea rsi, [rbx+5]
  xor eax, eax
  mov BYTE PTR [r13+4], 0
  mov rdi, r13
  sub r8, rsi
  mov DWORD PTR [r13+0], eax
  lea rcx, [r8+2]
  rep movsb
  mov rdi, r13
  call atoi
  cdqe
  add r14, rax
.L13:
  test r15b, r15b
  je .L1
  cmp BYTE PTR [rbp+1], 0
  je .L1
  lea rbx, [rbp+1]
  jmp .L2
.L12:
  lea rdx, [rbp+2]
  jmp .L3
.L1:
  add rsp, 56
  mov rax, r14
  pop rbx
  pop rbp
  pop r12
  pop r13
  pop r14
  pop r15
  ret

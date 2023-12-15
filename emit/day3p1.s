part_1:
  push r14
  push r13
  push r12
  mov r12, rdi
  push rbp
  push rbx
  mov rbp, rsi
  mov esi, 10
  sub rsp, 16
  xor r14d, r14d
  mov rbx, r12
  call strchr
  mov QWORD PTR [rsp+8], 0
  sub rax, r12
  mov r13, rax
  cmp r12, rbp
  jb .L56
  jmp .L1
.L59:
  inc rbx
.L56:
  movzx eax, BYTE PTR [rbx]
  sub eax, 48
  cmp al, 9
  jbe .L58
  cmp rbx, rbp
  jb .L59
.L1:
  add rsp, 16
  mov rax, r14
  pop rbx
  pop rbp
  pop r12
  pop r13
  pop r14
  ret
.L58:
  mov rdi, rbx
  lea rsi, [rsp+8]
  mov edx, 10
  call strtol
  mov rdi, QWORD PTR [rsp+8]
  mov r8, rax
  mov rax, rbx
  sub rax, r13
  sub rax, 2
  mov rcx, rdi
  sub rcx, r13
  cmp r12, rax
  jnb .L6
  cmp rax, rcx
  je .L6
  movabs rsi, -288019269919179778
.L10:
  movzx edx, BYTE PTR [rax]
  cmp dl, 57
  jbe .L60
.L18:
  add r14, r8
  cmp rdi, rbp
  jnb .L1
.L22:
  mov rbx, rdi
  jmp .L56
.L60:
  bt rsi, rdx
  jc .L18
  inc rax
  cmp rax, rcx
  je .L6
  cmp r12, rax
  jb .L10
.L6:
  lea rax, [rbx+r13]
  lea rcx, [rdi+2+r13]
  cmp rax, rbp
  jnb .L12
  cmp rax, rcx
  je .L12
  movabs rsi, -288019269919179778
  jmp .L15
.L61:
  cmp rax, rcx
  je .L12
.L15:
  movzx edx, BYTE PTR [rax]
  cmp dl, 57
  ja .L18
  bt rsi, rdx
  jc .L18
  inc rax
  cmp rax, rbp
  jb .L61
.L12:
  cmp rbx, r12
  jb .L17
  movzx eax, BYTE PTR [rbx-1]
  cmp al, 57
  ja .L18
  movabs rdx, -288019269919179778
  bt rdx, rax
  jc .L18
.L17:
  cmp rdi, rbp
  jnb .L1
  movzx eax, BYTE PTR [rdi]
  cmp al, 57
  ja .L19
  movabs rdx, -288019269919179778
  bt rdx, rax
  jnc .L22
.L19:
  add r14, r8
  jmp .L22

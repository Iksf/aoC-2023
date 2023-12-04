.LC2:
  .string "(one|two|three|four|five|six|seven|eight|nine)"
part_2:
  push rbp
  mov ecx, 38
  xor eax, eax
  mov rbp, rsp
  push r15
  push r14
  push r13
  push r12
  push rbx
  mov rbx, rdi
  sub rsp, 232
  vmovdqa ymm0, YMMWORD PTR .LC0[rip]
  vmovdqa ymm1, YMMWORD PTR .LC1[rip]
  lea rdi, [rsp+182]
  lea r12, [rsp+128]
  rep stosb
  lea r15, [rsp+182]
  mov r13, r12
  vmovdqu YMMWORD PTR [rsp+128], ymm0
  vmovdqu YMMWORD PTR [rsp+150], ymm1
.L2:
  mov rdi, r12
  add r12, 6
  add r13, 4
  call strlen
  mov DWORD PTR [r13+52], eax
  cmp r12, r15
  jne .L2
  lea rdi, [rsp+36]
  mov ecx, 23
  lea rsi, [rsp+128]
  mov edx, 1
  rep movsd
  mov esi, OFFSET FLAT:.LC2
  lea rdi, [rsp+128]
  mov r13, rbx
  call regcomp
  test eax, eax
  je .L3
  mov edi, 1
  call exit
.L3:
  xor r8d, r8d
  lea rcx, [rsp+20]
  mov edx, 2
  mov rsi, r13
  lea rdi, [rsp+128]
  call regexec
  mov r8d, DWORD PTR [rsp+32]
  mov r9d, DWORD PTR [rsp+28]
  mov DWORD PTR [rsp+12], eax
  test r8d, r8d
  je .L4
  sub r8d, r9d
  movsx r15, r9d
  xor r14d, r14d
  movsx rax, r8d
  lea r12, [r13+0+r15]
  mov QWORD PTR [rsp], rax
.L6:
  cmp DWORD PTR [rsp+92+r14*4], r8d
  jl .L5
  imul rdi, r14, 6
  lea rax, [rsp+36]
  mov rdx, QWORD PTR [rsp]
  mov rsi, r12
  mov DWORD PTR [rsp+8], r8d
  add rdi, rax
  call memcmp
  mov r8d, DWORD PTR [rsp+8]
  test eax, eax
  jne .L5
  lea ecx, [r14+49]
  lea r13, [rbx+r15]
  mov BYTE PTR [r12], cl
  jmp .L4
.L5:
  inc r14
  cmp r14, 9
  jne .L6
.L4:
  cmp DWORD PTR [rsp+12], 1
  jne .L3
  mov rdi, rbx
  call part_1
  add rsp, 232
  pop rbx
  pop r12
  pop r13
  pop r14
  pop r15
  pop rbp
  ret
.LC0:
  .quad 8607504787818507887
  .quad 7310019992601231471
  .quad 125848705695845
  .quad 7598416998006417766
.LC1:
  .quad 111559248838656
  .quad 7310186620160338291
  .quad 7523097585065551222
  .quad 111524889624692

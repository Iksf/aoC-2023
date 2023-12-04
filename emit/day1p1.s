part_1:
  xor r8d, r8d
  xor ecx, ecx
.L11:
  mov rsi, rcx
.L3:
  mov r9b, BYTE PTR [rdi+rsi]
  mov r10, rsi
  inc rsi
  cmp r9b, 10
  je .L12
  test r9b, r9b
  jne .L3
.L12:
  mov rdx, r10
.L2:
  cmp rcx, rdx
  jg .L15
  mov al, BYTE PTR [rdi+rdx]
  sub eax, 48
  cmp al, 9
  ja .L4
  movsx rax, al
  jmp .L7
.L4:
  dec rdx
  jmp .L2
.L15:
  xor eax, eax
  jmp .L7
.L8:
  inc rcx
.L7:
  cmp r10, rcx
  jle .L9
  mov dl, BYTE PTR [rdi+rcx]
  sub edx, 48
  cmp dl, 9
  ja .L8
  movsx rdx, dl
  imul rdx, rdx, 10
  add rax, rdx
.L9:
  add r8, rax
  test r9b, r9b
  je .L16
  mov rcx, rsi
  jmp .L11
.L16:
  xchg r8, rax
  ret

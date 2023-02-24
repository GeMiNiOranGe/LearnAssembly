# Gia su
# $s0 --> count
# $s1 --> i
# $s2 --> so bi chia = 2

.data
Index:  .asciiz "So thu "
SoLe:   .asciiz " la so le\n"
SoChan: .asciiz " la so chan\n"

.text
.globl main
main:

# Nhap count
    addi    $v0,    $zero,  5
    syscall 

# Gan $s0 = count, $s1 = 0 va $s2 = 2
    add     $s0,    $zero,  $v0
    addi    $s1,    $zero,  0
    addi    $s2,    $zero,  2

Loop:
    slt     $t0,    $s1,    $s0
    beq     $t0,    $zero,  EndFor

    div     $s1,    $s2
    mfhi    $t1
    beq     $t1,    $zero,  Chan

# In so le
    addi    $v0,    $zero,  4
    la      $a0,    Index
    syscall 

    addi    $v0,    $zero,  1
    add     $v0,    $zero,  $s1
    syscall 

    addi    $v0,    $zero,  4
    la      $a0,    SoLe
    syscall 

    j       EndIf

# In so chan
Chan:
    addi    $v0,    $0,     4       # system call #4 - print string
    la      $a0,    Index
    syscall                         # execute

    addi    $v0,    $0,     1       # system call #1 - print int
    add     $a0,    $0,     $s1
    syscall                         # execute

    addi    $v0,    $0,     4       # system call #4 - print string
    la      $a0,    SoChan
    syscall                         # execute

EndIf:
    addi    $s1,    $s1,    1
    j       Loop

EndFor:

# Ket thuc chuong trinh
    addi    $v0,    $0,     10      # System call 10 - Exit
    syscall                         # execute
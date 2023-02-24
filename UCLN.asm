# Gia su
# a --> $s0
# b --> $s1

.data
nhapA:  .asciiz "Nhap a: "
nhapB:  .asciiz "Nhap b: "
xuat:   .asciiz "UCLN la: "

.text
.globl main
main:

# Nhap vao a
    addi    $v0,    $0,     4           # system call #4 - print string
    la      $a0,    nhapA
    syscall                             # execute

    addi    $v0,    $0,     5           # system call #5 - input int
    syscall                             # execute

# Gan $s0 = a
    add     $s0,    $0,     $v0         # $s0 = $0 + $v0

# Nhap vao b
    addi    $v0,    $0,     4           # system call #4 - print string
    la      $a0,    nhapB
    syscall                             # execute

    addi    $v0,    $0,     5           # system call #5 - input int
    syscall                             # execute

# Gan $s1 = b
    add     $s1,    $0,     $v0         # $s1 = $0 + $v0

# Vong lap tim UCLN
Loop:

# Dieu kien dung
    beq     $s0,    $s1,    EndLoop     # if $s0 == $s1 then goto EndLoop

    slt     $t0,    $s0,    $s1         # $t0 = ($s0 < $s1) ? 1 : 0
    bne     $t0,    $0,     A           # if $t0 != $0 then goto A

# 2 lenh else duoi la tuong duong nhau
    beq     $t0,    $0,     B           # if $t0 == $0 then goto B
    j       B                           # if $t0 == $0 then goto B
A:
    sub     $s1,    $s1,    $s0         # $s1 = $s1 - $s0
    j       EndIf                       # jump to EndIf
B:
    sub     $s0,    $s0,    $s1         # $s0 = $s0 - $s1
    j       EndIf                       # jump to EndIf
EndIf:
    j       Loop                        # jump to Loop
EndLoop:

# Xuat
    addi    $v0,    $0,     4           # system call #4 - print string
    la      $a0,    xuat
    syscall                             # execute

    addi    $v0,    $0,     1           # system call #1 - print int
    add     $a0,    $0,     $s0
    syscall                             # execute

# Ket thuc chuong trinh
    addi    $v0,    $0,     10          # System call 10 - Exit
    syscall                             # execute

.data
UCLN:    .asciiz    "UCLN la: "
.text
.globl main
main:
addi    $v0,    $0,     5
syscall
add     $s0,    $0,     $v0
addi    $v0,    $0,     5
syscall
add     $s1,    $0,     $v0
Loop:
beq     $s0,    $s1,    End
slt     $t0,    $s0,    $s1
bne     $t0,    $0,     B
sub     $s0,    $s0,    $s1
j       Loop
B:
sub     $s1,    $s1,    $s0
j       Loop
End:
addi    $v0,    $0,     4
la      $a0,    UCLN
syscall
addi    $v0,    $0,     1
add     $a0,    $0,     $s0
syscall


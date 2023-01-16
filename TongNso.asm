# Gia su
# Size --> $s0
# i    --> $s1
# Sum  --> $s2

.data
nhap:   .asciiz "Nhap so n: "
xuat:   .asciiz "Tong cua chuoi so: "

.text
.globl main
main:

# nhap n
    addi    $v0,    $0,     4           # system call #4 - print string
    la      $a0,    nhap
    syscall                             # execute
    
    addi    $v0,    $0,     5           # system call #5 - input int
    syscall                             # execute

# gan $s0 = n va gan $s1 = 1
    add     $s0,    $v0,    $0          # $s0 = $0 + $v0
    addi    $s1,    $0,     1           # $s1 = $0 + 1

# lap tu 1 den n
Loop:
    slt     $t0,    $s0,    $s1         # $t0 = ($s0 < $s1) ? 1 : 0
    bne     $t0,    $0,     EndLoop     # if $t0 != $0 then goto EndLoop
    add     $s2,    $s2,    $s1         # $s2 = $s2 + $s1
    addi    $s1,    $s1,    1           # $s1 = $s1 + 1
    j       Loop
EndLoop:

# xuat tong
    addi    $v0,    $0,     4           # system call #4 - print string
    la      $a0,    xuat
    syscall                             # execute

    addi    $v0,    $0,     1           # system call #1 - print int
    add     $a0,    $0,     $s2
    syscall                             # execute

    addi    $v0,    $0,     10          # System call 10 - Exit
    syscall                             # execute
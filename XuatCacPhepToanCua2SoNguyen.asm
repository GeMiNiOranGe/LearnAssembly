# Viet chuong trinh tinh tong, hieu, tich, thuong
# Gia su
# a -------> $s0
# b -------> $s1
# tong ----> $s2
# hieu ----> $s3
# tich ----> $s4
# thuong --> $s5

.data
nhap:		.asciiz "Nhap vao 2 so nguyen:\n"
xuatCong:	.asciiz "\nKet qua phep cong: "
xuatTru:	.asciiz "\nKet qua phep tru: "
xuatNhan:	.asciiz "\nKet qua phep nhan: "
xuatChia:	.asciiz "\nKet qua phep chia: "

.text
.globl main
main:
    addi    $v0,    $0,         4       # system call #4 - print string
    la      $a0,    nhap
    syscall                             # execute

# Nhap so nguyen thu 1
    addi    $v0,    $0,         5       # system call #5 - input int
    syscall                             # execute
    add     $s0,    $0,         $v0     # $s0 = $0 + $v0

# Nhap so nguyen thu 2
    addi    $v0,    $0,         5       # system call #5 - input int
    syscall                             # execute
    add     $s1,    $0,         $v0     # $s1 = $0 + $v0

# Thuc hien cac phep toan
    add     $s2,    $s0,        $s1     # $s2 = $s0 + $s1
    sub     $s3,    $s0,        $s1     # $s3 = $s0 - $s1
    mult    $s0,    $s1                 # $s0 * $s1 = Hi and Lo registers
    mflo    $s4                         # copy Lo to $s4
    div     $s0,    $s1                 # $s0 / $s1
    mflo    $s5                         # $s5 = floor($s0 / $s1)

# Xuat ket qua cac phep toan
# <Phep cong>
    addi    $v0,    $0,         4       # system call #4 - print string
    la      $a0,    xuatCong
    syscall                             # execute
    addi    $v0,    $0,         1       # system call #1 - print int
    add     $a0,    $0,         $s2
    syscall                             # execute

# <Phep tru>
    addi    $v0,    $0,         4       # system call #4 - print string
    la      $a0,    xuatTru
    syscall                             # execute
    addi    $v0,    $0,         1       # system call #1 - print int
    add     $a0,    $0,         $s3
    syscall                             # execute

# <Phep nhan>
    addi    $v0,    $0,         4       # system call #4 - print string
    la      $a0,    xuatNhan
    syscall                             # execute
    addi    $v0,    $0,         1       # system call #1 - print int
    add     $a0,    $0,         $s4
    syscall                             # execute

# <Phep chia>
    addi    $v0,    $0,         4       # system call #4 - print string
    la      $a0,    xuatChia
    syscall                             # execute
    addi    $v0,    $0,         1       # system call #1 - print int
    add     $a0,    $0,         $s5
    syscall                             # execute

# Ket thuc chuong trinh
    addi    $v0,    $0,         10      # System call 10 - Exit
    syscall                             # execute
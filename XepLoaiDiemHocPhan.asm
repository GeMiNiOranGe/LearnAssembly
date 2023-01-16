.data
in:             .asciiz "Nhap diem: "
out:            .asciiz "Hoc sinh loai: "
loaiYeu:        .asciiz "Yeu"
loaiTrungBinh:  .asciiz "Trung binh"
loaiKha:        .asciiz "Kha"
loaiGioi:       .asciiz "Gioi"
loaiXuatSac:    .asciiz "Xuat sac"
error:          .asciiz "Khong hop le"

.text
.globl main
main:

# input
    addi    $v0,    $0,             4           # system call #4 - print string
    la      $a0,    in
    syscall                                     # execute
    addi    $v0,    $0,             5           # system call #5 - input int
    syscall                                     # execute

# $s0 = input number
    add     $s0,    $v0,            $0          # $s0 = $v0 + $0

# prepare to execute output
    addi    $v0,    $0,             4           # system call #4 - print string

# check error input number below 0
    slti    $t0,    $s0,            0           # $t0 = ($s0 < 0) ? 1 : 0
    bne     $t0,    $0,             ErrorInput  # if $t0 != $0 then goto ErrorInput

# check error input number above 10
    slti    $t0,    $s0,            11          # $t0 = ($s0 < 11) ? 1 : 0
    beq     $t0,    $0,             ErrorInput  # if $t0 == $0 then goto ErrorInput

# handle input
    la      $a0,    out
    syscall                                     # execute
    slti    $t0,    $s0,            5           # $t0 = ($s0 < 5) ? 1 : 0
    bne     $t0,    $0,             Yeu         # if $t0 != $0 then goto yeu
    slti    $t0,    $s0,            7           # $t0 = ($s0 < 7) ? 1 : 0
    bne     $t0,    $0,             TrungBinh   # if $t0 != $0 then goto TrungBinh
    slti    $t0,    $s0,            9           # $t0 = ($s0 < 9) ? 1 : 0
    bne     $t0,    $0,             Kha         # if $t0 != $0 then goto Kha
    slti    $t0,    $s0,            10          # $t0 = ($s0 < 10) ? 1 : 0
    bne     $t0,    $0,             Gioi        # if $t0 != $0 then goto Gioi
    slti    $t0,    $s0,            11          # $t0 = ($s0 < 11) ? 1 : 0
    bne     $t0,    $0,             XuatSac     # if $t0 != $0 then goto XuatSac

# output
Yeu:
    la      $a0,    loaiYeu
    j       Exit                                # jump to Exit
TrungBinh:
    la      $a0,    loaiTrungBinh
    j       Exit                                # jump to Exit
Kha:
    la      $a0,    loaiKha
    j       Exit                                # jump to Exit
Gioi:
    la      $a0,    loaiGioi
    j       Exit                                # jump to Exit
XuatSac:
    la      $a0,    loaiXuatSac
    j       Exit                                # jump to Exit
ErrorInput:
    la      $a0,    error
    j       Exit                                # jump to Exit
Exit:
    syscall                                     # execute output above
    addi    $v0,    $0,             10          # System call 10 - Exit
    syscall                                     # execute
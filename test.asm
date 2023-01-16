bne     $t0,    $0,     MainIf

# Your code #
j       EndIf
MainIf:

# Your code #
EndIf:
slti	$t0, $s0, 0			# $t0 = ($s0 < 0) ? 1 : 0
move		$a0, $t0			# $a0 = $t0
li			$v0, 1				# syscall print int
syscall							# execute
add $d, $s, $t ; $d = $s + $t
blt		$t0, $t1, target	# if $t0 < $t1 then goto target
mfhi $d ; $d =  hi

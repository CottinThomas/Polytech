
.text

main:
	lh $t0, A
	lh $t1, B
	move $t2, $t1
	slt $t4, $t0, $t1
	bgtz $t4, next
	move $t2, $t0
	next:
	sb $t2, C

	jr $ra

.data
A : .half 10
B : .half 15
C : .half 0


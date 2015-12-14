
.text

main:
	la $t0, X
	
	add $t1, $zero, $zero
	sw $t1, 0($t0)
	
	addi $t2, $zero, 1
	sw $t2, 4($t0)
	
	addi $t3, $t2, $t1
	sw $t2, 8($t3)

	addi $t4, $t3, $t2
	sw $t2, 12($t3)

	jr $ra

.data
X : .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

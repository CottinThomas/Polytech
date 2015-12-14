.text

main:
    # Chargement + écriture de A et B
    li $t1, 10
    sw $t1, A
    li $t2, 15
    sw $t2, B
    # Préparation appel fonction
    move $t7, $ra

    jal fmax

    move $ra, $t7
    sw $t3, C
    jr $ra


fmax:
    move $t3, $t1
    slt $t0, $t2, $t1
    bgtz $t0, next
        move $t3, $t2
    next:
    jr $ra

.data
A : .word 0x11111111
B : .word 0x22222222
C : .word 0x33333333

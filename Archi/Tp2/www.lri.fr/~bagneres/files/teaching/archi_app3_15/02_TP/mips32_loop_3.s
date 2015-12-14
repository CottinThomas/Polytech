.text

main:
    # Chargement de l'adresse de X dans $t6
    la $t6, X
    addiu $t6, $t6, 4
    # Chargement de l'adresse de Y dans $t7
    la $t7, Y
    addiu $t7, $t7, 4
    # Chargement de l'adresse de fin de X dans $t8
    addiu $t8, $t6, 24
    # Boucle
    loop:
        # $t1 = X[i]
        # $t2 = X[i-1]
        # $t3 = Y[i-1]
        lw $t1, 0($t6)
        lw $t2, -4($t6)
        lw $t3, -4($t7)
        # $t3 += $t1 + $t2
        add $t3, $t3, $t1
        add $t3, $t3, $t2
        # Écriture de $t3 dans Y[i-1]
        sw $t3, -4($t7)
        # Calcul des adresses de X[i] et de Y[i] suivantes
        addiu $t6, $t6, 4 
        addiu $t7, $t7, 4
        # Condition pour boucler
        bne $t6, $t8, loop
    jr $ra

.data
# X
X :
.word 0x00000001, 0x00000002, 0x00000003, 0x00000005
.word 0x00000008, 0x0000000D, 0x00000015, 0x00000022
# Y
Y :
.word 0x10000000, 0x20000000, 0x30000000, 0x40000000
.word 0x50000000, 0x60000000, 0x7fffffff, 0x8fffffff

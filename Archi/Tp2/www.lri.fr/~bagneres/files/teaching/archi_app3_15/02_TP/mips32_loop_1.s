.text

main:
    # Chargement de l'adresse de X dans $t6
    la $t6, X
    # Chargement de l'adresse de Y dans $t7
    #la $t7, Y # possible de supprimer t7 car deux tableaux contigues en memoire
    # Chargement de l'adresse de fin de X dans $t8
    addiu $t8, $t6, 32
    # s = 0 ($t3 = 0)

    move $t7, $ra
    
    jal floop

    move $ra, $t7
    jr $ra

floop:
    move $t3, $zero
    # Boucle
    loop:
        # $t1 = X[i]
        lw $t1, 0($t6)
        # $t2 = Y[i]
        lw $t2, 32($t6)
        # $t3 += $t1 + $t2
        add $t3, $t3, $t1
        add $t3, $t3, $t2
        # Calcul des adresses de X[i] et de Y[i] suivantes
        addiu $t6, $t6, 4 # sizeof(int) = 4
        #addiu $t7, $t7, 4
        # Condition pour boucler
        bne $t6, $t8, loop
    # Écriture de $t3 dans s
    sw $t3, S 


    jr $ra

.data
# X
X :.word 0x00000001, 0x00000010, 0x00000100, 0x00001000
.word 0x00010000, 0x00100000, 0x01000000, 0x10000000
# Y
Y : .word 0x00000002, 0x00000020, 0x00000200, 0x00002000
.word 0x00020000, 0x00200000, 0x02000000, 0x20000000
# s
S : .word 0xffffffff

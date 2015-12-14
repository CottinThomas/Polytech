.text

main:
    # Chargement + écriture de A et B
    li $t1, 10
    sw $t1, A
    li $t2, 15
    sw $t2, B
    # Préparation appel fonction
    sw $ra, 0($sp) # sauvegarde du point de sortie
    sw $t1, 4($sp) # sauvegarde de A
    sw $t2, 8($sp) # sauvegarde de B

    # appel de fonction (donc $ra modifié pour retour après)
    jal fmax

    # retours de fonction
    lw $ra, 0($sp) # réstauration du point de sortie
    lw $t3, 12($sp) # réstauration du max
    sw $t3, C # sauvegarde du max

    jr $ra # sortie du programme


    # TODO
    # fmax
fmax:
    lw $t1, 4($sp) # récupération de A
    lw $t2, 8($sp) # récupération de B
    # détermination du max BEGIN
    move $t3, $t1 
    slt $t0, $t2, $t1
    bgtz $t0, next
        move $t3, $t2
    next:
    # détermination du max END
    sw $t3, 12($sp) # sauvegarde du max
    # retours main
    jr $ra

.data
A : .word 0x11111111
B : .word 0x22222222
C : .word 0x33333333

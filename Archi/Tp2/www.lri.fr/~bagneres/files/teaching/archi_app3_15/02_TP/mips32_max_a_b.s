.text

main:
    # Calcul de l'adresse mémoire de A dans $t7
    # TODO
    # Chargement de A et B dans $t1 et $t2
    # TODO
    # max($t1, $t2) dans $t3
    # TODO
    # Écriture de $t3 dans C
    # TODO
    lui $t0, 0x1001
    addiu $t0, $t0, 0x20
    lb $t1, 0($t7)
    lb $t2, 1($t7)
    addiu $t2, $t2, 0x0001
    move $t3, $t1
    slt $t4, $t2, $t1
    bgtz $t4, next
    	move $t3, $t2
    next:
    sb $t3, 2($t7)
    jr $ra

.data
.word 0x00001111, 0x22223333, 0x44445555, 0x66667777
.word 0x88889999, 0xAAAABBBB, 0xCCCCDDDD, 0xEEEEFFFF
# A
#.ascii "2"
# B
#.ascii "9"
# C
#.ascii "0"

.data
.word 0x00001111, 0x22223333, 0x44445555, 0x66667777
.word 0x88889999, 0xAAAABBBB, 0xCCCCDDDD, 0xEEEEFFFF
# A
.ascii "2"
# B
.ascii "9"
# C
.ascii "0"

# 2 : 10010000
# 9 : 10010001

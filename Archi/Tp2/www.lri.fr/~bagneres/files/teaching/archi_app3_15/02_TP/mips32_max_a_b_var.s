.text

main:
    # Chargement de A et B dans $t1 et $t2
    # TODO
    # max($t1, $t2) dans $t3
    # TODO
    # Écriture de $t3 dans C
    # TODO
    lb $t1, A
    lb $t2, B
    move $t3, $t1
    slt $t4, $t2, $t1
    bgtz $t4, next
    	move $t3, $t2
    next:
    sb $t3, C
    jr $ra

.data
A : .ascii "9"
B : .ascii "2"

#.data
#A : .ascii "9"
#B : .ascii "2"

C : .ascii "0"

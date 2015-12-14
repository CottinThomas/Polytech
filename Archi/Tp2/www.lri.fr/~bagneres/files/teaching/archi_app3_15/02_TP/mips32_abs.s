.text

main:
    # Chargement d'un entier positif ou négatif
    #li $t1, 0xA0000000 # Entier négatif
    li $t1, 0x0A000000 # Entier positif

    # Branchement si la valeur est supérieur à zéro  (on ne fait pas le a = -a)
    bgez $t1, next
    	sub $t1, $zero, $t1
	next:

    # Calcul de la valeur absolue
    # TODO

    jr $ra

.data

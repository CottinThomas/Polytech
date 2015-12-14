.text

main:
    # Chargement + écriture
    la $t8, V
    li $t1, 0x1A
    sb $t1, 0($t8)
    li $t1, 0x19
    sb $t1, 1($t8)
    li $t1, 0x18
    sb $t1, 2($t8)
    li $t1, 0x17
    sb $t1, 3($t8)
    li $t1, 0x16
    sb $t1, 4($t8)
    li $t1, 0x15
    sb $t1, 5($t8)
    li $t1, 0x14
    sb $t1, 6($t8)
    li $t1, 0x13
    sb $t1, 7($t8)
    li $t1, 0x12
    sb $t1, 8($t8)
    li $t1, 0x11
    sb $t1, 9($t8)
    # Préparation tri
    # TODO
    # tri
    # TODO
    # Restauration après tri
    # TODO
    # End
    jr $ra

tri:
    # Addresse de fin pour v[i]
    # TODO
    # Addresse de v[i + 1]
    # TODO
    loopi:
        # Addresse de v[i]
        # TODO
        # v[i]
        # TODO
        # Addresse de fin pour v[j]
        # TODO
        # Addresse de v[j + 1]
        # TODO
        loopj:
            # Addresse de v[j]
            # TODO
            # v[j]
            # TODO
            # if (v[j] < v[i])
            # TODO
            # loopj
            # TODO
        # loopi
        # TODO
    jr $ra

change:
    # TODO
    jr $ra

.data
V : .byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff

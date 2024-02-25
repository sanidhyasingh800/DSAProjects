.pos 0x1000
code:
            ld $a, r0       # r0 = address of a 
            ld 0(r0), r1    # r1 = a
            ld $b, r2
            ld 0(r1), r3
            mov r1, r4
            not r4
            inc r4          # r4 = -a
            beq r4, skiploop
            bgt r4, skiploop
start:      inc r3
            dec r1
            st r1, 0(r0)
            st r3, 0(r2)
            bgt r1, start
skiploop:   halt

        




.pos 0x2000
static:
a:      .long 10 #a
b:      .long 0 #b
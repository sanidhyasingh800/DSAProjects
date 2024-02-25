.pos 0x1000
code:
        ld $a, r0       # r0 = address of a 
        ld 0(r0), r0    # r0 = a
        ld $b, r1
        ld 0(r1), r2
        dec r0          # r0 = a-1
        beq r0, if
        dec r2          # else clause
        st r2, 0(r1)    # else clause
        br skipif
if:     inc r2          # if clause
        st r2, 0(r1)    # if clause 
skipif: halt




.pos 0x2000
static:
a:      .long 0 #a
b:      .long 5 #b
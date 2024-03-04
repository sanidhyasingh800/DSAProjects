.pos 0x1000
code: 
main:   gpc $6, r6         
        j changeB
        ld $a, r0       #  r0 = address of a
        ld 0(r0), r1    # r1 = a
        inc r1          # a++
        st r1, 0(r0)    # a = a++
        halt


changeB: ld $b, r0
         ld $5, r1
         st r1, 0(r0)
         j 0(r6)



.pos 0x2000
static:
a:  .long 10
b:  .long 0

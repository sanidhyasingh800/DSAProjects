.pos 0x1000
code:
            ld $a, r0       # r0 = address of a 
            ld $b, r1       # r1 = address of b
            ld 0(r1), r2    # r2 = b
            ld $i, r3       # r3 = address of i
            ld 0(r3), r3    # r3 = i
            ld $-5, r4      # r4 = -5
            add r3, r4      # r4 = i-5
loop:       beq r4, end_loop # end loop if i-5 = 0 or i=5
            ld (r0, r3, 4), r5
            ld $1, r6
            and r6, r5
            bgt r5, skip_if
if:         inc r2
skip_if:    inc r3          # i++
            inc r4          # r4++ 
            br loop
end_loop:   st r2, 0(r1)
            ld $i, r7
            st r3, 0(r7)                  
            halt



        




.pos 0x2000
static:
a:      .long 1  #a[0]
        .long 2  #a[1]
        .long 3  #a[2]
        .long 4  #a[3]
        .long 5  #a[4]
b:      .long 0  #b
i:      .long 0  #i
.pos 0x100
code:
                ld $a, r0
                ld $0, r1
                st r1, 0(r0)
                ld $a, r0
                ld 0(r0), r0        # r0 = a = 0
                ld $arrlength, r1
                ld 0(r1), r1        # r1 = arrlength
                mov r0, r2
                not r1
                inc r1
                add r2, r1         # r1 = condition checker 
                ld $arr, r3
                ld 0(r3), r3
loop:           bgt r1, end_loop
                beq r1, end_loop
                ld (r3, r0, 4), r2
                ld $1, r4
                and r2, r4          # r4 = arr[a] & 1 (1 if odd)
                beq r4, next_cond
                br else
next_cond:      ld $-10, r5
                add r2, r5
                bgt r5, if
else:           bgt r4, inside_if
                ld $-5, r5
                add r2, r5
                not r5
                inc r5
                beq r5, inside_if
                bgt r5, inside_if
                br endif2
inside_if:      ld $c, r6
                ld 0(r6), r7
                inc r7
                st r7, 0(r6)
endif2:         br endif
if:             ld $b, r7
                ld 0(r7), r6
                inc r6
                st r6, 0(r7)           
endif:          inc r0
                inc r1
                br loop
end_loop:       ld $a, r7
                st r0, 0(r7)
                halt      



.pos 0x2000
static:
a:          .long 0
b:          .long 0
c:          .long 0
arr:        .long a_array
arrlength:  .long 5

.pos 0x3000
heap:
a_array: .long 12
         .long 2
         .long 3
         .long 4
         .long 5
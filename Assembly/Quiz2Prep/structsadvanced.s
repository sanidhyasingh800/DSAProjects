.pos 0x100
code:
            ld $0, r0       # r0 = i = 0 (serve as itercount)
            ld $b, r1       # r1 = address of b
            ld 0(r1), r1    # r1 = b_struct 
            ld 4(r1), r1    # r1 = b->num
            mov r0, r2
            not r1
            inc r1
            add r1, r2      # r2 = i-b->num (serve as condition)
loop:       bgt r2, end_loop
            beq r2, end_loop
            ld $b, r1
            ld 0(r1), r1    # r1 = b_struct 
            ld 0(r1), r1    # r1 = b->ptr
            mov r0, r3
            shl $4, r3
            add r3, r1
            ld 8(r1), r5
            bgt r5, if
            br endif
if:         ld 0(r1), r6
            st r5, 0(r6)
endif:      inc r0
            inc r2
            br loop
end_loop:   halt



.pos 0x2000
static:
a:      .long 0             # a.x
        .long 0             # a.ptr
        .long 0             # a.y
        .long 0             # a.z
b:      .long b_struct             # b


.pos 0x3000
heap:
b_struct:   .long a_array   # b->ptr
            .long 1         # b->num
a_array:    .long int_ptr             # a.x
            .long 0             # a.ptr
            .long 10             # a.y
            .long 0             # a.z
int_ptr:    .long 0
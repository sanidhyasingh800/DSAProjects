.pos 0x100
code:
        ld $num, r0         # r0 = address of num
        ld 0(r0), r0        # r0 = num
        bgt r0, if
else:   not r0
        inc r0
        br endif
if:     nop
endif:  ld $b, r1
        st r0, 0(r1)
        halt

.pos 0x2000
static:
b:      .long 0     # b->a
num:    .long -10     # num
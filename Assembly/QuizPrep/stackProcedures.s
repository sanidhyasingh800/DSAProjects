.pos 0x100
code: 
start: ld $stackBottom, r5
        inca r5
        gpc $6, r6
        j main 
        halt
main:   deca r5             # main prologue (allocate space for ra)
        st r6, 0(r5)        # main prologue (save ra)
        gpc $6, r6          # caller prologue (save ra into r6)
        j foo               # function call
        ld 0(r5), r6        # main epilogue
        inca r5             # main epilogue
        j 0(r6)             # main epilogue
foo:    deca r5
        st r6, 0(r5)
        ld $0, r0
        ld $1, r1
        deca r5
        deca r5
        st r0, 0(r5)
        st r1, 4(r5)
        gpc $6, r6
        j b
        inca r5
        inca r5
        ld 0(r5), r6
        inca r5
        j 0(r6)

b:      deca r5
        st r6, 0(r5)
        deca r5
        deca r5
        ld 12(r5), r3
        st r3, 0(r5)
        ld 16(r5), r3
        st r3, 4(r5)
        inca r5
        inca r5
        ld 0(r5), r6
        inca r5
        j 0(r6)





.pos 0x1000
stackTop:    .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
            .long 0x0
stackBottom: .long 0x0

.pos 0x2000
static:

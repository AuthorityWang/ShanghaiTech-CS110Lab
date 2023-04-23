## Part 1: Vector addition
run:

    gcc part1.c -o part1
    ./part1

- _mm_loadu_si128(__m128i const* mem_addr)
#### Description
Load 128-bits of integer data from unaligned memory into dst. This intrinsic may perform better than _mm_loadu_si128 when the data crosses a cache line boundary.
#### Operation
    dst[127:0] := MEM[mem_addr+127:mem_addr]

- _mm_storeu_si128(__m128i* mem_addr, __m128i a)
#### Description
Store 128-bits of integer data from a into memory. mem_addr does not need to be aligned on any particular boundary.
#### Operation
    MEM[mem_addr+127:mem_addr] := a[127:0]

- _mm_add_epi32(__m128i a, __m128i b)
#### Description
Add packed 32-bit integers in a and b, and store the results in dst.
#### Operation
    FOR j := 0 to 3
	   i := j*32
	   dst[i+31:i] := a[i+31:i] + b[i+31:i]
    ENDFOR

- _mm_load_si128
  Load 128-bits of integer data from memory into dst. mem_addr **must be aligned** on a 16-byte boundary or a general-protection exception may be generated.
- _mm_loadu_si128
  Load 128-bits of integer data from memory into dst. mem_addr **does not need to be aligned** on any particular boundary.
- _mm_load_pd
   #### Description
   Load 128-bits (composed of 2 packed double-precision (64-bit) floating-point elements) from memory into dst. mem_addr must be aligned on a 16-byte boundary or a general-protection exception may be generated.
   #### Operation
      dst[127:0] := MEM[mem_addr+127:mem_addr]
- _mm_load1_pd
   #### Description
   Load a double-precision (64-bit) floating-point element from memory into both elements of dst.
   #### Operation
      dst[63:0] := MEM[mem_addr+63:mem_addr]
      dst[127:64] := MEM[mem_addr+63:mem_addr]
## Part 2: Matrix multiplication
run:

    gcc part2_3.c -o part2
    ./part2

$$C_{n,p} = A_{n,4} * B_{4,p}$$

## Part 3: Loop unrolling

## Part 4: Compiler optimization


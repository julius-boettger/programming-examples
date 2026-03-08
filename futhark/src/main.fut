-- compile with `futhark [COMPILER] src/main.fut -o target/main`
-- interesting compilers include:
-- - c (sequential)
-- - multicore (in C)
-- - opencl (called from C)
-- - ispc (for usage with the CPU SIMD compiler)

def main: i32 = 42

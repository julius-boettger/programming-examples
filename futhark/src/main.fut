-- compile with `futhark [COMPILER] src/main.fut -o target/main`
-- then run compiled binary `target/main`
-- interesting compilers include:
-- cpu:
-- - c (sequential)
-- - multicore (in C)
-- - ispc (for usage with the CPU SIMD compiler)
-- gpgpu:
-- - opencl (called from C)
-- - cuda (called from C)
-- - hip (AMD's CUDA, called from C)

def main: i32 = 42

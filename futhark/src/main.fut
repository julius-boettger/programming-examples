-- compile with `futhark [COMPILER] src/main.fut -o target/main`
-- then run compiled binary `target/main`, entering arguments (if any)
-- interactively, or read them from stdin like `echo 123 | target/main`.

-- interesting compilers include:
-- cpu:
-- - c (sequential)
-- - multicore (in C)
-- - ispc (for usage with the CPU SIMD compiler)
-- gpu:
-- - opencl (called from C)
-- - cuda (called from C)
-- - hip (AMD's CUDA, called from C)

-- although it looks somewhat similar to haskell,
-- futhark is eagerly evaluated, not lazily

-- constants (are also functions!)
def const_1 = 123_u8 -- values can be suffixed with a type (underscore optional)
def const_2: i16 = 1 -- optionally annotate the constants type
-- primitive types are:
-- - signed integers: i8 - i64
-- - unsigned integers: u8 - u64
-- - floats: f32 - f64
-- - bool (true/false)

-- converting between primitive values: <TO>.<FROM>, e.g.
def converted = i32.f32 2.123
-- shorthands for common conversions:
-- "real"
-- r32 == f32.i32
-- r64 == f64.i32
-- "truncate"
-- t32 == i32.f32
-- t64 == i64.f32

-- tuple
def tuple: (bool, u8) = (true, 0)
def empty_tuple: () = ()

-- array (size can be elided)
def array: [3]u8 = [255, 255, 255]
-- array slicing like in python
def sliced_array: [2]u8 = array[0:2:1]

-- range notation for convenient arrays
def range_1: []i8 = 1...3 -- [1, 2, 3]
def range_2: []i8 = 1..<3 -- [1, 2]
def range_3: []i8 = 1..3...7 -- [1, 3, 5, 7]
def range_4: []i8 = 1..3..<7 -- [1, 3, 5]

-- branch (if-then-else)
def branch = if true then const_2 else -const_2

-- a function defintion
-- with pattern matching for the tuple argument
-- and the let-in syntax for local variables
def pack_rgb ((r, g, b): (u8, u8, u8)): u32 =
    let r = (u32.u8 r) << 16
    let g = (u32.u8 g) << 8
    let b = (u32.u8 b)
    in r + g + b

-- the default entry point (overridable with cli arguments)
def main = array

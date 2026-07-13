println("hello world")

# insert unicode chars lean-like using e.g. \pi[ENTER]
# (type is optional)
π::Integer = 3

# primitive types
char::Char = '0'
bool::Bool = true
int8::Int8 = 0 # up to 128
int::Int = 0 # size depends on system arch (probably  64)
uint8::UInt8 = 0 # up to 128
uint::UInt = 0 # size depends on system arch (probably  64)
float16::Float16 = 0.0 # up to 64

# abstract types (different sizes allowed)
any::Any = 1
signed::Signed = 1
integer::Integer = 1
float::AbstractFloat = 1.0

# dynamic typing
# only allowed for variables with no explicit type
x = false
@assert typeof(x) == Bool
x = "hello"
@assert typeof(x) == String

# a complex number
1 + 1im

# chaining comparisons
@assert 1 < 3 > 2

# exact rational numbers
rational = 6//9 # auto reduces to 2//3
@assert rational == 2//3
@assert numerator(rational) == 2
@assert denominator(rational) == 3

# cool operators
@assert √9 == 3 # \sqrt
@assert 2^8 == 256 # power
@assert 7 ÷ 3 == 2 # integer division (\div)
# interesting bitwise operator syntax
0 ⊻ 0 # \xor
0 ⊽ 0 # \nor
0 ⊼ 0 # \nand
# two kinds of right-shifts (only differ for signed integers) 
@assert bitstring(Int8(-8) >>  1) == "11111100"
@assert bitstring(Int8(-8) >>> 1) == "01111100"

### strings
# interpolation
@assert "$x world" == "hello world"
@assert "-> $(1 + 1)" == "-> 2"
# regex pattern strings
@assert typeof(r"^.*$") == Regex 
# version number strings
@assert typeof(v"0.2") == VersionNumber 

### arrays
array = [1, 2, 3]
# range notation
@assert 1:3 == [1, 2, 3]
# indexing starts at 1
@assert array[1] == 1
# dot operations (pointwise)
@assert array .* 2 == [2, 4, 6]
# range indexing (includes last element!)
@assert "hello"[2:end] == "ello"

array2 = [1, 2, 3] # same value
# value equality ==: true, same value
@assert array == array2
# object equality ===: false, different object in memory
@assert array !== array2
# true (same object)
@assert array === array

# a tuple
tuple = (1, 2, 3)
@assert tuple[1] == 1

# destructuring arrays
a, b..., c = 1:5
@assert a == 1
@assert b == [2, 3, 4]
@assert c == 5

# insert unicode chars lean-like using e.g. \pi[ENTER]
π = 3

# dynamic typing
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
# indexing starts at 1
@assert array[1] == 1
# dot operations (pointwise)
@assert array .* 2 == [2, 4, 6]
# range indexing
@assert "hello"[2:end] == "ello"

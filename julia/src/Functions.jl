# simple function
"small doc comment (uses _markdown_)"
function sum(a, b)
    # return last expression by default
    a + b # could also use `return`
end
@assert sum(1, 2) == 3

# provide a concrete implementation
# for specific argument types
# (a "method" for "multiple dispatch")
function sum(a::Float32, b::Float32)::Float32
    a + b
end
@assert sum(1.0, 2.0) == 3.0

# "assignment form"
shortsum(a, b) = a + b
@assert shortsum(1, 2) == 3

# anonymous functions
@assert ((a, b) -> a + b)(1, 2) == 3

"""
multi-line doc comment
"""
function printhello()
    println("hello")
    # convention for functions with no return value
    # could also use just `return` or just `nothing`
    return nothing
end

# reassigning arguments does not modify the originals
function modtest(num, array)
    num += 1
    num = 2
    array = [0]
end
num = 3
array = [1, 2, 3]
modtest(num, array)
@assert num == 3
@assert array == [1, 2, 3]

# convention: "mutating" function's names ends on "!"
zerofirst!(array) = array[1] = 0
zerofirst!(array)
@assert array[1] == 0

# unnamed arguments: useful with multiple dispatch
isinteger(::Any) = false
isinteger(::Integer) = true
@assert !isinteger(".")
@assert isinteger(0)

# optional argument (with defaults)
optional(num=1) = num
@assert optional() == 1
@assert optional(2) == 2

# operators are also functions
@assert 1 + 2 == +(1, 2)
# function composition with \circ
# careful: this is right-to-left (first add, then square)
@assert (sqrt ∘ +)(3, 6) == 3

# function piping/chaining
@assert (9 |> sqrt) == 3
# pipe with broadcasting (pointwise dot syntax) 
@assert ([9, 64, 100] .|> sqrt) == [3, 8, 10]

# map with anonymous function in a few different ways
# standard
@assert map(x -> x*2, 1:3) == [2, 4, 6]
# a block with begin+end for multi-line functions
@assert map(x -> begin x*2 end, 1:3) == [2, 4, 6]
# different syntax for multi-line functions
@assert map(1:3) do x x*2 end == [2, 4, 6]
# pointwise application
@assert (x -> x*2).(1:3) == [2, 4, 6]
# with pipes
@assert 1:3 |> (x -> x*2) == [2, 4, 6]

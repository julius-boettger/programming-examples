# a simple struct
# objects are immutable by default
struct Struct
    # types are optional
    field1::Int
    field2::Bool
    # default constructor definition
    #Struct(field1, field2) = new(field1, field2)
end

# use default constructor
object = Struct(0, true)
@assert object.field1 == 0
# not allowed: struct is immutable
#object.field1 = 1

# add constructor without arguments
Struct() = Struct(0, false)
defaultObj = Struct()
@assert defaultObj.field2 == false

# a mutable struct (objects are mutable)
mutable struct mutableStruct
    field::Int
    # can still annotate fields to be const (immutable)
    const constField
end
mutableObj = mutableStruct(0, 0)
mutableObj.field = 1
@assert mutableObj.field == 1

# with a parametric type
struct Parametric{T}
    x::T
    y::T
end
parametric = Parametric{Int}(1, 1)
@assert typeof(parametric.x) == Int

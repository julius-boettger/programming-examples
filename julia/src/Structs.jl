# a simple struct
# objects are immutable by default
struct Struct
    # types are optional
    field1::Int
    field2::Bool
end

object = Struct(0, true)
@assert object.field1 == 0
# not allowed: struct is immutable
#object.field1 = 1

# a mutable struct (objects are mutable)
mutable struct mutableStruct
    field::Int
    # can still annotate fields to be const (immutable)
    const constField
end
mutableObj = mutableStruct(0, 0)
mutableObj.field = 1
@assert mutableObj.field == 1

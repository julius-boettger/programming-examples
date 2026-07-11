# simple function
function sum(a, b)
    a + b
end
@assert sum(1, 2) == 3

# "assignment form"
shortSum(a, b) = a + b

# convention: function name ends on "!"
#             as it modifies an argument
zeroFirst!(array) = array[1] = 0
array = [1, 2, 3]
zeroFirst!(array)
@assert array[1] == 0

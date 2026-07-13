# explicitly override scope
global g = 1
local l = 1

# constants (use for globals if possible!)
const myConst = 0

# let blocks (new scope)
x = let a = 3, b = 4
    a + b
end
# equivalent
x = let
    a = 3
    b = 4
    a + b
end
@assert x == 7

# compound expressions (leaks into outer scope!)
# with begin blocks
x = begin
    a = 3
    b = 4
    a + b
end
@assert x == 7
@assert a == 3
# with ; chains
x = (c = 3; d = 4; c + d)
@assert x == 7
@assert c == 3

# variables leak into outer scope!
if true
    branch = 1
elseif false
    branch = 2
else
    branch = 3
end
@assert branch == 1

# ternary operator
@assert (true ? 1 : 2) == 1

# for loop 
for i = 1:9 # could also replace `=` with `in` or `∈`
    # ...
end

# while loop
while true
    break
    continue
end

# try-catch
try
    throw(InvalidStateException)
    error("something went very wrong")
catch #error
    # ...
else
    # do something on success
finally
    # do something either way
end

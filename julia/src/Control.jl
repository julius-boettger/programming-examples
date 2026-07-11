### compound expressions (with temporary variables)
# with begin blocks
x = begin
    a = 3
    b = 4
    a + b
end
@assert x == 7
# with ; chains
x = (a = 3; b = 4; a + b)
@assert x == 7

# if blocks do not introduce a new scope
# => variables defined inside are visible outside
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
for i in 1:9
    # ...
end

# while loop
while true
    break
    continue
end

# try-catch
try
    sqrt(-1)
catch #error
    # ...
else
    # do something on success
finally
    # do something either way
end

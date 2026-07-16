# a module, exporting a constant
module MyMod

# what to import with `using` (see below)
export myconst

const myconst = 0
const notexported = 1

end

# import the module (acess with its name)
import .MyMod
@assert MyMod.myconst == 0

# import everything in the module's export list
using .MyMod
@assert myconst == 0

# import just some specific names from the module
using .MyMod: notexported
@assert notexported == 1

# a module, exporting a constant
module MyMod

# what to import with `using` (see below)
export myConst

const myConst = 0
const notExported = 1

end

# import the module (acess with its name)
import .MyMod
@assert MyMod.myConst == 0

# import everything in the module's export list
using .MyMod
@assert myConst == 0

# import just some specific names from the module
using .MyMod: notExported
@assert notExported == 1

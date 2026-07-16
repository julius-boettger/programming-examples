# run this with `julia src/Main.jl`

# a main function is also not strictly necessary, but good practice
function (@main)(args)
    # in a real project, prefer to import code from other
    # files using modules, not like this (see Modules.jl)
    include("src/Basics.jl")
    include("src/Control.jl")
    include("src/Functions.jl")
    include("src/Modules.jl")
    include("src/Structs.jl")
end

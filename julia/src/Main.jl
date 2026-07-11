# run this with `julia src/Main.jl`

# a main function is not strictly necessary,
# its body could also just be at top-level,
# but good practice
function main()
    include("Basics.jl")
    include("Functions.jl")
end

# like `if __name == "__main__"` in python:
# only run this if the file is run directly (not e.g. included)
if abspath(PROGRAM_FILE) == @__FILE__
    main()
end

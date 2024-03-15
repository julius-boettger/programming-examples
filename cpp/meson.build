project('cpp-examples', 'CPP')
executable(
    'cpp-examples',
    include_directories: 'src/include',
    # g++ compiler arguments:
    cpp_args: [
        # throw errors when using compiler extensions (compiler-specific behavior)
        '-pedantic-errors',
        # more warnings
        '-Wall', '-Weffc++', '-Wextra', '-Wconversion', '-Wsign-conversion',
        # treat warnings as errors
        #'-Werror',
    ], sources: [
        'src/main.cpp',
        'src/examples/basics.cpp',
    ]
)
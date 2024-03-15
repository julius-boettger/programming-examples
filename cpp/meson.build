project('cpp-examples', 'CPP')
executable(
    'cpp-examples',
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
    ]
)
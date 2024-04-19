project('cpp-examples', 'cpp')
executable(
    'cpp-examples',
    include_directories: 'src/include',
    # g++ compiler arguments:
    cpp_args: [
        '-std=c++23',
        # throw errors when using compiler extensions (compiler-specific behavior)
        '-pedantic-errors',
        # more warnings
        '-Wall', '-Weffc++', '-Wextra', '-Wconversion', '-Wsign-conversion',
        # ignore some warnings
        '-Wno-unused-variable'
        # treat warnings as errors
        #'-Werror',
    ], sources: [
        'src/main.cpp',
        'src/examples/basics.cpp',
        'src/examples/functions.cpp',
    ]
)
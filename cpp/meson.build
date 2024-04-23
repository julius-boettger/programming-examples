project('cpp-examples', 'cpp')
executable(
    'cpp-examples',
    include_directories: 'src/include',
    # compiler arguments
    cpp_args: [
        '-std=c++23',
        # throw errors when using compiler extensions (compiler-specific behavior)
        '-pedantic-errors',
        # more warnings
        '-Wall', '-Weffc++', '-Wextra', '-Wconversion', '-Wsign-conversion', '-Wshadow',
        # ignore some warnings
        '-Wno-unused-variable', '-Wno-unused-local-typedefs',
    ], sources: [
        'src/main.cpp',
        'src/examples/basics.cpp',
        'src/examples/control.cpp',
        'src/examples/functions.cpp',
        'src/examples/namespaces.cpp',
        'src/examples/strings.cpp',
    ]
)
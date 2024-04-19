# minimal setup for meson with ninja, which is a popular build tool
# some commands:
# - generate build files (only once): meson setup build
# - build: meson compile -C build
# - run: ./build/c-examples
project('c-examples', 'c')
executable('c-examples',
    # search for header files here so include paths don't have to be relative
    include_directories: 'src/include',
    # compiler arguments
    c_args: [
        # more warnings
        '-Wall', '-Wextra', '-Wconversion', '-Wsign-conversion',
        # ignore some warnings (acceptable for these examples)
        '-Wno-unused-variable', '-Wno-unused-value', '-Wno-unused-but-set-variable', '-Wno-unused-function', '-Wno-unknown-pragmas', '-Wno-unused-parameter',
        # warn when using compiler extensions (compiler-specific behavior)
        #'-Wpedantic',
        # treat warnings as errors
        #'-Werror',
    ],
    # all source files that should be compiled need to be specified manually
    # order usually doesn't matter, but can in rare cases
    sources: [
        'src/main.c',
        'src/examples/enums.c',
        'src/examples/basics.c',
        'src/examples/unions.c',
        'src/examples/structs.c',
        'src/examples/control.c',
        'src/examples/functions.c',
        'src/examples/dyn_array.c',
        'src/examples/concurrency.c',
        'src/examples/preprocessor.c',
        'src/examples/mem_management.c',
    ]
)
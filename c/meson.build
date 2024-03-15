# minimal setup for meson with ninja, which is a popular build tool
# some commands:
# - generate build files (only once): meson setup build
# - build: meson compile -C build
# - run: ./build/c-examples
project('c-examples', 'C')
executable('c-examples',
    # search for header files here so include paths don't have to be relative
    include_directories: 'src/include',
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
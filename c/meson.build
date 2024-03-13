# minimal setup for meson with ninja, which is a popular build tool
# some commands:
# - generate build files (only once): meson setup build
# - build: meson compile -C build
# - run: ./build/c-examples
project('c-examples', 'C')
executable('c-examples', sources: [
    # all source files that should be compiled need to be specified manually
    # order usually doesn't matter, but can in rare cases
    'src/main.c',
    'src/examples/enums.c',
    'src/examples/basics.c',
    'src/examples/unions.c',
    'src/examples/structs.c',
    'src/examples/control.c',
    'src/examples/functions.c',
    'src/examples/dyn_array.c',
    'src/examples/unit_test.c',
    'src/examples/concurrency.c',
    'src/examples/preprocessor.c',
    'src/examples/mem_management.c',
], dependencies: [
    # optional: depend on Check (a unit testing tool)
    dependency('check', required: false)
])
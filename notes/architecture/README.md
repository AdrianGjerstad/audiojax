# Architecture

> February 4, 2021

This note document outlines the basic structure of this project, both in file system and in code.

## File System

An overview of the file system for this project, starting at the root directory for the repository is as shown below.

```
 *
 +-- audiojax
     +   BUILD
     +-- include
     +-- impl
 +-- test
     +   BUILD
 +-- examples
 `   WORKSPACE
```

### `audiojax`

This directory is the main source code directory for this project. It contains header files in `include`, implementation files in `impl`, and a Bazel `BUILD` file, indicating every object to compile.

Each class will have it's own header and source code files, and may also include other headers as dependencies, which **must** be marked as dependencies within the `BUILD` file.

The `include` directory contains every C++ header for AudioJAX, and may have subdirectories for smaller subsets of the library. Except for header files that only add simple `struct`s with no functionality inside, the subdirectories should be mirrored in the `impl` directory.

The `impl` directory contains every C++ implementation file (`.cc`) for this library. These implementation files will only exist for classes that require functionality. If you want to look at how something is implemented, or the exact math behind a specific calculation, the `impl` directory is for you.

### `test`

This directory is simple in its purpose. It contains a Bazel `BUILD` file, indicating each test binary to build, and a list of subdirectories with source files called `main.cc`, along with any assets it may require. In the future, there may also be a `shared_assets` directory to indicate assets that may be used for multiple tests.

Please note that all source files within this directory imply that your CWD is this directory, not its parent.

### `examples`

This directory is not meant to be built, but instead it is meant to be a list of working examples that show off any given feature of AudioJAX. These example files should be in their own directories inside of `examples`, along with any additional assets that may be required for the example to run correctly. Just like the `test` directory, this directory may also have a `shared_assets` subdirectory to indicate assets that are used by multiple examples.

As with the `test` directory, if you build these files as-is, your CWD must be this directory, and not its parent.

### `WORKSPACE`

This file doesn't serve much purpose other than for indicating the name of this workspace as well as just letting Bazel know where the workspace begins.

## Codebase

This section outlines the way this project's source code is layed out for use in other people's projects.

### Constants

Constants for various calculations such as Pi, Tau (2 * Pi), Panning constants, etc. will all be placed in the proper header files for their use. If such a file does not exist, or the constant may be needed elsewhere, it's definition must be placed inside `include/constants.h`.


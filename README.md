# Image Viewer

A simple image viewer for PPM (P3) files, built using C and the SDL2 library.

## How it Works

The program reads a PPM file, parses the header and pixel data, and then uses SDL2 to create a window and render the image pixel by pixel.

## Dependencies

- **GCC (GNU Compiler Collection)**: To compile the C code.
- **Make**: To automate the build process using the provided `Makefile`.
- **SDL2**: A cross-platform development library designed to provide low-level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D.

### Installing Dependencies

**On macOS (using Homebrew):**

```bash
brew install sdl2
```

**On Debian/Ubuntu-based Linux:**

```bash
sudo apt-get update
sudo apt-get install libsdl2-dev
```

## Building

1.  **Clone the repository:**
    ```bash
    git clone <repository-url>
    cd ImageViewer
    ```

2.  **Update Makefile (if necessary):**
    The provided `Makefile` includes paths that might be specific to a macOS environment with Homebrew (`/opt/homebrew/Cellar/sdl2/...`). If you installed SDL2 in a different location, you may need to update the `INCLUDE` and `LINK` variables in the `Makefile`.

3.  **Compile the code:**
    ```bash
    make
    ```
    This will create an executable file named `iv` in the project's root directory.

## Usage

To run the image viewer, use the following command:

```bash
./iv
```

This will open a window displaying the `bitcoin.ppm` image, which is included in the repository. The input filename is currently hardcoded in `src/iv.c`. To view a different PPM file, you will need to modify the `main` function in `src/iv.c`.

## Cleaning

To remove the compiled object files and the executable, run:

```bash
make clean
```

## Project Structure

```
.
├── Makefile          # Defines build rules and tasks.
├── bitcoin.ppm       # An example PPM image file.
├── include/
│   └── ppm_to_rgb.h  # Header file for the PPM parsing logic.
└── src/
    ├── iv.c          # Main application logic and SDL2 windowing.
    └── ppm_to_rgb.c  # Implementation for reading and parsing PPM files.
```
# Writing Startup script for Cortex M controllers in C++

A definitive guide to developing the entire embedded C++ project for ARM Cortexm-M micro-controllers. This projects ais to provide as deep insight into the development of startup script in c++.

## Project Working

This project configures SysTick timer and uses it to generate time accurate delay for blinking an LED. The onboard LED connected to pin C13 blinks every second.

## Dependencies

* **make**\
    Make utility is required for configuring and building this project. You can install make on linux by running command:

    ```bash
    sudo apt install build-essential
    ```

* **gcc-arm-none-eabi toolchain**\
    ARM cross-platform toolchain is required to build applications for arm mcus. Toolchain can be installed by running following command:

    ```bash
    sudo apt install gcc-arm-none-eabi
    ```

* **openocd**\
    It is an Open On Circuit Debugging tool used to flash and debug arm micro controllers. You can install openocd on linux by running command:

   ```bash
   sudo apt install openocd -y
   ```

* **st-link**\
This package is provided by STMicro-electronics for flashing the binary on the micro-controller

```bash
sudo apt install stlink
```

* **Cortex Debug extension**\
    This extension for VSCode is helpful for debugging the application on Blue Pill. The contents of registers as well as memory are visible in the context menu.
    Launch VS Code Quick Open (Ctrl+P), paste the following command, and press enter.

     ```bash
    ext install marus25.cortex-debug
    ```

## Project Structure

* `src` directory contains all source files for the project
* `include` directory contains all header files for the project

### Source file description

* `stm31f1.ld`  - linker script for STM32F103 MCU
* `src\main.cpp` - application code
* `src\startup_stm32f103.cpp` - startup script in cpp
* `include\gpio.hpp` - slibrary for handling gpio functions
* `system_stm32f1xx.c` - clock configuration and system initialization functions
* `STM32F103.svd` - contains the description of the system contained in Arm Cortex-M processor-based microcontrollers, in particular, the memory mapped registers of peripherals.

## Run Locally

Running the project is super easy. Just clone, build, and flash.

### Clone the project

1. Using https

    ```bash
    git clone https://github.com/csrohit/stm32-startup-cpp.git
    cd stm32-startup-cpp
    ```

2. Using ssh

    ```bash
    git clone git@github.com:csrohit/stm32-startup-cpp.git
    cd stm32-startup-cpp
    ```

## Configuration

All the configuration required for building this project is given below.

1. Build output directory
    In `Makefile`, output directory can be configured using variable `BUILD_DIR`.

2. Binary name
    In `Makefile`, the name of binary can be configured using variable `TARGET`.

3. MCU
    In `Makefile`, the target mcu can be selected by seting the following flags/variables
    * `MCU_FAMILY`: Specifies the family, it used to define a maco for inclusion of header files
    * `LD_SCRIPT`: Specifies path to linker script of the target controller
    * `INSTR_SET`: Specifies the instruction set to use. e.g. `thumb`, `arm`, etc
    * `FLOAT_ABI`: Specifies the floating point implementation
    * `CPU`: Specifies the processor on the MCU. e.g. `cortex-m3`, `cortex-m4`, etc

## Build

Run following command in terminal to generate flashable binaries for blue pill board. Build files will be written to **Build Output Directory** as configured.

```bash
make all
```

## Flash

1. Connect STlink to PC and blue pill board using swd headers.
2. Put blue pill board in programming mode.
3. Run following to flash board with binary.

```C
make flash
```

Output

Onboard led connected to Pin C13 can be observed to be blinking every second.

## Debug

1. Run the following make command to build the program using debugging flags

```bash
make debug
```

2. Flash the controller using following command

```bash
make flash
```

3. Click in Run and Debug option in VsCode sidebar. Then launch Cortex Debug target.

Happy debugging....

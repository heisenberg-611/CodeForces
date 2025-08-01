# Codeforces Solutions Repository

Welcome to my **Codeforces** problem-solving repository! This repo is designed as a centralized workspace for competitive programming practice, with a focus on Codeforces problems. It is optimized for efficient compilation, organization, and easy management of source and binary files using VS Code and the Competitive Programming Helper (CPH) extension.

---

## Repository Structure
```plaintext
├── bin/                    # Compiled binaries (executables) are stored here
├── root/                   # Main workspace where all source code files reside
├── .cph/                   # Configuration folder for Competitive Programming Helper (CPH) extension
├── .vscode/                # VS Code configuration files (tasks, launch, settings)
├── bin_mover_into_bin.py   # Python script to move executables from root to bin/
├── bin_mover_outof_bin.py  # Python script to move executables from bin/ back to root/
└── README.md               # This file
```

---

## Features & Workflow

- **Source files are kept in the root folder** to keep your workspace clean and manageable.
- **All compiled executables (.bin files) are stored in the `bin/` folder**, separating code from binaries.
- Use the provided Python scripts to quickly organize your compiled files:
  - `bin_mover_into_bin.py`: Move binaries from root to `bin/`.
  - `bin_mover_outof_bin.py`: Move binaries from `bin/` back to root.
- The repo is integrated with the **CPH (Competitive Programming Helper)** extension for VS Code:
  - Quickly add, compile, and run Codeforces problems.
  - Supports custom compiler and flags settings.
  - Configured to output binaries inside the `bin/` folder.
- VS Code `.vscode` folder contains task and debugging configurations optimized for C++23 and Clang/G++ compilers.
- Proper file associations are set for STL headers and competitive programming snippets to enable smooth IntelliSense and syntax highlighting.

---

## Setup Instructions

1. **Clone this repository** to your local machine.

2. **Ensure you have the CPH extension installed** in VS Code for easy problem management.

3. **Create the `bin/` folder if it does not exist:**

    ```bash
    mkdir -p bin
    ```

4. **Configure your VS Code settings** (usually auto-configured, but verify):

    ```json
    {
      "cph.compiler": "clang++",
      "cph.compileArgs": ["-std=c++23", "-O2", "-Wall"],
      "cph.outputDirectory": "bin"
    }
    ```

5. **Use the Python scripts to manage your binaries:**

    - Move compiled executables to `bin/`:

      ```bash
      python3 bin_mover_into_bin.py
      ```

    - Move executables back to root (if needed):

      ```bash
      python3 bin_mover_outof_bin.py
      ```

---

## How to Use

- Add new problem solutions as `.cpp` files inside the **root** folder.
- Compile and run using the CPH extension or VS Code build tasks.
- Use `bin_mover_into_bin.py` script after compiling to keep your root directory clean.
- Use `bin_mover_outof_bin.py` when you want to run binaries directly from the root for the past made binaries
- Use VS Code debugging and task configurations in `.vscode` for seamless development.

---

## Recommended Tools & Versions

- **VS Code** (latest stable)
- **CPH (Competitive Programming Helper)** VS Code extension
- **Clang++ or g++** with C++23 support (e.g., Clang 17 or GCC 14)
- **Python 3** for running management scripts

---

## Contribution & Customization

Feel free to fork and customize this repository according to your workflow preferences. Suggestions for improvements or issues can be submitted via pull requests.

---

## Contact

If you have any questions or want to collaborate, reach out to me on Codeforces or GitHub!

---

Happy Coding! 🚀

---
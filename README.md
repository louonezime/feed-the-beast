# strace 

This project is an attempt to replicate the functionality of `strace`, a diagnostic and debugging tool commonly used on Unix-like operating systems. 

## Overview

The goal of this project is to gain a deeper understanding of system calls, their role in operating systems, and how tools like `strace` intercept and log these calls. By building this replication, I aim to:

- Explore system call tracing.
- Understand the mechanics behind process monitoring.
- Learn more about the interactions between user-space applications and the kernel.

## How to Use

1. Clone the repository:
   ```bash
   git clone https://github.com/louonezime/feed-the-beast.git
   cd feed-the-beast
   ```

2. Build the project (e.g., using `make`):
   ```bash
   make
   ```

3. Run the tool with a target process:
   ```bash
   ./strace <target_command>
   ```
   

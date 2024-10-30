# Educational Keylogger Project

This project is an educational Python-based keylogger. **It should only be used in authorized environments, such as a controlled lab setup, for educational or ethical hacking purposes.** This script demonstrates the basics of logging keystrokes with additional features like timestamping and session management.

## Features
- Logs keystrokes to a file with timestamps
- Exits when the 'Esc' key is pressed
- Saves logs to a `keylogs` directory in `log.txt`

## Usage

1. **Installation**:
    - Make sure you have Python installed.
    - Install the required library using:
      ```bash
      pip install pynput
      ```

2. **Running the Script**:
    - Run the script using:
      ```bash
      python keylogger.py
      ```

3. **Stopping the Logger**:
    - Press the `Esc` key to stop logging.

> **Disclaimer**: This code is strictly for educational purposes and should only be used in environments where you have full authorization to capture keystrokes.

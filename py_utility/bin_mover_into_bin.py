import os
import shutil

def move_binaries_to_bin_folder():
    project_root = os.getcwd()
    bin_folder = os.path.join(project_root, 'bin')

    # Create bin/ folder if it doesn't exist
    if not os.path.exists(bin_folder):
        os.makedirs(bin_folder)

    # Get list of all files in the current directory
    for file in os.listdir(project_root):
        file_path = os.path.join(project_root, file)

        # Skip directories and non-executables
        if os.path.isdir(file_path):
            continue

        # On Unix (macOS/Linux), check if file is executable and not a source file
        if os.access(file_path, os.X_OK) and not file.endswith(('.cpp', '.c', '.py', '.txt', '.json')):
            print(f"Moving: {file} → bin/")
            shutil.move(file_path, os.path.join(bin_folder, file))

if __name__ == '__main__':
    move_binaries_to_bin_folder()
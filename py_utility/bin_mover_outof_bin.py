# import os
# import shutil

# def move_binaries_out_of_bin_folder():
#     project_root = os.getcwd()
#     bin_folder = os.path.join(project_root, 'bin')

#     # Check if bin folder exists
#     if not os.path.exists(bin_folder):
#         print("No 'bin/' folder found.")
#         return

#     # Move all files from bin/ back to root
#     for file in os.listdir(bin_folder):
#         source = os.path.join(bin_folder, file)
#         destination = os.path.join(project_root, file)

#         # Only move regular files
#         if os.path.isfile(source):
#             print(f"Moving: bin/{file} → {file}")
#             shutil.move(source, destination)

#     print("Done moving all files from bin/ to root.")

# if __name__ == '__main__':
#     move_binaries_out_of_bin_folder()
import os
import shutil
import re

# Natural sorting key (splits numbers and letters)
def natural_key(s):
    return [int(text) if text.isdigit() else text.lower() for text in re.split(r'([0-9]+)', s)]

# List and sort files naturally from the bin folder
def list_bin_files(bin_folder):
    files = [f for f in os.listdir(bin_folder) if os.path.isfile(os.path.join(bin_folder, f))]
    return sorted(files, key=natural_key)

# Move a single file
def move_file(source, destination):
    shutil.move(source, destination)
    print(f"Moved: {os.path.basename(source)} → {destination}")

# Main function
def move_binaries_out_of_bin_folder():
    project_root = os.getcwd()
    bin_folder = os.path.join(project_root, 'bin')

    # Check if bin/ folder exists
    if not os.path.exists(bin_folder):
        print("No 'bin/' folder found.")
        return

    files = list_bin_files(bin_folder)

    if not files:
        print("No files found in bin/ folder.")
        return

    # Display sorted file list
    print("\nAvailable files in bin/:")
    for idx, file in enumerate(files, start=1):
        print(f"{idx}. {file}")
    print(f"{len(files)+1}. Move ALL files")

    # User input
    try:
        choice = int(input("\nEnter the number of the file to move (or select last option to move all): "))
    except ValueError:
        print("Invalid input. Please enter a number.")
        return

    if 1 <= choice <= len(files):
        selected_file = files[choice - 1]
        source = os.path.join(bin_folder, selected_file)
        destination = os.path.join(project_root, selected_file)
        move_file(source, destination)
    elif choice == len(files) + 1:
        for file in files:
            source = os.path.join(bin_folder, file)
            destination = os.path.join(project_root, file)
            move_file(source, destination)
    else:
        print("Invalid choice.")

if __name__ == '__main__':
    move_binaries_out_of_bin_folder()

import os
import shutil

def move_binaries_out_of_bin_folder():
    project_root = os.getcwd()
    bin_folder = os.path.join(project_root, 'bin')

    # Check if bin folder exists
    if not os.path.exists(bin_folder):
        print("No 'bin/' folder found.")
        return

    # Move all files from bin/ back to root
    for file in os.listdir(bin_folder):
        source = os.path.join(bin_folder, file)
        destination = os.path.join(project_root, file)

        # Only move regular files
        if os.path.isfile(source):
            print(f"Moving: bin/{file} → {file}")
            shutil.move(source, destination)

    print("Done moving all files from bin/ to root.")

if __name__ == '__main__':
    move_binaries_out_of_bin_folder()

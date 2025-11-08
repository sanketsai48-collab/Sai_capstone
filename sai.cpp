#include <iostream>
#include <unistd.h>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;

void listFiles(const char* path) {
    DIR* dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return;
    }
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        cout << entry->d_name << endl;
    }
    closedir(dir);
}
void copyFile(string source, string destination) {
    ifstream src(source, ios::binary);
    ofstream dest(destination, ios::binary);
    if (!src) {
        cout << "Source file not found!\n";
        return;
    }
    dest << src.rdbuf();
    cout << "File copied successfully!\n";
}

void moveFile(string oldPath, string newPath) {
    if (rename(oldPath.c_str(), newPath.c_str()) == 0)
        cout << "File moved successfully!\n";
    else
        perror("Error moving file");
}

void deleteFile(string filename) {
    if (remove(filename.c_str()) == 0)
        cout << "File deleted successfully!\n";
    else
        perror("Error deleting file");
}

void createFile(string filename) {
    ofstream newFile(filename);
    if (newFile) {
        cout << "File created successfully!\n";
        newFile.close();
    } else {
        cout << "Error creating file!\n";
    }
}
void searchFile(const string &basePath, const string &target) {
    DIR *dir = opendir(basePath.c_str());
    if (!dir) return;

    struct dirent *entry;
    struct stat info;

    while ((entry = readdir(dir)) != NULL) {
        string name = entry->d_name;

        // Skip current and parent folders
        if (name == "." || name == "..")
            continue;

        string fullPath = basePath + "/" + name;

        // Check if it's a directory
        if (stat(fullPath.c_str(), &info) == -1) {
	    continue;
        }

        if (S_ISDIR(info.st_mode)) {
            // Recursive call to search inside subdirectories
            searchFile(fullPath, target);
        }

        // Check if file/folder name contains the target
        if (name.find(target) != string::npos) {
            cout << "Found: " << fullPath << endl;
        }
    }

    closedir(dir);
}
// Convert mode (st_mode) to rwxr-xr-x style string
string permissionString(mode_t mode) {
    string s;
    if (S_ISDIR(mode)) s += 'd'; else s += '-';

    s += (mode & S_IRUSR) ? 'r' : '-';
    s += (mode & S_IWUSR) ? 'w' : '-';
    s += (mode & S_IXUSR) ? 'x' : '-';
    s += (mode & S_IRGRP) ? 'r' : '-';
    s += (mode & S_IWGRP) ? 'w' : '-';
    s += (mode & S_IXGRP) ? 'x' : '-';
    s += (mode & S_IROTH) ? 'r' : '-';
    s += (mode & S_IWOTH) ? 'w' : '-';
    s += (mode & S_IXOTH) ? 'x' : '-';

    return s;
}

void viewPermissions(const string &path) {
    struct stat info;
    if (stat(path.c_str(), &info) == -1) {
        perror(("stat: " + path).c_str());
        return;
    }
    cout << permissionString(info.st_mode) << "  ";
    cout << setw(8) << info.st_size << " bytes  ";
    cout << path << endl;
}

void changePermissions(const string &path, const string &modeStr) {
    int modeInt = 0;
    try {
        modeInt = stoi(modeStr, nullptr, 8); // base 8
    } catch (...) {
        cout << "Invalid mode format. Use octal like 644 or 0755.\n";
        return;
    }
    mode_t mode = static_cast<mode_t>(modeInt);

    if (chmod(path.c_str(), mode) == 0) {
        cout << "Permissions changed successfully.\n";
        viewPermissions(path);
    } else {
        perror(("chmod: " + path).c_str());
        cout << "You may need appropriate privileges to change these permissions.\n";
    }
}

int main() {
    string command;
    while (true) {
        cout << "\nAvailable commands: list | copy | move | delete | create | search | perm | chmod | exit\n";
        cout << "Enter command: ";
        cin >> command;

        if (command == "list") {
            listFiles(".");
        } 
        else if (command == "copy") {
            string src, dest;
            cout << "Enter source file: ";
            cin >> src;
            cout << "Enter destination file: ";
            cin >> dest;
            copyFile(src, dest);
        } 
        else if (command == "move") {
            string src, dest;
            cout << "Enter source file: ";
            cin >> src;
            cout << "Enter destination file: ";
            cin >> dest;
            moveFile(src, dest);
        } 
        else if (command == "delete") {
            string filename;
            cout << "Enter file to delete: ";
            cin >> filename;
            deleteFile(filename);
        } 
        else if (command == "create") {
            string filename;
            cout << "Enter new file name: ";
            cin >> filename;
            createFile(filename);
        }
        else if (command == "search") {
            string keyword;
     	    cout << "Enter file name or keyword to search: ";
	        cin >> keyword;
	    searchFile(".", keyword);
	    }
	    else if (command == "perm") {
    	    string filename;
    	    cout << "Enter file or path to view permissions: ";
    	    cin >> filename;
    	    viewPermissions(filename);
	    }
	    else if (command == "chmod") {
    	    string filename, mode;
    	    cout << "Enter file or path to change permissions: ";
    	    cin >> filename;
    	    cout << "Enter numeric mode (e.g. 644 or 0755): ";
    	    cin >> mode;
    	    changePermissions(filename, mode);
	   }
       else if (command == "exit") {
            cout << "Exiting File Explorer...\n";
            break;
        } 
        else {
            cout << "Invalid command!\n";
        }
    }
    return 0;
}


